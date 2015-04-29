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
   * Holds a list of temporary users created by our steps.
   *
   * @var array
   */
  protected $users = array();

  /**
   * Initializes context.
   */
  public function __construct(array $parameters = array()) {
  }

  public static function getAlias() {
    return 'test';
  }

  protected $private_path_overridden = FALSE;

  /**
   * Get the session from the parent context.
   */
  protected function getSession() {
    return $this->getMainContext()->getSession();
  }

  /**
   * @When /^I switch to the frame "([^"]*)"$/
   */
  public function iSwitchToTheFrame($frame) {
    $this->getSession()->switchToIFrame($frame);
  }

  /**
   * @When /^I switch out of all frames$/
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
   * @Then /^I should see an image in the "([^"]*)" region$/
   *
   * Attempts to determine if the image is broken or not.
   */
  public function assertValidImageRegion($region) {
    $regionObj = $this->getMainContext()->getRegion($region);
    $elements = $regionObj->findAll('css', 'img');
    if (empty($elements)) {
      throw new \Exception(sprintf('No image was not found in the "%s" region on the page %s', $region, $this->getSession()->getCurrentUrl()));
    }

    if ($src = $elements[0]->getAttribute('src')) {
      $params = array('http' => array('method' => 'HEAD'));
      $context = stream_context_create($params);
      $fp = @fopen($src, 'rb', FALSE, $context);
      if (!$fp) {
        throw new \Exception(sprintf('Unable to download <img src="%s"> in the "%s" region on the page %s', $src, $region, $this->getSession()->getCurrentUrl()));
      }

      $meta = stream_get_meta_data($fp);
      fclose($fp);
      if ($meta === FALSE) {
        throw new \Exception(sprintf('Error reading from <img src="%s"> in the "%s" region on the page %s', $src, $region, $this->getSession()->getCurrentUrl()));
      }

      $wrapper_data = $meta['wrapper_data'];
      $found = FALSE;
      if (is_array($wrapper_data)) {
        foreach ($wrapper_data as $header) {
          if (substr(strtolower($header), 0, 19) == 'content-type: image') {
            $found = TRUE;
          }
        }
      }

      if (!$found) {
        throw new \Exception(sprintf('Not a valid image <img src="%s"> in the "%s" region on the page %s', $src, $region, $this->getSession()->getCurrentUrl()));
      }
    }
    else {
      throw new \Exception(sprintf('No image had no src="..." attribute in the "%s" region on the page %s', $region, $this->getSession()->getCurrentUrl()));
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
   * @BeforeScenario @api&&@drupal_private_files
   *
   * Configure a private files path if one isn't already configured.
   */
  public function configurePrivateFiles($event) {
    $file_private_path = variable_get('file_private_path', '');
    if (empty($file_private_path)) {
      $file_public_path = variable_get('file_public_path', conf_path() . '/files');
      if (empty($file_public_path)) {
        throw new \Exception('Files must be configured for @drupal_private_files tests to work!');
      }

      // Set flag for later cleanup.
      $this->private_path_overridden = TRUE;

      // Create and setup the private path.
      $file_private_path = $file_public_path . '/' . 'private';
      variable_set('file_private_path', $file_private_path);
    }
  }

  /**
   * @AfterScenario @api&&@drupal_private_files
   *
   * Clean up our temporary private files path.
   */
  public function cleanupPrivateFiles($event) {
    if ($this->private_path_overridden) {
      variable_del('file_private_path');
    }
  }

  /**
   * @AfterScenario
   *
   * Clean up users that were created during testing
   */
  public function removeUsers() {
    if(!empty($this->users)){
      foreach ($this->users as $user) {
        $account = user_load_by_name($user->name);
        user_delete($account->uid);
      }
      $this->users = array();
    }
  }

  /**
   * @AfterStep @javascript
   *
   * After every step in a @javascript scenario, we want to wait for AJAX
   * loading to finish.
   */
  public function afterStep(StepEvent $event) {
    $type = $event->getDefinition()->getType();
    $text = $event->getStep()->getText();
    if (($type === 'When' || preg_match('/viewing|visit|reload/', $text)) && $event->getResult() === 0) {
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
   * @Given /^Panopoly admin "Use Advanced Panel Plugins" is disabled$/
   *
   * Disable the "Use Advanced Panel Panes" option.
   */
  public function disablePanopolyAdminAdvanacedPanelPlugins() {
    variable_set('panopoly_admin_advanced_plugins', FALSE);
  }

  /**
   * @Given /^Panopoly admin "Use Advanced Panel Plugins" is enabled$/
   *
   * Enable the "Use Advanced Panel Panes" option.
   */
  public function enablePanopolyAdminAdvanacedPanelPlugins() {
    variable_set('panopoly_admin_advanced_plugins', TRUE);
  }

  /**
   * @When /^(?:|I )wait(?:| for) (\d+) seconds?$/
   *
   * Wait for the given number of seconds. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForSeconds($arg1) {
    sleep($arg1);
  }

  /**
   * @When /^(?:|I )wait for AJAX loading to finish$/
   *
   * Wait for the jQuery AJAX loading to finish. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForAJAX() {
    $this->getSession()->wait(5000, 'typeof jQuery !== "undefined" && jQuery.active === 0');
  }

 /**
   * @When /^(?:|I )wait for live preview to finish$/
   *
   * Wait until the live preview to finish.
   */
  public function waitForLivePreview() {
    $this->getSession()->wait(5000, 'typeof jQuery !== "undefined" && jQuery.active === 0 && jQuery("#panopoly-form-widget-preview").length > 0 && !jQuery("#panopoly-form-widget-preview").hasClass("panopoly-magic-loading")');
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
   * @Given /^I am viewing a landing page$/
   */
  public function iAmViewingALandingPage() {
    $random = new Random();
    $name = $random->name(8);
    $this->getMainContext()->createNode('panopoly_test_landing_page', $name);
  }

  /**
   * @Then /^the "([^"]*)" radio button should be set to "([^"]*)"$/
   *
   * @link: https://www.drupal.org/node/1891584 @endlink
   */
  public function theRadioButtonShouldBeSetTo($identifier, $option) {
    $page = $this->getSession()->getPage();
    $div = $page->find('xpath', "//div[contains(., '$identifier') and @class[contains(.,'form-type-radio')]]");
    if ($div) {
      $radios = $div->find('xpath', "//input[@type='radio']");
      if ($radios) {
        $checkedRadio = $div->find('xpath', "//input[@type='radio' and @checked='checked']/following-sibling::label[contains(text(), '$option')] ");
        if (!$checkedRadio) {
          throw new \Exception(sprintf('We found the radio buttons for "%s", but "%s" was not selected.', $identifier, $option));
        }
      } elseif (!$radios) {
        throw new \Exception(sprintf('We found "%s", but it did not contain any radio buttons".', $identifier));
      }
    } elseif (!$div) {
      throw new \Exception(sprintf('We couldn\'nt find "%s" on the page', $identifier));
    } else {
      throw new \Exception('General exception from '.__FUNCTION__);
    }
  }

  /**
   * @Then /^I should see the radio button "(?P<label>[^"]*)" with the id "(?P<id>[^"]*)"$/
   * @Then /^I should see the radio button "(?P<label>[^"]*)"$/
   */
  public function assertSeeRadioById($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array('radio', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($radiobutton === NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
    }
    if ($id) {
      $value = $radiobutton->getAttribute('value');
      $labelonpage = $radiobutton->getParent()->getText();
      if ($label != $labelonpage) {
        throw new \Exception(sprintf("Button with id '%s' has label '%s' instead of '%s' on the page %s", $id, $labelonpage, $label, $this->getSession()->getCurrentUrl()));
      }
    }
  }

  /**
   * @Then /^I should not see the radio button "(?P<label>[^"]*)" with the id "(?P<id>[^"]*)"$/
   * @Then /^I should not see the radio button "(?P<label>[^"]*)"$/
   */
  public function assertNotSeeRadioById($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array('radio', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($radiobutton !== NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then /^the "([^"]*)" select should be set to "([^"]*)"$/
   */
  public function theSelectShouldBeSetTo($identifier, $value) {
    $select = $this->getSession()->getPage()->findField($identifier);
    if (empty($select)) {
      throw new \Exception(sprintf('We couldn\'nt find "%s" on the page', $identifier));
    }
    $options = $select->findAll('xpath', '//option[@selected="selected"]');
    if (empty($select)) {
      throw new \Exception(sprintf('The select "%s" doesn\'t have any options selected', $identifier));
    }

    $found = FALSE;
    foreach ($options as $option) {
      if ($option->getText() === $value) {
        $found = TRUE;
        break;
      }
    }
    if (!$found) {
      throw new \Exception(sprintf('The select "%s" doesn\'t have the option "%s" selected', $identifier, $value));
    }
  }

  /**
   * @Given /^the dblog is empty$/
   */
  public function clearDblog() {
    db_delete('watchdog')->execute();
  }

}
