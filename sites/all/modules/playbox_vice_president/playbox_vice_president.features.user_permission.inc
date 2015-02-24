<?php
/**
 * @file
 * playbox_vice_president.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function playbox_vice_president_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node vice_president breadcrumbs'.
  $permissions['administer panelizer node vice_president breadcrumbs'] = array(
    'name' => 'administer panelizer node vice_president breadcrumbs',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node vice_president content'.
  $permissions['administer panelizer node vice_president content'] = array(
    'name' => 'administer panelizer node vice_president content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node vice_president context'.
  $permissions['administer panelizer node vice_president context'] = array(
    'name' => 'administer panelizer node vice_president context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node vice_president defaults'.
  $permissions['administer panelizer node vice_president defaults'] = array(
    'name' => 'administer panelizer node vice_president defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node vice_president layout'.
  $permissions['administer panelizer node vice_president layout'] = array(
    'name' => 'administer panelizer node vice_president layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node vice_president overview'.
  $permissions['administer panelizer node vice_president overview'] = array(
    'name' => 'administer panelizer node vice_president overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node vice_president settings'.
  $permissions['administer panelizer node vice_president settings'] = array(
    'name' => 'administer panelizer node vice_president settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'create vice_president content'.
  $permissions['create vice_president content'] = array(
    'name' => 'create vice_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any vice_president content'.
  $permissions['delete any vice_president content'] = array(
    'name' => 'delete any vice_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own vice_president content'.
  $permissions['delete own vice_president content'] = array(
    'name' => 'delete own vice_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any vice_president content'.
  $permissions['edit any vice_president content'] = array(
    'name' => 'edit any vice_president content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own vice_president content'.
  $permissions['edit own vice_president content'] = array(
    'name' => 'edit own vice_president content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
