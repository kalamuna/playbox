<?php
/**
 * @file
 * playbox_battles.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function playbox_battles_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-left-main-menu_battles:battles
  $menu_links['menu-left-main-menu_battles:battles'] = array(
    'menu_name' => 'menu-left-main-menu',
    'link_path' => 'battles',
    'router_path' => 'battles',
    'link_title' => 'Battles',
    'options' => array(
      'identifier' => 'menu-left-main-menu_battles:battles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Battles');


  return $menu_links;
}
