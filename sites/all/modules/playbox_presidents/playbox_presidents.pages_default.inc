<?php
/**
 * @file
 * playbox_presidents.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function playbox_presidents_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'playbox_presidents';
  $page->task = 'page';
  $page->admin_title = 'Playbox Presidents';
  $page->admin_description = 'This contains a page for all the presidents. ';
  $page->path = 'presidents';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'name' => 'menu-left-main-menu',
    'weight' => '99',
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
  $handler->name = 'page_playbox_presidents_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'playbox_presidents';
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
    $pane->pid = 'new-58582ea4-8f5b-4cd1-8c20-9361b41e87ba';
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
    $pane->uuid = '58582ea4-8f5b-4cd1-8c20-9361b41e87ba';
    $display->content['new-58582ea4-8f5b-4cd1-8c20-9361b41e87ba'] = $pane;
    $display->panels['footer'][0] = 'new-58582ea4-8f5b-4cd1-8c20-9361b41e87ba';
    $pane = new stdClass();
    $pane->pid = 'new-c1694ccb-a801-47b6-a822-c8a51c7c4752';
    $pane->panel = 'jumbotron';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_presidents-playbox_president_header_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c1694ccb-a801-47b6-a822-c8a51c7c4752';
    $display->content['new-c1694ccb-a801-47b6-a822-c8a51c7c4752'] = $pane;
    $display->panels['jumbotron'][0] = 'new-c1694ccb-a801-47b6-a822-c8a51c7c4752';
    $pane = new stdClass();
    $pane->pid = 'new-d58a7343-9019-489d-86f6-bc9faefc5ab8';
    $pane->panel = 'row1';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_presidents-playbox_president_grid_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'fields_override' => array(
        'title' => 1,
        'field_playbox_portrait' => 1,
        'field_playbox_nickname' => 1,
      ),
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd58a7343-9019-489d-86f6-bc9faefc5ab8';
    $display->content['new-d58a7343-9019-489d-86f6-bc9faefc5ab8'] = $pane;
    $display->panels['row1'][0] = 'new-d58a7343-9019-489d-86f6-bc9faefc5ab8';
    $pane = new stdClass();
    $pane->pid = 'new-3366c8ec-9c01-4d0d-9708-e79b85257629';
    $pane->panel = 'row3';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_presidents-playbox_president_featured_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3366c8ec-9c01-4d0d-9708-e79b85257629';
    $display->content['new-3366c8ec-9c01-4d0d-9708-e79b85257629'] = $pane;
    $display->panels['row3'][0] = 'new-3366c8ec-9c01-4d0d-9708-e79b85257629';
    $pane = new stdClass();
    $pane->pid = 'new-82051d6a-8212-4bfe-b3ac-bc79e9832e86';
    $pane->panel = 'row4';
    $pane->type = 'playbox_static_instructions';
    $pane->subtype = 'playbox_static_instructions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'instructions_html' => ' <div class="container"><div class="row"><div class="col-md-12"><h2>So, how does this work?</h2><p>You need to vote on who would win in a fight: A president or a Megaman boss. The first player to the predetermined vote total is named the winner. You should consider the following factors:</p></div><div class="row"><div class="col-md-3 text-center"><i class="fa fa-bomb fa-5x space-bottom space-top"></i><h3>Explosiveness</h3><small>Everyone has an x-factor.</small></div><div class="col-md-3 text-center"><i class="fa fa-crosshairs fa-5x space-bottom space-top"></i><h3>Precision</h3><small>Doing the most with the least.</small></div><div class="col-md-3 text-center"><i class="fa fa-heart fa-5x space-bottom space-top"></i><h3>Passion</h3><small>Love and determination conquer all.</small></div><div class="col-md-3 text-center"><i class="fa fa-flask fa-5x space-bottom space-top"></i><h3>Logic</h3><small>Shrewd, cold, mechanic calculus.</small></div></div><div class="row"><div class="col-md-12 text-center space-top"><a href="battles" class="btn btn-success btn-lg" role="button">Check out the battles!</a></div></div>',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '82051d6a-8212-4bfe-b3ac-bc79e9832e86';
    $display->content['new-82051d6a-8212-4bfe-b3ac-bc79e9832e86'] = $pane;
    $display->panels['row4'][0] = 'new-82051d6a-8212-4bfe-b3ac-bc79e9832e86';
    $pane = new stdClass();
    $pane->pid = 'new-5e781905-e5d8-4960-ac8e-52120ad22a4e';
    $pane->panel = 'row5';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_battles-playbox_battles_featured_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5e781905-e5d8-4960-ac8e-52120ad22a4e';
    $display->content['new-5e781905-e5d8-4960-ac8e-52120ad22a4e'] = $pane;
    $display->panels['row5'][0] = 'new-5e781905-e5d8-4960-ac8e-52120ad22a4e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_presidents'] = $page;

  return $pages;

}
