<?php
/**
 * @file
 * Provide Behat step-definitions for Fieldable Panels Panes.
 *
 * @todo This should become fieldable_panels_panes.behat.inc in the Panels module!
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Behat\Behat\Context\BehatContext;

class FieldablePanelsPanesSubContext extends BehatContext implements DrupalSubContextInterface {
  /**
   * Initializes context.
   */
  public function __construct(array $parameters = array()) {
  }

  public static function getAlias() {
    return 'fieldable_panels_panes';
  }

  /**
   * Get the session from the parent context.
   */
  protected function getSession() {
    return $this->getMainContext()->getSession();
  }

  /**
   * Get a Fieldable Panels Pane by admin title.
   *
   * @param string $admin_title
   *   The admin title of the FPP to retrieve.
   *
   * @return object
   *   The Fieldable Panels Pane entity object.
   */
  protected function getFPPByAdminTitle($admin_title) {
    $fpps = fieldable_panels_panes_load_multiple(array(), array('admin_title' => $admin_title));
    if (empty($fpps)) {
      throw new \Exception(sprintf('Fieldable panels pane "%s" was not found', $admin_title));
    }
    return reset($fpps);
  }

  /**
   * Get the list of revisions for a Fieldable Panels Pane.
   *
   * @param int $fpid
   *   The ID for the Fieldable Panels Pane.
   */
  protected function getFPPRevisions($fpid) {
    return db_query("SELECT * FROM {fieldable_panels_panes_revision} WHERE fpid = :fpid", array(':fpid' => $fpid))->fetchAll();
  }

  /**
   * @Then /^fieldable panels pane "([^"]*)" should have (\d+) revisions?$/
   *
   * @todo: Can we only allow this to work with @api tests?
   */
  public function assertRevisionCount($admin_title, $expected_count) {
    $fpp = $this->getFPPByAdminTitle($admin_title);
    $revisions = $this->getFPPRevisions($fpp->fpid);

    $actual_count = count($revisions);
    if ($actual_count != $expected_count) {
      throw new \Exception(sprintf('Fieldable panels pane "%s" has %s revisions (rather than the expected %s)', $admin_title, $actual_count, $expected_count));
    }
  }

  /**
   * @Given /^I am viewing revision (\d+) of fieldable panels pane "([^"]*)"$/
   *
   * @todo: Can we only allow this to work with @api tests?
   */
  public function iAmViewingFPPRevision($revision_number, $admin_title) {
    $fpp = $this->getFPPByAdminTitle($admin_title);
    $revisions = $this->getFPPRevisions($fpp->fpid);

    $vid = $revisions[$revision_number - 1]->vid;
    $path = "admin/structure/fieldable-panels-panes/view/{$fpp->fpid}/revision/$vid";

    $this->getSession()->visit($this->getMainContext()->locatePath($path));
  }
}
