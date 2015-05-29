<?php
/**
 * @file
 * playbox_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function playbox_core_user_default_roles() {
  $roles = array();

  // Exported role: Battle Curator.
  $roles['Battle Curator'] = array(
    'name' => 'Battle Curator',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
