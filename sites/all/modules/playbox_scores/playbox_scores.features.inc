<?php
/**
 * @file
 * playbox_scores.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_scores_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
