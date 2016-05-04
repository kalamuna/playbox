<?php
/**
 * @file
 * playbox_trumpit.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function playbox_trumpit_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-playbox_battle-field_playbox_trumped'
  $field_instances['node-playbox_battle-field_playbox_trumped'] = array(
    'bundle' => 'playbox_battle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_playbox_trumped',
    'label' => 'Trumped',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Trumped');

  return $field_instances;
}
