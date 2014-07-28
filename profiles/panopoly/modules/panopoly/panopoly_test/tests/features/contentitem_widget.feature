Feature: Add content item
  In order to put in a particular content item on a page
  As a site administrator
  I need to be able to choose which content item
 
  @api @javascript @panopoly_widgets
  Scenario: Add content item
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page" nodes:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I fill in the following:
      | exposed[title]        | Test Page 1 |
    When I select "Test Page" from "exposed[type]"
      And I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Test Page 1"
      And I should see "January 1, 2001"
      And I should see "Posted by Anonymous"

