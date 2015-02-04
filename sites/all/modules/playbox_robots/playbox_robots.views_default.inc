<?php
/**
 * @file
 * playbox_robots.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function playbox_robots_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'playbox_robots';
  $view->description = 'Contains the views for Playbox Robots.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Playbox Robots';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="battler-title text-center">
[title]
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait']['id'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['label'] = '';
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
  $handler->display->display_options['fields']['field_playbox_nickname']['alter']['text'] = '<div class="battler-nickname text-center">
[field_playbox_nickname] 
</div>';
  $handler->display->display_options['fields']['field_playbox_nickname']['element_label_colon'] = FALSE;
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
    'playbox_robot' => 'playbox_robot',
  );

  /* Display: Robot Grid */
  $handler = $view->new_display('panel_pane', 'Robot Grid', 'playbox_robot_grid_1');
  $handler->display->display_options['display_description'] = 'A responsive grid of robots. ';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="text-center space-bottom">The Robots</h2>';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['pane_title'] = 'Robot Grid';
  $handler->display->display_options['pane_description'] = 'A responsive grid of robots.';
  $handler->display->display_options['pane_category']['name'] = 'Robots';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';

  /* Display: Robot Header */
  $handler = $view->new_display('panel_pane', 'Robot Header', 'playbox_robot_header_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait']['id'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_portrait']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_playbox_portrait']['settings'] = array(
    'image_style' => 'playbox_portrait_featured',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '
    <div class="container">
      <div class="row">
        <div class="col-md-4 battler-rows-sidebar-area">
          [field_playbox_portrait]
        </div>
        <div class="col-md-8 battler-rows-main-content">
          <h2>The Robots</h2>
          In the year 20XX robots reign supreme. Metal Man, Air Man, Mega Man... all bring skills and precision to the table. Can the innovation and creative of Humanity thwart this new, cold and efficient menace or will iron, copper and AI carry the day?
        </div>
      </div>
    </div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'playbox_robot' => 'playbox_robot',
  );
  $handler->display->display_options['pane_title'] = 'Robot Header';
  $handler->display->display_options['pane_description'] = 'A nice little header for the robots';
  $handler->display->display_options['pane_category']['name'] = 'Robots';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Featured Robot */
  $handler = $view->new_display('panel_pane', 'Featured Robot', 'playbox_robot_featured_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'A randomly selected robot';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="text-center">Robotic Spotlight</h2>';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait']['id'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_portrait']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_portrait']['alter']['text'] = '<p class="text-center play-spot-portrait space-bottom">[field_playbox_portrait]</p>';
  $handler->display->display_options['fields']['field_playbox_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_playbox_portrait']['settings'] = array(
    'image_style' => 'playbox_portrait_featured',
    'image_link' => 'content',
  );
  /* Field: Content: Bio */
  $handler->display->display_options['fields']['field_playbox_bio']['id'] = 'field_playbox_bio';
  $handler->display->display_options['fields']['field_playbox_bio']['table'] = 'field_data_field_playbox_bio';
  $handler->display->display_options['fields']['field_playbox_bio']['field'] = 'field_playbox_bio';
  $handler->display->display_options['fields']['field_playbox_bio']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_playbox_bio']['alter']['text'] = '<p class="text-center play-spot-bio">[field_playbox_bio]</p>';
  $handler->display->display_options['fields']['field_playbox_bio']['element_label_colon'] = FALSE;
  /* Field: Content: Powers */
  $handler->display->display_options['fields']['field_playbox_powers']['id'] = 'field_playbox_powers';
  $handler->display->display_options['fields']['field_playbox_powers']['table'] = 'field_data_field_playbox_powers';
  $handler->display->display_options['fields']['field_playbox_powers']['field'] = 'field_playbox_powers';
  $handler->display->display_options['fields']['field_playbox_powers']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_powers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_powers']['type'] = 'playbox_core_feature_formatter';
  $handler->display->display_options['fields']['field_playbox_powers']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['pane_title'] = 'Featured Robot';
  $handler->display->display_options['pane_description'] = 'A randomly selected robot';
  $handler->display->display_options['pane_category']['name'] = 'Robots';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['playbox_robots'] = $view;

  return $export;
}
