<?php
/**
 * @file
 * playbox_admin.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function playbox_admin_user_default_roles() {
  $roles = array();

  // Exported role: battle_author.
  $roles['battle_author'] = array(
    'name' => 'battle_author',
    'weight' => 2,
  );

  return $roles;
}
