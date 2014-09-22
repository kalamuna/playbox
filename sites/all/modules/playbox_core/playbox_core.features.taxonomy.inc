<?php
/**
 * @file
 * playbox_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function playbox_core_taxonomy_default_vocabularies() {
  return array(
    'playbox_tags' => array(
      'name' => 'Playbox Tags',
      'machine_name' => 'playbox_tags',
      'description' => 'This is a way to sort playbox things',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
