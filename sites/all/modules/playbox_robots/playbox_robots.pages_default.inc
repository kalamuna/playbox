<?php
/**
 * @file
 * playbox_robots.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function playbox_robots_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'playbox_robots';
  $page->task = 'page';
  $page->admin_title = 'Playbox Robots';
  $page->admin_description = 'This contains a page for all the presidents. ';
  $page->path = 'robots';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'name' => 'menu-right-main-menu',
    'weight' => '-99',
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
  $handler->name = 'page_playbox_robots_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'playbox_robots';
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
  $display->title = '';
  $display->uuid = '1b959402-e029-40f7-b54b-563dd8e7f420';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3293caf-4d29-4c6a-a6cf-cebe9149fac7';
    $pane->panel = 'row1';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_robots-playbox_robot_grid_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'fields_override' => array(
        'title' => 1,
        'field_playbox_nickname' => 1,
        'field_playbox_portrait' => 1,
      ),
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd3293caf-4d29-4c6a-a6cf-cebe9149fac7';
    $display->content['new-d3293caf-4d29-4c6a-a6cf-cebe9149fac7'] = $pane;
    $display->panels['row1'][0] = 'new-d3293caf-4d29-4c6a-a6cf-cebe9149fac7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_robots'] = $page;

  return $pages;

}
