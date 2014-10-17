<?php
/**
 * @file
 * playbox_scores.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function playbox_scores_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'playbox_scores';
  $page->task = 'page';
  $page->admin_title = 'Playbox Scores';
  $page->admin_description = 'This contains some fun metrics for playbox scores.';
  $page->path = 'scores';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Scores',
    'name' => 'menu-right-main-menu',
    'weight' => '50',
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
  $handler->name = 'page_playbox_scores_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'playbox_scores';
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
  $display->title = 'Scores';
  $display->uuid = '6178e5a0-aa81-4de5-bca8-7df8f98f30f4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fc9f0af2-ec13-4006-bc79-e8095161397f';
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
    $pane->uuid = 'fc9f0af2-ec13-4006-bc79-e8095161397f';
    $display->content['new-fc9f0af2-ec13-4006-bc79-e8095161397f'] = $pane;
    $display->panels['footer'][0] = 'new-fc9f0af2-ec13-4006-bc79-e8095161397f';
    $pane = new stdClass();
    $pane->pid = 'new-c72c54c7-1bda-4fe8-be8f-cbe1db49b0a8';
    $pane->panel = 'row1';
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
    $pane->uuid = 'c72c54c7-1bda-4fe8-be8f-cbe1db49b0a8';
    $display->content['new-c72c54c7-1bda-4fe8-be8f-cbe1db49b0a8'] = $pane;
    $display->panels['row1'][0] = 'new-c72c54c7-1bda-4fe8-be8f-cbe1db49b0a8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playbox_scores'] = $page;

  return $pages;

}
