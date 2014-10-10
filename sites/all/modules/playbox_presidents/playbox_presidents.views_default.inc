<?php
/**
 * @file
 * playbox_presidents.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function playbox_presidents_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'playbox_presidents';
  $view->description = 'Contains the views for Playbox Presidents.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Playbox Presidents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presidents';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_playbox_portrait']['id'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['table'] = 'field_data_field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['field'] = 'field_playbox_portrait';
  $handler->display->display_options['fields']['field_playbox_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_playbox_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_playbox_portrait']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Nickname */
  $handler->display->display_options['fields']['field_playbox_nickname']['id'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['table'] = 'field_data_field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['field'] = 'field_playbox_nickname';
  $handler->display->display_options['fields']['field_playbox_nickname']['label'] = '';
  $handler->display->display_options['fields']['field_playbox_nickname']['element_label_colon'] = FALSE;
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
    'playbox_president' => 'playbox_president',
  );

  /* Display: President Grid */
  $handler = $view->new_display('panel_pane', 'President Grid', 'playbox_president_grid_1');
  $handler->display->display_options['display_description'] = 'A responsive grid of presidents. ';
  $handler->display->display_options['pane_title'] = 'Preident Grid';
  $handler->display->display_options['pane_description'] = 'A responsive grid of presidents.';
  $handler->display->display_options['pane_category']['name'] = 'Presidents';
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

  /* Display: President Header */
  $handler = $view->new_display('panel_pane', 'President Header', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'This shows a nice header for the presidents page.';
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
    'image_style' => '',
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
          <h2>The Presidents</h2>
          Andrew Jackson beat a would be assailant senseless to the ground on the White House Grounds. Teddy Roosevelt got shot during a speech and ... then finished the speech. Ronald Reagan broke Tecumseh\'s Curse. These guys mean serious business. 
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
  $handler->display->display_options['pane_title'] = 'Presidents Header';
  $handler->display->display_options['pane_description'] = 'This is a nice little header to describe the presidents.';
  $handler->display->display_options['pane_category']['name'] = 'Presidents';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['playbox_presidents'] = $view;

  return $export;
}
