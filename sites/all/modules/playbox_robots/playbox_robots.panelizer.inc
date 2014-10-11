<?php
/**
 * @file
 * playbox_robots.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function playbox_robots_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:playbox_robot:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'playbox_robot';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'battler_rows';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'jumbotron' => NULL,
      'row1' => NULL,
      'row2' => NULL,
      'row3' => NULL,
      'row4' => NULL,
      'row5' => NULL,
      'row6' => NULL,
      'row7' => NULL,
      'footer' => NULL,
      'core' => NULL,
      'des' => NULL,
      'powers' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '05c36bc4-daed-4aaa-b5e4-07218af2b2ca';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce4456b6-cda1-4a12-bf80-9022f112ae67';
    $pane->panel = 'core';
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
        'image_style' => 'playbox_portrait_featured',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce4456b6-cda1-4a12-bf80-9022f112ae67';
    $display->content['new-ce4456b6-cda1-4a12-bf80-9022f112ae67'] = $pane;
    $display->panels['core'][0] = 'new-ce4456b6-cda1-4a12-bf80-9022f112ae67';
    $pane = new stdClass();
    $pane->pid = 'new-fc78c257-a66c-46c1-8b1c-9f013f88d3d8';
    $pane->panel = 'core';
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
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fc78c257-a66c-46c1-8b1c-9f013f88d3d8';
    $display->content['new-fc78c257-a66c-46c1-8b1c-9f013f88d3d8'] = $pane;
    $display->panels['core'][1] = 'new-fc78c257-a66c-46c1-8b1c-9f013f88d3d8';
    $pane = new stdClass();
    $pane->pid = 'new-33770186-b373-4326-9eca-fc6b4e13c423';
    $pane->panel = 'des';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '%node:title',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '33770186-b373-4326-9eca-fc6b4e13c423';
    $display->content['new-33770186-b373-4326-9eca-fc6b4e13c423'] = $pane;
    $display->panels['des'][0] = 'new-33770186-b373-4326-9eca-fc6b4e13c423';
    $pane = new stdClass();
    $pane->pid = 'new-1eb716c3-93ef-462a-ba55-2c2382235980';
    $pane->panel = 'des';
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
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1eb716c3-93ef-462a-ba55-2c2382235980';
    $display->content['new-1eb716c3-93ef-462a-ba55-2c2382235980'] = $pane;
    $display->panels['des'][1] = 'new-1eb716c3-93ef-462a-ba55-2c2382235980';
    $pane = new stdClass();
    $pane->pid = 'new-4cf1862f-7e91-4f0c-bf89-be61705bc819';
    $pane->panel = 'footer';
    $pane->type = 'playbox_static_footer';
    $pane->subtype = 'playbox_static_footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'footer_html' => '&copy; 2014 Kalamuna LLC',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4cf1862f-7e91-4f0c-bf89-be61705bc819';
    $display->content['new-4cf1862f-7e91-4f0c-bf89-be61705bc819'] = $pane;
    $display->panels['footer'][0] = 'new-4cf1862f-7e91-4f0c-bf89-be61705bc819';
    $pane = new stdClass();
    $pane->pid = 'new-c8403521-e661-4da4-93af-34d773c546eb';
    $pane->panel = 'powers';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_powers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'playbox_core_feature_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c8403521-e661-4da4-93af-34d773c546eb';
    $display->content['new-c8403521-e661-4da4-93af-34d773c546eb'] = $pane;
    $display->panels['powers'][0] = 'new-c8403521-e661-4da4-93af-34d773c546eb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:playbox_robot:default'] = $panelizer;

  return $export;
}
