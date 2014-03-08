Feature: Add a file to a page
  In order to add a file to a page
  As a site administrator
  I need to be able to use the file widget

  Background:
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
      And I click "Add file"
    Then I should see "Configure new Add file"

  @api @javascript
  Scenario: Add a spotlight
    Then I should see "Allowed file types: pdf txt."
    When I fill in the following:
      | Title | Testing file title |
      | Editor              | plain_text    |
      | Text | Testing file text   |
      And I attach the file "README.txt" to "files[field_basic_file_file_und_0]"
      And I press "Upload"
    Then I should see "README.txt"
    When I press "edit-return"
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing file title"
      And I should see "Testing file text"
      And I should see the link "README.txt"
