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
  $display->uuid = '05c36bc4-daed-4aaa-b5e4-07218af2b2ca';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce4456b6-cda1-4a12-bf80-9022f112ae67';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_portrait';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = 'ce4456b6-cda1-4a12-bf80-9022f112ae67';
    $display->content['new-ce4456b6-cda1-4a12-bf80-9022f112ae67'] = $pane;
    $display->panels['center'][0] = 'new-ce4456b6-cda1-4a12-bf80-9022f112ae67';
    $pane = new stdClass();
    $pane->pid = 'new-1eb716c3-93ef-462a-ba55-2c2382235980';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = '1eb716c3-93ef-462a-ba55-2c2382235980';
    $display->content['new-1eb716c3-93ef-462a-ba55-2c2382235980'] = $pane;
    $display->panels['center'][1] = 'new-1eb716c3-93ef-462a-ba55-2c2382235980';
    $pane = new stdClass();
    $pane->pid = 'new-fc78c257-a66c-46c1-8b1c-9f013f88d3d8';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_nickname';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = 'fc78c257-a66c-46c1-8b1c-9f013f88d3d8';
    $display->content['new-fc78c257-a66c-46c1-8b1c-9f013f88d3d8'] = $pane;
    $display->panels['center'][2] = 'new-fc78c257-a66c-46c1-8b1c-9f013f88d3d8';
    $pane = new stdClass();
    $pane->pid = 'new-c8403521-e661-4da4-93af-34d773c546eb';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_powers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = 'c8403521-e661-4da4-93af-34d773c546eb';
    $display->content['new-c8403521-e661-4da4-93af-34d773c546eb'] = $pane;
    $display->panels['center'][3] = 'new-c8403521-e661-4da4-93af-34d773c546eb';
    $pane = new stdClass();
    $pane->pid = 'new-ece4141f-ac7f-4531-a952-66543d2e753e';
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
    $pane->uuid = 'ece4141f-ac7f-4531-a952-66543d2e753e';
    $display->content['new-ece4141f-ac7f-4531-a952-66543d2e753e'] = $pane;
    $display->panels['center'][4] = 'new-ece4141f-ac7f-4531-a952-66543d2e753e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ece4141f-ac7f-4531-a952-66543d2e753e';
  $panelizer->display = $display;
  $export['node:playbox_robot:default'] = $panelizer;

  return $export;
}
