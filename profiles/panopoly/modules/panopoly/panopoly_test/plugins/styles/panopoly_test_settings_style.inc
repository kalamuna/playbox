<?php

/**
 * @file
 * Definition of the 'rounded_corners' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Panopoly Test: Style with settings'),
  'description' => t('Pane style to ensure Panopoly Magic does not disrupt style forms.'),
  'render region' => 'panopoly_test_settings_style_style_render_region',
  'render pane' => 'panopoly_test_settings_style_render_pane',
  'settings form' => 'panopoly_test_settings_style_style_settings_form',
  'pane settings form' => 'panopoly_test_settings_style_style_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panopoly_test_settings_style_style_render_region($vars) {
  $output = '';
//  $output .= '<div class="region region-' . $vars['region_id'] . '">';
  $output .= implode('<div class="panel-separator"></div>', $vars['panes']);
//  $output .= '</div>';
  return $output;
}

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panopoly_test_settings_style_render_pane($vars) {
  return render($vars['content']->content);
}

/**
 * Settings form callback.
 */
function panopoly_test_settings_style_style_settings_form($style_settings) {
  $form['corner_location'] = array(
    '#type' => 'select',
    '#title' => t('Generic setting select'),
    '#options' => array(
      'pane' => t('Generic option one'),
      'panel' => t('Generic opton two'),
    ),
  );

  return $form;
}
