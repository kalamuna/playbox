<?php
/**
 * @file
 * playbox_emergency.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_emergency_ctools_plugin_api($module = NULL, $api = NULL) {
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
function playbox_emergency_node_info() {
  $items = array(
    'playbox_vice_president' => array(
      'name' => t('Vice Presidents'),
      'base' => 'node_content',
      'description' => t('This contains the data model for a vice president. '),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
