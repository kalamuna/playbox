<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Event\ScenarioEvent,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;
use Drupal\Component\Utility\Random;

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */
class PanopolyContext extends DrupalContext
{

  /**
   * Keep track of files added by tests so they can be cleaned up.
   *
   * @var array
   */
  public $files = array();

  /**
   * Keep track of Fieldable Panels Panes added by tests so they can be cleaned up.
   *
   * @var array
   */
  public $fpps = array();

  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters) {
    // Initialize your context here

  }

//
// Place your definition and hook methods here:
//
//    /**
//     * @Given /^I have done something with "([^"]*)"$/
//     */
//    public function iHaveDoneSomethingWith($argument)
//    {
//        doSomethingWith($argument);
//    }
//

  /**
   * Override MinkContext::fixStepArgument().
   *
   * Make it possible to use [random].
   * If you want to use the previous random value [random:1].
   * Also, allow newlines in arguments.
   */
  public function fixStepArgument($argument) {
    $argument = str_replace('\\"', '"', $argument);

    $argument = str_replace('\n', "\n", $argument);

    // Token replace the argument.
    static $random = array();
    for ($start = 0; ($start = strpos($argument, '[', $start)) !== FALSE; ) {
      $end = strpos($argument, ']', $start);
      if ($end === FALSE) {
        break;
      }
      $random_generator = new Random;
      $name = substr($argument, $start + 1, $end - $start - 1);
      if ($name == 'random') {
        $this->vars[$name] = $random_generator->name(8);
        $random[] = $this->vars[$name];
      }
      // In order to test previous random values stored in the form,
      // suppport random:n, where n is the number or random's ago
      // to use, i.e., random:1 is the previous random value.
      elseif (substr($name, 0, 7) == 'random:') {
        $num = substr($name, 7);
        if (is_numeric($num) && $num <= count($random)) {
          $this->vars[$name] = $random[count($random) - $num];
        }
      }
      if (isset($this->vars[$name])) {
        $argument = substr_replace($argument, $this->vars[$name], $start, $end - $start + 1);
        $start += strlen($this->vars[$name]);
      }
      else {
        $start = $end + 1;
      }
    }
    return $argument;
  }

  /**
   * @Given /^the managed file "([^"]*)"$/
   *
   * This function copies the provided file into the site files directory,
   * creates a file object with the URI, and passes that object to a file
   * creation function to create the entity.
   * The function has to be here for now, as it needs some Mink functions.
   *
   * @todo See if it can be done without Mink functions?
   * @todo Allow creating private files.
   * @todo Add before and after event dispatchers.
   * @todo Add ability to create multiple files at once using Table.
   */
  public function createFile($filename, $public = TRUE) {
    // Get location of source file.
    if ($this->getMinkParameter('files_path')) {
      $source_path = rtrim(realpath($this->getMinkParameter('files_path'))) . DIRECTORY_SEPARATOR . $filename;
      if (!is_file($source_path)) {
        throw new \Exception(sprintf("Cannot find the file at '%s'", $source_path));
      }
    } else {
      throw new \Exception("files_path not set");
    }

    $prefix = $public ? 'public://' : 'private://';
    $uri = $prefix . $filename;

    $this->fileCreate($source_path, $uri);
  }

  /**
   * Create a managed Drupal file.
   *
   * @param $source_path
   *   A file object passed in with the URI already set.
   * @param $destination
   *   (Optional) The desired URI where the file will be uploaded.
   *
   * @return
   *   A single Drupal file object.
   */
  public function fileCreate($source_path, $destination = NULL) {
    $data = file_get_contents($source_path);

    // Before working with files, we need to change our current directory to
    // DRUPAL_ROOT so that the relative paths that define the stream wrappers
    // (like public:// or temporary://) actually work.
    $cwd = getcwd();
    chdir(DRUPAL_ROOT);

    if ($file = file_save_data($data, $destination)) {
      $this->files[] = $file;
    }

    // Then change back.
    chdir($cwd);

    return $file;
  }
  /**
   * Get a list of UIDs.
   *
   * @return
   *   An array of numeric UIDs of users created by Given... steps during this scenario.
   */
  public function getUIDs() {
    $uids = array();
    foreach ($this->users as $user) {
      $uids[] = $user->uid;
    }
    return $uids;
  }
  /**
   * Cleans up files after every scenario.
   *
   * @AfterScenario @api
   */
  public function cleanUpFiles($event) {
    // Get UIDs of users created during this scenario.
    $uids = $this->getUIDs();
    if (!empty($uids)) {

      // Add any files created by test users to the $files variable.
      $file_ids = db_query('SELECT fid FROM {file_managed} WHERE uid IN (:uids)', array(':uids' => $uids))->fetchAll();
      if (!empty($file_ids)) {
        // The file_delete() function expects an object.
        foreach ($file_ids as $fid) {
          $file = file_load($fid->fid);
          $this->files[] = $file;
        }
      }
      // Find any FPPs created by the test users.
      // First, get a list of FPPs with their first revision VID.
      $fpp_vids = db_query('SELECT min(vid) AS vid FROM {fieldable_panels_panes_revision} GROUP BY fpid')->fetchAll();
      $vids = array();
      $fpids = array();
      if (!empty($fpp_vids)) {
        foreach ($fpp_vids as $vid) {
          $vids[] = $vid->vid;
        }
        // Then, check whether that first revision was created by a current test user.
        $fpp_fpids = db_query('SELECT fpid FROM {fieldable_panels_panes_revision} WHERE vid IN (:vids) AND uid IN (:uids)', array(':uids' => $uids, ':vids' => $vids))->fetchAll();
        if (!empty($fpp_fpids)) {
          foreach ($fpp_fpids as $fpid) {
            $fpids[] = $fpid->fpid;
          }
        }
      }
      // Add FPPs created by users to the $fpps variable.
      $this->fpps = array_unique(array_merge($this->fpps, $fpids));
    }

    // Delete any fieldable panels panes that were created by test users or a Given step.
    if (!empty($this->fpps)) {
      foreach ($this->fpps as $fpp) {
        $this->fppDelete($fpp);
      }
    }

    // Delete any files that were created by test users or our Given step.
    if (!empty($this->files)) {
      foreach ($this->files as $file) {
        $this->fileDelete($file);
      }
    }

    // Reset the arrays to empty after deletion.
    $this->files = array();
    $this->fpps = array();
  }

  /**
   * Delete a managed Drupal file.
   *
   * @param $file
   *   A file object to delete.
   */
  public function fileDelete($file) {
    // Figure out if there's usage in any nodes.
    $fid = $file->fid;
    $node_usage = db_query('SELECT id AS nid FROM {file_usage} WHERE fid = (:fid) AND module = (:module) and type = (:node)', array(':fid' => $fid, ':module' => 'media', ':node' => 'node'))->fetchAll();
    // If there is, it should be safe to unregister it, because we already know the file is owned by a current test user.
    if (!empty($node_usage)) {
      foreach ($node_usage as $nid) {
        file_usage_delete($file, 'media', 'node', $nid->nid);
      }
    }
    // See PanopolyContext::fileCreate() for information on why we do this.
    $cwd = getcwd();
    chdir(DRUPAL_ROOT);
    file_delete($file);
    chdir($cwd);
  }

  /**
   * Delete a Fieldable Panels Pane.
   *
   * @param $fpp
   *   A fieldable panel pane ID to delete.
   */
  public function fppDelete($fpp) {
    fieldable_panels_panes_delete($fpp);
  }
}
