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
    $pane = new stdClass();
    $pane->pid = 'new-61e9f965-412d-423e-8f59-10dde796d811';
    $pane->panel = 'jumbotron';
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
    $pane->uuid = '61e9f965-412d-423e-8f59-10dde796d811';
    $display->content['new-61e9f965-412d-423e-8f59-10dde796d811'] = $pane;
    $display->panels['jumbotron'][0] = 'new-61e9f965-412d-423e-8f59-10dde796d811';
    $pane = new stdClass();
    $pane->pid = 'new-5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd';
    $pane->panel = 'row2';
    $pane->type = 'playbox_static_instructions';
    $pane->subtype = 'playbox_static_instructions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'instructions_html' => ' <div class="container"><div class="row"><div class="col-md-12"><h2>So, how does this work?</h2><p>You need to vote on who would win in a fight: A president or a Megaman boss. The first player to the predetermined vote total is named the winner. You should consider the following factors:</p></div><div class="row"><div class="col-md-3 col-sm-6 text-center"><i class="fa fa-bomb fa-5x space-bottom space-top"></i><h3>Explosiveness</h3><small>Everyone has an x-factor.</small></div><div class="col-md-3 col-sm-6 text-center"><i class="fa fa-crosshairs fa-5x space-bottom space-top"></i><h3>Precision</h3><small>Doing the most with the least.</small></div><div class="col-md-3 col-sm-6 text-center"><i class="fa fa-heart fa-5x space-bottom space-top"></i><h3>Passion</h3><small>Love and determination conquer all.</small></div><div class="col-md-3 col-sm-6 text-center"><i class="fa fa-flask fa-5x space-bottom space-top"></i><h3>Logic</h3><small>Shrewd, cold, mechanic calculus.</small></div></div><div class="row"><div class="col-md-12 text-center space-top"><a href="battles" class="btn btn-success btn-lg" role="button">Check out the battles!</a></div></div>',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd';
    $display->content['new-5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd'] = $pane;
    $display->panels['row2'][0] = 'new-5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd';
    $pane = new stdClass();
    $pane->pid = 'new-771a40cd-4cbf-4a8a-9610-0534e8565d4a';
    $pane->panel = 'row4';
    $pane->type = 'playbox_static_kalamuna';
    $pane->subtype = 'playbox_static_kalamuna';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'kalamuna_html' => '<div class="container"><div class="row"><div class="col-md-12"><h2>Seriously though... WTF is this?</h2></div></div><div class="row"><div class="col-md-4 text-center"><a href="http://www.kalamuna.com" target="_blank"><img src="http://identity.kalamuna.com/images/assets/logo_horizontal_tagline.png" alt="Kalamuna, Let\'s Play!"></a></div><div class="col-md-8"><p class="space-top">Playbox! is a sandbox-proving-ground for people interested in working with us here at Kalamuna. It\'s a magnificent and collaborative code-garden where would-be code artists, site builder and designers alike can play around and show what they\'ve got. Think you\'ve got what it takes?</p><a href="https://github.com/kalamuna/playbox" class="btn btn-success btn-lg" role="button">Then give it shot!</a></div></div>',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '771a40cd-4cbf-4a8a-9610-0534e8565d4a';
    $display->content['new-771a40cd-4cbf-4a8a-9610-0534e8565d4a'] = $pane;
    $display->panels['row4'][0] = 'new-771a40cd-4cbf-4a8a-9610-0534e8565d4a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_battles'] = $page;

  return $pages;

}
