<?php
/**
 * @file
 * playbox_vice_president.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function playbox_vice_president_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:vice_president:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'vice_president';
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
  $display->uuid = '5909c315-9cbd-42f0-aa3f-b9ecdfd8b84d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9401a047-bbc3-48b9-8d19-78f404b0dc74';
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
    $pane->uuid = '9401a047-bbc3-48b9-8d19-78f404b0dc74';
    $display->content['new-9401a047-bbc3-48b9-8d19-78f404b0dc74'] = $pane;
    $display->panels['center'][0] = 'new-9401a047-bbc3-48b9-8d19-78f404b0dc74';
    $pane = new stdClass();
    $pane->pid = 'new-45aeacaf-6aca-45aa-b024-ca407fb1f5fd';
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
        'image_style' => '',
        'image_link' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '45aeacaf-6aca-45aa-b024-ca407fb1f5fd';
    $display->content['new-45aeacaf-6aca-45aa-b024-ca407fb1f5fd'] = $pane;
    $display->panels['center'][1] = 'new-45aeacaf-6aca-45aa-b024-ca407fb1f5fd';
    $pane = new stdClass();
    $pane->pid = 'new-1773b0c7-e346-4e39-9027-60bcedb27195';
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
    $pane->uuid = '1773b0c7-e346-4e39-9027-60bcedb27195';
    $display->content['new-1773b0c7-e346-4e39-9027-60bcedb27195'] = $pane;
    $display->panels['center'][2] = 'new-1773b0c7-e346-4e39-9027-60bcedb27195';
    $pane = new stdClass();
    $pane->pid = 'new-02d69027-0b8b-4ae8-9a60-d5a34d80461a';
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
    $pane->uuid = '02d69027-0b8b-4ae8-9a60-d5a34d80461a';
    $display->content['new-02d69027-0b8b-4ae8-9a60-d5a34d80461a'] = $pane;
    $display->panels['center'][3] = 'new-02d69027-0b8b-4ae8-9a60-d5a34d80461a';
    $pane = new stdClass();
    $pane->pid = 'new-b8e8c48d-077e-4b8e-84fc-c26dc51df821';
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
    $pane->uuid = 'b8e8c48d-077e-4b8e-84fc-c26dc51df821';
    $display->content['new-b8e8c48d-077e-4b8e-84fc-c26dc51df821'] = $pane;
    $display->panels['center'][4] = 'new-b8e8c48d-077e-4b8e-84fc-c26dc51df821';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b8e8c48d-077e-4b8e-84fc-c26dc51df821';
  $panelizer->display = $display;
  $export['node:vice_president:default'] = $panelizer;

  return $export;
}
