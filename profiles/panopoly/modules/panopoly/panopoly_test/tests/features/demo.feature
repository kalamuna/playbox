Feature: Demo content
  In order to test out the site
  As a site owner
  I need to view demo content

  @panopoly_demo
  Scenario: Homepage
    Given I am an anonymous user
    When I visit "/demo"
    Then the "h1" element should contain "Homepage Demo"
