<?php
/**
 * @file
 * Provide Behat step-definitions for generic Panopoly tests.
 *
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Behat\Behat\Context\BehatContext;
use Drupal\Component\Utility\Random;
use Behat\Behat\Event\StepEvent;

class TestSubContext extends BehatContext implements DrupalSubContextInterface {
  /**
   * Initializes context.
   */
  public function __construct(array $parameters = array()) {
  }

  public static function getAlias() {
    return 'test';
  }

  protected $bootstrapped = FALSE;
  protected $landing_pages = array();

  /**
   * Get the session from the parent context.
   */
  protected function getSession() {
    return $this->getMainContext()->getSession();
  }

  /**
   * @Given /^I switch to the frame "([^"]*)"$/
   */
  public function iSwitchToTheFrame($frame) {
    $this->getSession()->switchToIFrame($frame);
  }

  /**
   * @Given /^I switch out of all frames$/
   */
  public function iSwitchOutOfAllFrames() {
    $this->getSession()->switchToIFrame();
  }

  /**
   * @Then /^I should see the "([^"]*)" button$/
   */
  public function assertButton($label) {
    $page = $this->getSession()->getPage();
    $results = $page->findAll('css', "input[type=submit],input[type=button],button");
    if (!empty($results)) {
      foreach ($results as $result) {
        if ($result->getTagName() == 'input' && $result->getAttribute('value') == $label) {
          return;
        }
        elseif ($result->getText() == $label) {
          return;
        }
      }
    }
    throw new \Exception(sprintf('The "%s" button was not found on the page %s', $label, $region, $this->getSession()->getCurrentUrl()));
  }

  /**
   * @Then /^I should see the "([^"]*)" button in the "([^"]*)" region$/
   */
  public function assertRegionButton($label, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $results = $regionObj->findAll('css', "input[type=submit],input[type=button],button");
    if (!empty($results)) {
      foreach ($results as $result) {
        if ($result->getTagName() == 'input' && $result->getAttribute('value') == $label) {
          return;
        }
        elseif ($result->getText() == $label) {
          return;
        }
      }
    }
    throw new \Exception(sprintf('The "%s" button was not found in the "%s" region on the page %s', $label, $region, $this->getSession()->getCurrentUrl()));
  }

  /**
   * @Then /^I should see the "([^"]*)" element in the "([^"]*)" region$/
   */
  public function assertRegionElement($tag, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $elements = $regionObj->findAll('css', $tag);
    if (!empty($elements)) {
      return;
    }
    throw new \Exception(sprintf('The element "%s" was not found in the "%s" region on the page %s', $tag, $region, $this->getSession()->getCurrentUrl()));
  }

  /**
   * @Then /^I should not see the "([^"]*)" element in the "([^"]*)" region$/
   */
  public function assertNotRegionElement($tag, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $result = $regionObj->findAll('css', $tag);
    if (!empty($result)) {
      throw new \Exception(sprintf('The element "%s" was found in the "%s" region on the page %s', $tag, $region, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should see "([^"]*)" in the "([^"]*)" element in the "([^"]*)" region$/
   */
  public function assertRegionElementText($text, $tag, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $results = $regionObj->findAll('css', $tag);
    if (!empty($results)) {
      foreach ($results as $result) {
        if ($result->getText() == $text) {
          return;
        }
      }
    }
    throw new \Exception(sprintf('The text "%s" was not found in the "%s" element in the "%s" region on the page %s', $text, $tag, $region, $this->getSession()->getCurrentUrl()));
  }

  /**
   * @Then /^I should see "([^"]*)" in the "([^"]*)" element with the "([^"]*)" CSS property set to "([^"]*)" in the "([^"]*)" region$/
   */
  public function assertRegionElementTextCss($text, $tag, $property, $value, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $elements = $regionObj->findAll('css', $tag);
    if (empty($elements)) {
      throw new \Exception(sprintf('The element "%s" was not found in the "%s" region on the page %s', $tag, $region, $this->getSession()->getCurrentUrl()));
    }

    $found = FALSE;
    foreach ($elements as $element) {
      if ($element->getText() == $text) {
        $found = TRUE;
        break;
      }
    }
    if (!$found) {
      throw new \Exception(sprintf('The text "%s" was not found in the "%s" element in the "%s" region on the page %s', $text, $tag, $region, $this->getSession()->getCurrentUrl()));
    }

    if (!empty($property)) {
      $style = $element->getAttribute('style');
      if (strpos($style, "$property: $value") === FALSE) {
        throw new \Exception(sprintf('The "%s" property does not equal "%s" on the element "%s" in the "%s" region on the page %s', $property, $value, $tag, $region, $this->getSession()->getCurrentUrl()));
      }
    }
  }

  /**
   * @Then /^I should see "([^"]*)" in the "([^"]*)" element with the "([^"]*)" attribute set to "([^"]*)" in the "([^"]*)" region$/
   */
  public function assertRegionElementTextAttribute($text, $tag, $attribute, $value, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $elements = $regionObj->findAll('css', $tag);
    if (empty($elements)) {
      throw new \Exception(sprintf('The element "%s" was not found in the "%s" region on the page %s', $tag, $region, $this->getSession()->getCurrentUrl()));
    }

    $found = FALSE;
    foreach ($elements as $element) {
      if ($element->getText() == $text) {
        $found = TRUE;
        break;
      }
    }
    if (!$found) {
      throw new \Exception(sprintf('The text "%s" was not found in the "%s" element in the "%s" region on the page %s', $text, $tag, $region, $this->getSession()->getCurrentUrl()));
    }

    if (!empty($attribute)) {
      $attr = $element->getAttribute($attribute);
      if (empty($attr)) {
        throw new \Exception(sprintf('The "%s" attribute is not present on the element "%s" in the "%s" region on the page %s', $attribute, $tag, $region, $this->getSession()->getCurrentUrl()));
      }
      if (strpos($attr, "$value") === FALSE) {
        throw new \Exception(sprintf('The "%s" attribute does not equal "%s" on the element "%s" in the "%s" region on the page %s', $attribute, $value, $tag, $region, $this->getSession()->getCurrentUrl()));
      }
    }
  }

  /**
   * @Then /^I should not see "([^"]*)" in the "([^"]*)" element in the "([^"]*)" region$/
   */
  public function assertNotRegionElementText($text, $tag, $region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $results = $regionObj->findAll('css', $tag);
    if (!empty($results)) {
      foreach ($results as $result) {
        if ($result->getText() == $text) {
          throw new \Exception(sprintf('The text "%s" was found in the "%s" element in the "%s" region on the page %s', $text, $tag, $region, $this->getSession()->getCurrentUrl()));
        }
      }
    }
  }

  /**
   * Checks, that the region contains text matching specified pattern.
   *
   * @Then /^(?:|I )should see text matching "(?P<pattern>(?:[^"]|\\")*)" in the "(?P<region>[^"]*)"(?:| region)$/
   */
  public function assertRegionMatchesText($pattern, $region)
  {
    $regionObj = $this->getMainContext()->getRegion($region);

    // Find the text within the region
    $regionText = $regionObj->getText();
    if (!preg_match($pattern, $regionText)) {
      throw new \Exception(sprintf("No text matching '%s' was found in the region '%s' on the page %s", $pattern, $region, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * Checks, that the region does not contain text matching specified pattern.
   *
   * @Then /^(?:|I )should not see text matching "(?P<pattern>(?:[^"]|\\")*)" in the "(?P<region>[^"]*)"(?:| region)$/
   */
  public function assertNotRegionMatchesText($pattern, $region)
  {
    $regionObj = $this->getMainContext()->getRegion($region);

    // Find the text within the region
    $regionText = $regionObj->getText();
    if (preg_match($pattern, $regionText)) {
      throw new \Exception(sprintf("Text matching '%s' was found in the region '%s' on the page %s", $pattern, $region, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should see the image alt "(?P<alt>(?:[^"]|\\")*)" in the "(?P<region>[^"]*)"(?:| region)$/
   */
  public function assertAltRegion($alt, $region) {
    $alt = $this->getMainContext()->fixStepArgument($alt);
    $regionObj = $this->getMainContext()->getRegion($region);
    $element = $regionObj->find('css', 'img');
    $tmp = $element->getAttribute('alt');
    if ($alt == $tmp) {
      $result = $alt;
    }
    if (empty($result)) {
      throw new \Exception(sprintf('No alt text matching "%s" in the "%s" region on the page %s', $alt, $region, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @BeforeScenario @api
   *
   * Bootstrap Drupal so that all Drupal API functions work.
   */
  public function bootstrapDrupal($event) {
    if (!$this->bootstrapped) {
      $drupal = $this->getMainContext()->getDriver('drupal');

      // We are experiencing a weird issue where the CTools plugin cache gets
      // corrupted and none of our Panels pages work because their layout
      // plugins can't be found. It appears that clearing the cache, and then
      // bootstrapping Drupal again will fix it! I suspect the CTools plugin
      // cache is being built too early, ie. before we change to the Drupal
      // directory - but I haven't been able to confirm that.
      $drupal->clearCache();
      $drupal->bootstrap();

      // We occasionally get errors about not finding the ctools_get_export_ui()
      // function, so we force it to be loaded. No idea what's causing this.
      ctools_include('export-ui');

      $this->bootstrapped = TRUE;
    }
  }

  /**
   * @AfterStep @javascript
   *
   * After every step in a @javascript scenario, we want to wait for AJAX
   * loading to finish.
   */
  public function afterStep(StepEvent $event) {
    if ($event->getResult() === 0) {
      $this->iWaitForAJAX();
    }
  }

  /**
   * @Given /^Panopoly magic live previews are disabled$/
   *
   * Disable live previews via Panopoly Magic.
   */
  public function disablePanopolyMagicLivePreview() {
    //$this->getDriver('drush')->vset('panopoly_magic_live_preview 0 --yes');
    variable_set('panopoly_magic_live_preview', 0);
  }

  /**
   * @Given /^Panopoly magic live previews are automatic$/
   *
   * Enable live previews via Panopoly Magic.
   */
  public function enableAutomaticPanopolyMagicLivePreview() {
    //$this->getDriver('drush')->vset('panopoly_magic_live_preview 1 --yes');
    variable_set('panopoly_magic_live_preview', 1);
  }

  /**
   * @Given /^Panopoly magic live previews are manual$/
   *
   * Enable live previews via Panopoly Magic.
   */
  public function enableManualPanopolyMagicLivePreview() {
    //$this->getDriver('drush')->vset('panopoly_magic_live_preview 2 --yes');
    variable_set('panopoly_magic_live_preview', 2);
  }

  /**
   * @Given /^(?:|I )wait(?:| for) (\d+) seconds?$/
   *
   * Wait for the given number of seconds. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForSeconds($arg1) {
    sleep($arg1);
  }

  /**
   * @Given /^(?:|I )wait for AJAX loading to finish$/
   *
   * Wait for the jQuery AJAX loading to finish. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForAJAX() {
    $this->getSession()->wait(5000, 'typeof jQuery !== "undefined" && jQuery.active === 0');
  }

  /**
   * @Given /^I log in with the One Time Login Url$/
   */
  public function iLogInWithTheOneTimeLoginUrl() {
    if ($this->getMainContext()->loggedIn()) {
      $this->getMainContext()->logOut();
    }

    $random = new Random;

    // Create user (and project)
    $user = (object) array(
      'name' => $random->name(8),
      'pass' => $random->name(16),
      'role' => 'authenticated user',
    );
    $user->mail = "{$user->name}@example.com";

    // Create a new user.
    $this->getMainContext()->getDriver()->userCreate($user);

    $this->users[$user->name] = $this->user = $user;

    $base_url = rtrim($this->getMainContext()->locatePath('/'), '/');
    $login_link = $this->getMainContext()->getDriver('drush')->drush('uli', array(
      "'$user->name'",
      '--browser=0',
      "--uri=${base_url}",
    ));
    // Trim EOL characters. Required or else visiting the link won't work.
    $login_link = trim($login_link);
    $login_link = str_replace("/login", '', $login_link);
    $this->getSession()->visit($this->getMainContext()->locatePath($login_link));
    return TRUE;
  }

  /**
   * Create a new Landing Page.
   *
   * @param string $name
   *   The internal machine name for the new Page.
   * @param string $path
   *   The path for the new Page.
   * @param string $title
   *   The title for the new Page.
   */
  protected function createPage($name, $path, $title) {
    $page_task = page_manager_get_task('page');

    $subtask = page_manager_page_new();
    $subtask->name = $name;
    $subtask->path = $path;
    $subtask->admin_title = $title;
    $subtask->admin_description = '';
    $subtask->menu = array(
      'type' => 'none',
    );

    $display = new stdClass();
    $display->layout = 'boxton';
    $display->title = $title;
    $display->panels = array();
    $display->content = array();

    $plugin = page_manager_get_task_handler('panel_context');
    $handler = page_manager_new_task_handler($plugin);
    $handler->conf['title'] = t('Landing page');
    $handler->conf['display'] = $display;
    $handler->conf['pipeline'] = 'ipe';

    // Assemble a new $page cache and assign it to our page subtask and task
    // handler.
    $page = new stdClass();
    page_manager_page_new_page_cache($subtask, $page);
    page_manager_handler_add_to_page($page, $handler);
    page_manager_save_page_cache($page);

    // Mark this page for deletion at the end of the scenario.
    $this->landing_pages[] = $name;
  }

  /**
   * @AfterScenario @api
   *
   * Delete landing pages after a Scenario has finished.
   */
  public function cleanupPages() {
    foreach ($this->landing_pages as $name) {
      if ($page = page_manager_page_load($name)) {
        page_manager_page_delete($page);
      }
    }
    $this->landing_pages = array();
  }

  /**
   * @Given /^I am viewing a landing page$/
   */
  public function iAmViewingALandingPage() {
    $random = new Random();
    $name = $random->name(8);
    $path = $random->name(8);

    $this->createPage($name, $path, 'Testing Landing Page');

    $this->getSession()->visit($this->getMainContext()->locatePath($path));
  }
}
