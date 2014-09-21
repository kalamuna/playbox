<?php
/**
 * @file
 * playbox_presidents.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function playbox_presidents_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create playbox_president content'.
  $permissions['create playbox_president content'] = array(
    'name' => 'create playbox_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any playbox_president content'.
  $permissions['delete any playbox_president content'] = array(
    'name' => 'delete any playbox_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own playbox_president content'.
  $permissions['delete own playbox_president content'] = array(
    'name' => 'delete own playbox_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any playbox_president content'.
  $permissions['edit any playbox_president content'] = array(
    'name' => 'edit any playbox_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own playbox_president content'.
  $permissions['edit own playbox_president content'] = array(
    'name' => 'edit own playbox_president content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
