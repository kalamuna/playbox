<?php
/**
 * @file
 * panopoly_test.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function panopoly_test_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create panopoly_test_page content'.
  $permissions['create panopoly_test_page content'] = array(
    'name' => 'create panopoly_test_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panopoly_test_page content'.
  $permissions['delete any panopoly_test_page content'] = array(
    'name' => 'delete any panopoly_test_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panopoly_test_page content'.
  $permissions['delete own panopoly_test_page content'] = array(
    'name' => 'delete own panopoly_test_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panopoly_test_page content'.
  $permissions['edit any panopoly_test_page content'] = array(
    'name' => 'edit any panopoly_test_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
