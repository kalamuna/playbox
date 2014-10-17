<?php
/**
 * @file
 * playbox_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function playbox_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'playbox_homepage';
  $page->task = 'page';
  $page->admin_title = 'Playbox Homepage';
  $page->admin_description = 'This is the homepage for the Playbox';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_playbox_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'playbox_homepage';
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '81843456-ceaf-4386-91a5-dd6450fe4f10';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bb2de5a1-19c2-434d-9c6b-00610ade8333';
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
    $pane->uuid = 'bb2de5a1-19c2-434d-9c6b-00610ade8333';
    $display->content['new-bb2de5a1-19c2-434d-9c6b-00610ade8333'] = $pane;
    $display->panels['footer'][0] = 'new-bb2de5a1-19c2-434d-9c6b-00610ade8333';
    $pane = new stdClass();
    $pane->pid = 'new-e8bbdb1d-279f-435c-bae2-cee6add42e14';
    $pane->panel = 'jumbotron';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_battles-playbox_battles_featured_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'full',
      'fields_override' => array(
        'field_playbox_battle_completed' => 0,
        'field_playbox_winner' => 0,
        'field_playbox_loser' => 0,
        'title' => 1,
        'field_playbox_portrait' => 1,
        'field_playbox_president_votes' => 1,
        'field_playbox_nickname' => 1,
        'field_playbox_battle_bio' => 1,
        'field_playbox_votes_to_win' => 1,
        'field_playbox_portrait_1' => 1,
        'field_playbox_robot_votes' => 1,
        'field_playbox_nickname_1' => 1,
      ),
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e8bbdb1d-279f-435c-bae2-cee6add42e14';
    $display->content['new-e8bbdb1d-279f-435c-bae2-cee6add42e14'] = $pane;
    $display->panels['jumbotron'][0] = 'new-e8bbdb1d-279f-435c-bae2-cee6add42e14';
    $pane = new stdClass();
    $pane->pid = 'new-bb3e543d-b61d-4580-8866-9353a49af3cf';
    $pane->panel = 'row1';
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
    $pane->uuid = 'bb3e543d-b61d-4580-8866-9353a49af3cf';
    $display->content['new-bb3e543d-b61d-4580-8866-9353a49af3cf'] = $pane;
    $display->panels['row1'][0] = 'new-bb3e543d-b61d-4580-8866-9353a49af3cf';
    $pane = new stdClass();
    $pane->pid = 'new-823dd144-c6ed-43f5-ba58-ce21f6bf93bc';
    $pane->panel = 'row3';
    $pane->type = 'views_panes';
    $pane->subtype = 'playbox_battles-playbox_battles_grid_1';
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
    $pane->uuid = '823dd144-c6ed-43f5-ba58-ce21f6bf93bc';
    $display->content['new-823dd144-c6ed-43f5-ba58-ce21f6bf93bc'] = $pane;
    $display->panels['row3'][0] = 'new-823dd144-c6ed-43f5-ba58-ce21f6bf93bc';
    $pane = new stdClass();
    $pane->pid = 'new-30c94c0f-7726-48dc-b02e-9756b65df51a';
    $pane->panel = 'row4';
    $pane->type = 'playbox_static_kalamuna';
    $pane->subtype = 'playbox_static_kalamuna';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'kalamuna_html' => '<div class="container"><div class="row"><div class="col-md-12"><h2>Seriously though... WTF is this?</h2></div><div class="row"><div class="col-md-4 text-center"><a href="http://www.kalamuna.com" target="_blank"><img src="http://identity.kalamuna.com/images/assets/logo_horizontal_tagline.png" alt="Kalamuna, Let\'s Play!"></a></div><div class="col-md-8"><p class="space-top">Playbox! is a sandbox-proving-ground for people interested in working with us here at Kalamuna. It\'s a magnificent and collaborative code-garden where would-be code artists, site builder and designers alike can play around and show what they\'ve got. Think you\'ve got what it takes?</p><a href="https://github.com/kalamuna/playbox" class="btn btn-success btn-lg" role="button">Then give it shot!</a></div></div>',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '30c94c0f-7726-48dc-b02e-9756b65df51a';
    $display->content['new-30c94c0f-7726-48dc-b02e-9756b65df51a'] = $pane;
    $display->panels['row4'][0] = 'new-30c94c0f-7726-48dc-b02e-9756b65df51a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_homepage'] = $page;

  return $pages;

}
