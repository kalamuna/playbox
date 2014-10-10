<?php
/**
 * @file
 * playbox_battles.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function playbox_battles_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'playbox_battles';
  $page->task = 'page';
  $page->admin_title = 'Playbox Battles';
  $page->admin_description = 'This contains the page for all playbox battles. ';
  $page->path = 'battles';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Battles',
    'name' => 'menu-left-main-menu',
    'weight' => '-50',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_playbox_battles_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'playbox_battles';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'playbox_rows';
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
    ),
  );
  $display->cache = array();
  $display->title = 'Battles of Humanity/Robotronix';
  $display->uuid = '43a25f58-f11b-4aad-bf0a-9685cf68762d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-33f38f03-deec-495e-956f-84de7ba81ec8';
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
    $pane->uuid = '33f38f03-deec-495e-956f-84de7ba81ec8';
    $display->content['new-33f38f03-deec-495e-956f-84de7ba81ec8'] = $pane;
    $display->panels['footer'][0] = 'new-33f38f03-deec-495e-956f-84de7ba81ec8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_battles'] = $page;

  return $pages;

}
