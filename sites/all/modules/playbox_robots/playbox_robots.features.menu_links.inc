<?php
/**
 * @file
 * playbox_robots.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function playbox_robots_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-right-main-menu_robots:robots
  $menu_links['menu-right-main-menu_robots:robots'] = array(
    'menu_name' => 'menu-right-main-menu',
    'link_path' => 'robots',
    'router_path' => 'robots',
    'link_title' => 'Robots',
    'options' => array(
      'attributes' => array(
        'title' => 'Link to the robots page.',
      ),
      'identifier' => 'menu-right-main-menu_robots:robots',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Robots');


  return $menu_links;
}
