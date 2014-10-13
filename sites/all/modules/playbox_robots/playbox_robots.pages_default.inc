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
    $pane->pid = 'new-2b0094c1-e4f7-4dcb-881e-c87f34d5f7a3';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2b0094c1-e4f7-4dcb-881e-c87f34d5f7a3';
    $display->content['new-2b0094c1-e4f7-4dcb-881e-c87f34d5f7a3'] = $pane;
    $display->panels['footer'][0] = 'new-2b0094c1-e4f7-4dcb-881e-c87f34d5f7a3';
    $pane = new stdClass();
    $pane->pid = 'new-ab83792c-0bc3-4fae-be89-66487fe44fc0';
    $pane->panel = 'jumbotron';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_robots-playbox_robot_header_1';
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
    $pane->uuid = 'ab83792c-0bc3-4fae-be89-66487fe44fc0';
    $display->content['new-ab83792c-0bc3-4fae-be89-66487fe44fc0'] = $pane;
    $display->panels['jumbotron'][0] = 'new-ab83792c-0bc3-4fae-be89-66487fe44fc0';
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
    $pane = new stdClass();
    $pane->pid = 'new-05ffa6e1-5f80-4443-9cfa-1ee2c9d87965';
    $pane->panel = 'row3';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_robots-playbox_robot_featured_1';
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
    $pane->uuid = '05ffa6e1-5f80-4443-9cfa-1ee2c9d87965';
    $display->content['new-05ffa6e1-5f80-4443-9cfa-1ee2c9d87965'] = $pane;
    $display->panels['row3'][0] = 'new-05ffa6e1-5f80-4443-9cfa-1ee2c9d87965';
    $pane = new stdClass();
    $pane->pid = 'new-31376910-10f1-48ff-afb3-f1c2b2fcbbc3';
    $pane->panel = 'row4';
    $pane->type = 'playbox_static_kalamuna';
    $pane->subtype = 'playbox_static_kalamuna';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'kalamuna_html' => '<div class="container"><div class="row"><div class="col-md-12"><h2>Seriously though... WTF is this?</h2></div></div><div class="row"><div class="col-md-4 text-center"><img src="http://identity.kalamuna.com/images/assets/logo_horizontal_tagline.png" alt="Kalamuna, Let\'s Play!"></div><div class="col-md-8"><p class="space-top">Playbox! is a sandbox-proving-ground for people interested in working with us here at Kalamuna. It\'s a magnificent and collaborative code-garden where would-be code artists, site builder and designers alike can play around and show what they\'ve got. Think you\'ve got what it takes?</p><a href="https://github.com/kalamuna/playbox" class="btn btn-success btn-lg" role="button">Then give it shot!</a></div></div>',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '31376910-10f1-48ff-afb3-f1c2b2fcbbc3';
    $display->content['new-31376910-10f1-48ff-afb3-f1c2b2fcbbc3'] = $pane;
    $display->panels['row4'][0] = 'new-31376910-10f1-48ff-afb3-f1c2b2fcbbc3';
    $pane = new stdClass();
    $pane->pid = 'new-e94c7932-9bfc-4251-b64c-45f83137ce4c';
    $pane->panel = 'row5';
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
    $pane->uuid = 'e94c7932-9bfc-4251-b64c-45f83137ce4c';
    $display->content['new-e94c7932-9bfc-4251-b64c-45f83137ce4c'] = $pane;
    $display->panels['row5'][0] = 'new-e94c7932-9bfc-4251-b64c-45f83137ce4c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_robots'] = $page;

  return $pages;

}
