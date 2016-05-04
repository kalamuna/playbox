<?php
/**
 * @file
 * playbox_trumpit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_trumpit_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
