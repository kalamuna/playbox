<?php
/**
 * @file
 * playbox_vice_president.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_vice_president_ctools_plugin_api($module = NULL, $api = NULL) {
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
function playbox_vice_president_node_info() {
  $items = array(
    'vice_president' => array(
      'name' => t('Vice President'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
