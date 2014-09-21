<?php
/**
 * @file
 * playbox_presidents.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function playbox_presidents_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-left-main-menu_presidents:presidents
  $menu_links['menu-left-main-menu_presidents:presidents'] = array(
    'menu_name' => 'menu-left-main-menu',
    'link_path' => 'presidents',
    'router_path' => 'presidents',
    'link_title' => 'Presidents',
    'options' => array(
      'attributes' => array(
        'title' => 'This is the link to the presidents page.',
      ),
      'identifier' => 'menu-left-main-menu_presidents:presidents',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Presidents');


  return $menu_links;
}
