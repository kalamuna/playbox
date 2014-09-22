<?php
/**
 * @file
 * playbox_robots.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function playbox_robots_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create playbox_robot content'.
  $permissions['create playbox_robot content'] = array(
    'name' => 'create playbox_robot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any playbox_robot content'.
  $permissions['delete any playbox_robot content'] = array(
    'name' => 'delete any playbox_robot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own playbox_robot content'.
  $permissions['delete own playbox_robot content'] = array(
    'name' => 'delete own playbox_robot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any playbox_robot content'.
  $permissions['edit any playbox_robot content'] = array(
    'name' => 'edit any playbox_robot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own playbox_robot content'.
  $permissions['edit own playbox_robot content'] = array(
    'name' => 'edit own playbox_robot content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
