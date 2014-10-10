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
    $pane->pid = 'new-5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd';
    $pane->panel = 'row1';
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
    $pane->uuid = '5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd';
    $display->content['new-5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd'] = $pane;
    $display->panels['row1'][0] = 'new-5f94c76c-e8f9-461a-b5cf-9ce9eb3576fd';
    $pane = new stdClass();
    $pane->pid = 'new-7677d2bf-6bbf-4e03-96fb-6e8b5ceee193';
    $pane->panel = 'row2';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_battles-playbox_battles_list_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '10',
      'fields_override' => array(
        'field_playbox_battle_completed' => 0,
        'field_playbox_winner' => 0,
        'field_playbox_loser' => 0,
        'title' => 1,
        'field_playbox_battle_bio' => 1,
        'field_playbox_president_votes' => 1,
        'field_playbox_robot_votes' => 1,
        'field_playbox_votes_to_win' => 1,
        'field_playbox_nickname' => 1,
        'field_playbox_portrait' => 1,
        'field_playbox_nickname_1' => 1,
        'field_playbox_portrait_1' => 1,
      ),
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
    $pane->uuid = '7677d2bf-6bbf-4e03-96fb-6e8b5ceee193';
    $display->content['new-7677d2bf-6bbf-4e03-96fb-6e8b5ceee193'] = $pane;
    $display->panels['row2'][0] = 'new-7677d2bf-6bbf-4e03-96fb-6e8b5ceee193';
    $pane = new stdClass();
    $pane->pid = 'new-4ad5514f-089a-4fbf-8f63-39f63b38e1b7';
    $pane->panel = 'row2';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_battles-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '10',
      'fields_override' => array(
        'field_playbox_battle_completed' => 0,
        'field_playbox_winner' => 0,
        'field_playbox_loser' => 0,
        'title' => 1,
        'field_playbox_nickname' => 1,
        'field_playbox_portrait' => 1,
        'field_playbox_president_votes' => 1,
        'field_playbox_battle_bio' => 1,
        'field_playbox_votes_to_win' => 1,
        'field_playbox_nickname_1' => 1,
        'field_playbox_robot_votes' => 1,
        'field_playbox_portrait_1' => 1,
      ),
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4ad5514f-089a-4fbf-8f63-39f63b38e1b7';
    $display->content['new-4ad5514f-089a-4fbf-8f63-39f63b38e1b7'] = $pane;
    $display->panels['row2'][1] = 'new-4ad5514f-089a-4fbf-8f63-39f63b38e1b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_battles'] = $page;

  return $pages;

}
