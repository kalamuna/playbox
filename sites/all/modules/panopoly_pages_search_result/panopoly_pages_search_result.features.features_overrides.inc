<?php
/**
 * @file
 * panopoly_pages_search_result.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function panopoly_pages_search_result_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: variable
  $overrides["variable.panelizer_defaults_node_panopoly_page.value|view modes|search_result"] = array(
    'status' => 0,
    'default' => 0,
    'choice' => 0,
  );

 return $overrides;
}
