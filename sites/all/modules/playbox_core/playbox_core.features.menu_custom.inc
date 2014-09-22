<?php
/**
 * @file
 * playbox_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function playbox_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-left-main-menu.
  $menus['menu-left-main-menu'] = array(
    'menu_name' => 'menu-left-main-menu',
    'title' => 'Left Main Menu',
    'description' => 'This shit goes to the left of the centerpiece logo.',
  );
  // Exported menu: menu-right-main-menu.
  $menus['menu-right-main-menu'] = array(
    'menu_name' => 'menu-right-main-menu',
    'title' => 'Right Main Menu',
    'description' => 'This is the shit to the right of the centerpiece logo.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Left Main Menu');
  t('Right Main Menu');
  t('This is the shit to the right of the centerpiece logo.');
  t('This shit goes to the left of the centerpiece logo.');


  return $menus;
}
