<?php
/**
 * @file
 * playbox_robots.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_robots_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_views_api().
 */
function playbox_robots_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function playbox_robots_node_info() {
  $items = array(
    'playbox_robot' => array(
      'name' => t('Robots'),
      'base' => 'node_content',
      'description' => t('This is the data model for our would-be robot oppressors. '),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
