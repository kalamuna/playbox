<?php
/**
 * @file
 * panopoly_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panopoly_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function panopoly_test_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function panopoly_test_node_info() {
  $items = array(
    'panopoly_test_page' => array(
      'name' => t('Test Page'),
      'base' => 'node_content',
      'description' => t('Used for the automated tests.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
