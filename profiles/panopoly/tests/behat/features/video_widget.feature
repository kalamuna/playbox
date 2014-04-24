Feature: Add video widget
  In order to add a video
  As a site administrator
  I need to be able to use the video widget

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
      And I click "Add new pane" in the "Bryant Content" region
      And I click "Add video"
    Then I should see "Configure new Add video"

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome
  Scenario: Add a YouTube video
    When I fill in "Testing video" for "edit-title"
    When I click "Select"
      And I switch to the frame "mediaBrowser"
    Then I should see "Supported providers"
      And I should see "YouTube"
    When I fill in "File URL or media resource" with "https://www.youtube.com/watch?v=1TV0q4Sdxlc"
      And I press "Submit"
      And I wait 2 seconds
    Then I should see "Edit"
      And I should see "Remove"
    When I press "edit-return"
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing video"
    Then I should see the "iframe.media-youtube-player" element in the "Bryant Content" region

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome
  Scenario: Add a Vimeo video
    When I fill in "Testing video" for "edit-title"
    When I click "Select"
      And I switch to the frame "mediaBrowser"
    Then I should see "Supported providers"
      And I should see "YouTube"
    When I fill in "File URL or media resource" with "http://vimeo.com/59482983"
      And I press "Submit"
      And I wait 2 seconds
    Then I should see "Edit"
      And I should see "Remove"
    When I press "edit-return"
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing video"
    Then I should see the "iframe.media-vimeo-player" element in the "Bryant Content" region
