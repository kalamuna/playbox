<?php
/**
 * @file
 * panopoly_pages_search_result.features.inc
 */

/**
 * Implements hook_strongarm_alter().
 */
function panopoly_pages_search_result_strongarm_alter(&$data) {
  if (isset($data['panelizer_defaults_node_panopoly_page'])) {
    $data['panelizer_defaults_node_panopoly_page']->value['view modes']['search_result'] = array(
      'status' => 0,
      'default' => 0,
      'choice' => 0,
    ); /* WAS: '' */
  }
}
