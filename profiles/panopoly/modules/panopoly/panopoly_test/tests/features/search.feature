Feature: Search
  In order to find content on the site
  As an anonymous user
  I should be able to find content using the site search

  Background:
    Given I am on the homepage

  @panopoly_search
  Scenario: Trying an empty search should yield a message
    When I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "Enter your keywords"

  @panopoly_search
  Scenario: Trying a search with no results
    When I fill in "TkyXNk9NG2U7FjqtMvNvHXpv2xnfVv7Q" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "0 items matched TkyXNk9NG2U7FjqtMvNvHXpv2xnfVv7Q"
      And I should see "Your search did not return any results."

  @api @panopoly_search
  Scenario: Performing a search with results
    Given "panopoly_test_page" nodes:
      | title           | body        | created            | status |
      | fxabR86L Page 1 | Test page 1 | 01/01/2001 11:00am |      1 |
      | fxabR86L Page 2 | Test page 2 | 01/02/2001 11:00am |      1 |
      | X9A1YXwc Page 3 | Test page 3 | 01/03/2001 11:00am |      1 |
      And I run drush "cron"
    When I fill in "fxabR86L" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "2 items matched fxabR86L"
      And I should see "Filter by Type"
      And I should not see "X9A1YXwc"
