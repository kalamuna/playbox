<?php
/**
 * @file
 * playbox_presidents.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_presidents_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function playbox_presidents_node_info() {
  $items = array(
    'playbox_president' => array(
      'name' => t('Presidents'),
      'base' => 'node_content',
      'description' => t('This contains the data model for a president. '),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
