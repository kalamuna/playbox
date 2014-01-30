Feature: Add content list widget
  In order to create a list of certain content
  As a site administrator
  I need to be able to add a list with the content I choose
 
  @api @javascript
  Scenario: Add a content list
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
    When I visit "/node/add/panopoly-page"
      And I fill in the following:
        | Title               | Testing title |
        | Editor              | plain_text    |
        | body[und][0][value] | Testing body  |
      And I press "Publish"
    Then the "h1" element should contain "Testing title"
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content list"
    Then I should see "Configure new Add content list"
      When I fill in the following:
       | widget_title    | Content Page List Asc 1 |
       | items_per_page  | 1                       |
#      | Display Type    | Fields                  |
    When I select "Content Page" from "exposed[type]"
      And I select "Asc" from "exposed[sort_order]"
      And I select "Title" from "exposed[sort_by]"
      And I press "edit-return"
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should see "Content Page List Asc 1"
    Then I should see "March 20, 2012"
      And I should see "Posted by admin"
    When I customize this page with the Panels IPE
     And I click "Settings" in the "Bryant Sidebar" region
    Then I should see "Configure Add content list"
      And the "exposed[sort_by]" field should contain "Title"
