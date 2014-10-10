<?php
/**
 * @file
 * Include that provides a bookshare searchable pane
 */

// CONSTANTS
define('PLAYBOX_STATIC_DEFAULT_FOOTER', '&copy; 2014 Kalamuna LLC');

$plugin = array(
  'single' => TRUE,
  'title' => t('Playbox Footer'),
  'description' => t('A generic footer for Playbox.'),
  'category' => t('Playbox Static Panes'),
  'edit form' => 'playbox_static_footer_edit_form',
  'render callback' => 'playbox_static_footer_render',
  'defaults' => array(
    'footer_html' => PLAYBOX_STATIC_DEFAULT_FOOTER,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function playbox_static_footer_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['footer_html'] = array(
    '#title' => t('HTML for footer'),
    '#description' => t('Playbox footer'),
    '#type' => 'textarea',
    //'#format' => 'panopoly_html_text',
    '#required' => FALSE,
    '#default_value' => ($conf['footer_html'] != PLAYBOX_STATIC_DEFAULT_FOOTER) ? $conf['footer_html'] : PLAYBOX_STATIC_DEFAULT_FOOTER,
  );

  return $form;
}

/**
 * Make sure our custom stuff is being saved
 */
function playbox_static_footer_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function playbox_static_footer_render($subtype, $conf, $args, $contexts) {

  // Update the strings to allow contexts.
  $content = ($conf['footer_html'] != playbox_static_DEFAULT_SEARCH_FORM) ? $conf['footer_html'] : playbox_static_DEFAULT_SEARCH_FORM;

  $block = new stdClass();
  $block->title = t('');
  $block->content = $content;

  return $block;
}
