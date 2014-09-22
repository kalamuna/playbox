<?php
/**
 * @file
 * playbox_battles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_battles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function playbox_battles_node_info() {
  $items = array(
    'playbox_battle' => array(
      'name' => t('Battles'),
      'base' => 'node_content',
      'description' => t('This is the MAIN EVENT. Battles of bots and prezzzzz\'z.'),
      'has_title' => '1',
      'title_label' => t('Battle Title'),
      'help' => '',
    ),
  );
  return $items;
}
