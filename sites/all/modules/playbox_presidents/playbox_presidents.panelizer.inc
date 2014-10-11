<?php
/**
 * @file
 * playbox_presidents.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function playbox_presidents_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:playbox_president:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'playbox_president';
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
      'default' => array(),
      'core' => array(),
      'des' => array(),
      'powers' => array(),
      'footer' => array(),
    ),
    'style' => 'kalacustomize',
    'core' => array(
      'style' => 'kalacustomize',
    ),
    'des' => array(
      'style' => 'kalacustomize',
    ),
    'powers' => array(
      'style' => 'kalacustomize',
    ),
    'footer' => array(
      'style' => 'kalacustomize',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '455527b9-a0f4-477b-8839-d8700c563c03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-24092bb1-673c-4e5c-8530-60598216667b';
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
      'settings' => array(),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '24092bb1-673c-4e5c-8530-60598216667b';
    $display->content['new-24092bb1-673c-4e5c-8530-60598216667b'] = $pane;
    $display->panels['core'][0] = 'new-24092bb1-673c-4e5c-8530-60598216667b';
    $pane = new stdClass();
    $pane->pid = 'new-26fe5ef0-985d-468b-9ac5-0921d9f83adc';
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '26fe5ef0-985d-468b-9ac5-0921d9f83adc';
    $display->content['new-26fe5ef0-985d-468b-9ac5-0921d9f83adc'] = $pane;
    $display->panels['core'][1] = 'new-26fe5ef0-985d-468b-9ac5-0921d9f83adc';
    $pane = new stdClass();
    $pane->pid = 'new-acd529fc-3c08-4abc-bae2-8d926e9087cf';
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
      'settings' => array(),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'acd529fc-3c08-4abc-bae2-8d926e9087cf';
    $display->content['new-acd529fc-3c08-4abc-bae2-8d926e9087cf'] = $pane;
    $display->panels['des'][0] = 'new-acd529fc-3c08-4abc-bae2-8d926e9087cf';
    $pane = new stdClass();
    $pane->pid = 'new-a4627050-956b-4b1d-8465-16c5fa202729';
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
      'settings' => array(),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a4627050-956b-4b1d-8465-16c5fa202729';
    $display->content['new-a4627050-956b-4b1d-8465-16c5fa202729'] = $pane;
    $display->panels['des'][1] = 'new-a4627050-956b-4b1d-8465-16c5fa202729';
    $pane = new stdClass();
    $pane->pid = 'new-7864b8e6-1df6-47eb-9d58-b42688a401ef';
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
      'settings' => array(),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7864b8e6-1df6-47eb-9d58-b42688a401ef';
    $display->content['new-7864b8e6-1df6-47eb-9d58-b42688a401ef'] = $pane;
    $display->panels['footer'][0] = 'new-7864b8e6-1df6-47eb-9d58-b42688a401ef';
    $pane = new stdClass();
    $pane->pid = 'new-d2e47caf-c796-4610-8703-16074f402983';
    $pane->panel = 'powers';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_playbox_powers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
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
      'settings' => array(),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd2e47caf-c796-4610-8703-16074f402983';
    $display->content['new-d2e47caf-c796-4610-8703-16074f402983'] = $pane;
    $display->panels['powers'][0] = 'new-d2e47caf-c796-4610-8703-16074f402983';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-26fe5ef0-985d-468b-9ac5-0921d9f83adc';
  $panelizer->display = $display;
  $export['node:playbox_president:default'] = $panelizer;

  return $export;
}
