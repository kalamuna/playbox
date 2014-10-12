<?php
/**
 * @file
 * playbox_battles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function playbox_battles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'playbox_battles';
  $view->description = 'Views for all the playbox battles. ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Playbox Battles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_playbox_president_target_id']['id'] = 'field_playbox_president_target_id';
  $handler->display->display_options['relationships']['field_playbox_president_target_id']['table'] = 'field_data_field_playbox_president';
  $handler->display->display_options['relationships']['field_playbox_president_target_id']['field'] = 'field_playbox_president_target_id';
  $handler->display->display_options['relationships']['field_playbox_president_target_id']['label'] = 'Related President';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_playbox_robot_target_id']['id'] = 'field_playbox_robot_target_id';
  $handler->display->display_options['relationships']['field_playbox_robot_target_id']['table'] = 'field_data_field_playbox_robot';
  $handler->display->display_options['relationships']['field_playbox_robot_target_id']['field'] = 'field_playbox_robot_target_id';
  $handler->display->display_options['relationships']['field_playbox_robot_target_id']['label'] = 'Related Robot';
  /* Field: Content: Battle Completed */
  $handler->display->display_options['fields']['field_playbox_battle_completed']['id'] = 'field_playbox_battle_completed';
  $handler->display->display_options['fields']['field_playbox_battle_completed']['table'] = 'field_data_field_playbox_battle_completed';
  $handler->display->display_options['fields']['field_playbox_battle_completed']['field'] = 'field_playbox_battle_completed';
  $handler->display->display_options['fields']['field_playbox_battle_completed']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_battle_completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_battle_completed']['element_label_colon'] = FALSE;
  /* Field: Content: Winner */
  $handler->display->display_options['fields']['field_playbox_winner']['id'] = 'field_playbox_winner';
  $handler->display->display_options['fields']['field_playbox_winner']['table'] = 'field_data_field_playbox_winner';
  $handler->display->display_options['fields']['field_playbox_winner']['field'] = 'field_playbox_winner';
  $handler->display->display_options['fields']['field_playbox_winner']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_winner']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_winner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_winner']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_playbox_winner']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Loser */
  $handler->display->display_options['fields']['field_playbox_loser']['id'] = 'field_playbox_loser';
  $handler->display->display_options['fields']['field_playbox_loser']['table'] = 'field_data_field_playbox_loser';
  $handler->display->display_options['fields']['field_playbox_loser']['field'] = 'field_playbox_loser';
  $handler->display->display_options['fields']['field_playbox_loser']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_loser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_loser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_loser']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_playbox_loser']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: President Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait']['id'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['relationship'] = 'field_playbox_president_target_id';
  $handler->display->display_options['fields']['field_playbox_portrait']['ui_name'] = 'President Portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_playbox_portrait']['settings'] = array(
    'image_style' => 'playbox_portrait_featured',
    'image_link' => '',
  );
  /* Field: Content: President Votes */
  $handler->display->display_options['fields']['field_playbox_president_votes']['id'] = 'field_playbox_president_votes';
  $handler->display->display_options['fields']['field_playbox_president_votes']['table'] = 'field_data_field_playbox_president_votes';
  $handler->display->display_options['fields']['field_playbox_president_votes']['field'] = 'field_playbox_president_votes';
  $handler->display->display_options['fields']['field_playbox_president_votes']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_president_votes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_president_votes']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: President Nickname */
  $handler->display->display_options['fields']['field_playbox_nickname']['id'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['table'] = 'field_data_field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['field'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['relationship'] = 'field_playbox_president_target_id';
  $handler->display->display_options['fields']['field_playbox_nickname']['ui_name'] = 'President Nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_nickname']['element_label_colon'] = FALSE;
  /* Field: Content: Battle Description */
  $handler->display->display_options['fields']['field_playbox_battle_bio']['id'] = 'field_playbox_battle_bio';
  $handler->display->display_options['fields']['field_playbox_battle_bio']['table'] = 'field_data_field_playbox_battle_bio';
  $handler->display->display_options['fields']['field_playbox_battle_bio']['field'] = 'field_playbox_battle_bio';
  $handler->display->display_options['fields']['field_playbox_battle_bio']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_battle_bio']['element_label_colon'] = FALSE;
  /* Field: Content: Votes to Win */
  $handler->display->display_options['fields']['field_playbox_votes_to_win']['id'] = 'field_playbox_votes_to_win';
  $handler->display->display_options['fields']['field_playbox_votes_to_win']['table'] = 'field_data_field_playbox_votes_to_win';
  $handler->display->display_options['fields']['field_playbox_votes_to_win']['field'] = 'field_playbox_votes_to_win';
  $handler->display->display_options['fields']['field_playbox_votes_to_win']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_votes_to_win']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_votes_to_win']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Robot Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait_1']['id'] = 'field_playbox_portrait_1';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['relationship'] = 'field_playbox_robot_target_id';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['ui_name'] = 'Robot Portrait';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_portrait_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_playbox_portrait_1']['settings'] = array(
    'image_style' => 'playbox_portrait_featured',
    'image_link' => '',
  );
  /* Field: Content: Robot Votes */
  $handler->display->display_options['fields']['field_playbox_robot_votes']['id'] = 'field_playbox_robot_votes';
  $handler->display->display_options['fields']['field_playbox_robot_votes']['table'] = 'field_data_field_playbox_robot_votes';
  $handler->display->display_options['fields']['field_playbox_robot_votes']['field'] = 'field_playbox_robot_votes';
  $handler->display->display_options['fields']['field_playbox_robot_votes']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_robot_votes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_robot_votes']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Robot Nickname */
  $handler->display->display_options['fields']['field_playbox_nickname_1']['id'] = 'field_playbox_nickname_1';
  $handler->display->display_options['fields']['field_playbox_nickname_1']['table'] = 'field_data_field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname_1']['field'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname_1']['relationship'] = 'field_playbox_robot_target_id';
  $handler->display->display_options['fields']['field_playbox_nickname_1']['ui_name'] = 'Robot Nickname';
  $handler->display->display_options['fields']['field_playbox_nickname_1']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_nickname_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'playbox_battle' => 'playbox_battle',
  );
  /* Filter criterion: Content: Battle Completed (field_playbox_battle_completed) */
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['id'] = 'field_playbox_battle_completed_value';
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['table'] = 'field_data_field_playbox_battle_completed';
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['field'] = 'field_playbox_battle_completed_value';
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['value'] = array(
    0 => '0',
  );

  /* Display: List of onging Playbox Battles */
  $handler = $view->new_display('panel_pane', 'List of onging Playbox Battles', 'playbox_battles_list_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ongoing Battles';
  $handler->display->display_options['display_description'] = 'A nice list of the ongoing playbox battles';
  $handler->display->display_options['pane_title'] = 'List of ongoing playbox battles';
  $handler->display->display_options['pane_description'] = 'A list of the ongoing playbox battles';
  $handler->display->display_options['pane_category']['name'] = 'Battles';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';

  /* Display: List of completed Playbox Battles */
  $handler = $view->new_display('panel_pane', 'List of completed Playbox Battles', 'playbox_battles_list_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Completed Battles';
  $handler->display->display_options['display_description'] = 'A nice list of the completed playbox battles';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'playbox_battle' => 'playbox_battle',
  );
  /* Filter criterion: Content: Battle Completed (field_playbox_battle_completed) */
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['id'] = 'field_playbox_battle_completed_value';
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['table'] = 'field_data_field_playbox_battle_completed';
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['field'] = 'field_playbox_battle_completed_value';
  $handler->display->display_options['filters']['field_playbox_battle_completed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_title'] = 'List of Completed Battles';
  $handler->display->display_options['pane_description'] = 'A list of the completed playbox battles';
  $handler->display->display_options['pane_category']['name'] = 'Battles';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';

  /* Display: Featured Battle */
  $handler = $view->new_display('panel_pane', 'Featured Battle', 'playbox_battles_featured_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Featured view of a random battle';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['pane_title'] = 'Featured Battle';
  $handler->display->display_options['pane_description'] = 'This is a random featured battle';
  $handler->display->display_options['pane_category']['name'] = 'Battles';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Grid of battlers */
  $handler = $view->new_display('panel_pane', 'Grid of battlers', 'playbox_battles_grid_1');
  $handler->display->display_options['display_description'] = 'Here is a big grid of all the combatants.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="text-center space-bottom">The Challengers</h2>';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="battler-title text-center">
[title]
</div>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait']['id'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_portrait']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_portrait']['alter']['text'] = '<div class="text-center">[field_playbox_portrait] </div>';
  $handler->display->display_options['fields']['field_playbox_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_playbox_portrait']['settings'] = array(
    'image_style' => 'playbox_portrait_normal',
    'image_link' => 'content',
  );
  /* Field: Content: Nickname */
  $handler->display->display_options['fields']['field_playbox_nickname']['id'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['table'] = 'field_data_field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['field'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_nickname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_nickname']['alter']['text'] = '<div class="battler-nickname text-center">[field_playbox_nickname] </div>';
  $handler->display->display_options['fields']['field_playbox_nickname']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'playbox_president' => 'playbox_president',
    'playbox_robot' => 'playbox_robot',
  );
  $handler->display->display_options['pane_title'] = 'All Participants Grid';
  $handler->display->display_options['pane_description'] = 'This is a view of all the participants';
  $handler->display->display_options['pane_category']['name'] = 'Battles';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['playbox_battles'] = $view;

  return $export;
}
