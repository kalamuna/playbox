<?php
/**
 * @file
 * playbox_battles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function playbox_battles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create playbox_battle content'.
  $permissions['create playbox_battle content'] = array(
    'name' => 'create playbox_battle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any playbox_battle content'.
  $permissions['delete any playbox_battle content'] = array(
    'name' => 'delete any playbox_battle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own playbox_battle content'.
  $permissions['delete own playbox_battle content'] = array(
    'name' => 'delete own playbox_battle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any playbox_battle content'.
  $permissions['edit any playbox_battle content'] = array(
    'name' => 'edit any playbox_battle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own playbox_battle content'.
  $permissions['edit own playbox_battle content'] = array(
    'name' => 'edit own playbox_battle content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
