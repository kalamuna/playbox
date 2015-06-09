<?php
/**
 * @file
 * playbox_emergency.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function playbox_emergency_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:playbox_vice_president:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'playbox_vice_president';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '9b15d62d-6992-4d0f-8ff6-950f8ea551ee';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1a8bb2e2-2ddd-4a90-8708-540bf232dcd1';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_nickname';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1a8bb2e2-2ddd-4a90-8708-540bf232dcd1';
    $display->content['new-1a8bb2e2-2ddd-4a90-8708-540bf232dcd1'] = $pane;
    $display->panels['center'][0] = 'new-1a8bb2e2-2ddd-4a90-8708-540bf232dcd1';
    $pane = new stdClass();
    $pane->pid = 'new-891e4b50-6bf7-4348-80fc-9fe978bdb6eb';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_portrait';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'image_style' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '891e4b50-6bf7-4348-80fc-9fe978bdb6eb';
    $display->content['new-891e4b50-6bf7-4348-80fc-9fe978bdb6eb'] = $pane;
    $display->panels['center'][1] = 'new-891e4b50-6bf7-4348-80fc-9fe978bdb6eb';
    $pane = new stdClass();
    $pane->pid = 'new-5e26c239-de04-4022-b22b-1c91b7154e6b';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5e26c239-de04-4022-b22b-1c91b7154e6b';
    $display->content['new-5e26c239-de04-4022-b22b-1c91b7154e6b'] = $pane;
    $display->panels['center'][2] = 'new-5e26c239-de04-4022-b22b-1c91b7154e6b';
    $pane = new stdClass();
    $pane->pid = 'new-f3ac0e05-25db-4913-8126-3c8a56025e7e';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_powers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f3ac0e05-25db-4913-8126-3c8a56025e7e';
    $display->content['new-f3ac0e05-25db-4913-8126-3c8a56025e7e'] = $pane;
    $display->panels['center'][3] = 'new-f3ac0e05-25db-4913-8126-3c8a56025e7e';
    $pane = new stdClass();
    $pane->pid = 'new-8884b2bd-32d6-40c9-80b7-5a0c615cee2f';
    $pane->panel = 'center';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8884b2bd-32d6-40c9-80b7-5a0c615cee2f';
    $display->content['new-8884b2bd-32d6-40c9-80b7-5a0c615cee2f'] = $pane;
    $display->panels['center'][4] = 'new-8884b2bd-32d6-40c9-80b7-5a0c615cee2f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8884b2bd-32d6-40c9-80b7-5a0c615cee2f';
  $panelizer->display = $display;
  $export['node:playbox_vice_president:default'] = $panelizer;

  return $export;
}
