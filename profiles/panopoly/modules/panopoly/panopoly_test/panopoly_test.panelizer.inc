<?php
/**
 * @file
 * panopoly_test.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function panopoly_test_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:panopoly_test_page:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'panopoly_test_page';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = 'page-page';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = '';
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $display = new panels_display();
  $display->layout = 'bryant';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '16346c80-6fcf-4cee-bf7a-9c0173fc2916';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_featured_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => 'content',
        'image_style' => 'panopoly_image_half',
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
    $pane->uuid = '34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
    $display->content['new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1'] = $pane;
    $display->panels['contentmain'][0] = 'new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
    $pane = new stdClass();
    $pane->pid = 'new-59cafe99-f0a0-4a3a-a13f-8f108d69d18b';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '250',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '59cafe99-f0a0-4a3a-a13f-8f108d69d18b';
    $display->content['new-59cafe99-f0a0-4a3a-a13f-8f108d69d18b'] = $pane;
    $display->panels['contentmain'][1] = 'new-59cafe99-f0a0-4a3a-a13f-8f108d69d18b';
    $pane = new stdClass();
    $pane->pid = 'new-f3bf9c22-9b22-41d2-a57e-110951093871';
    $pane->panel = 'contentmain';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'featured',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f3bf9c22-9b22-41d2-a57e-110951093871';
    $display->content['new-f3bf9c22-9b22-41d2-a57e-110951093871'] = $pane;
    $display->panels['contentmain'][2] = 'new-f3bf9c22-9b22-41d2-a57e-110951093871';
    $pane = new stdClass();
    $pane->pid = 'new-0a2c7b96-5f45-4e85-8e00-88fee50f4f71';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_featured_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_link',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0a2c7b96-5f45-4e85-8e00-88fee50f4f71';
    $display->content['new-0a2c7b96-5f45-4e85-8e00-88fee50f4f71'] = $pane;
    $display->panels['contentmain'][3] = 'new-0a2c7b96-5f45-4e85-8e00-88fee50f4f71';
    $pane = new stdClass();
    $pane->pid = 'new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1';
    $pane->panel = 'sidebar';
    $pane->type = 'menu_tree';
    $pane->subtype = 'main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'main-menu',
      'parent_mlid' => 'main-menu:0',
      'title_link' => 0,
      'admin_title' => '',
      'level' => '2',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
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
    $pane->uuid = 'c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1';
    $display->content['new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1'] = $pane;
    $display->panels['sidebar'][0] = 'new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
  $panelizer->display = $display;
  $export['node:panopoly_test_page:default'] = $panelizer;

  return $export;
}
