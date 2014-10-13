<?php
/**
 * @file
 * Include that provides a bookshare searchable pane
 */

// CONSTANTS
define('PLAYBOX_STATIC_DEFAULT_KALAMUNA', '<div class="container"><div class="row"><div class="col-md-12"><h2>Seriously though... WTF is this?</h2></div></div><div class="row"><div class="col-md-4 text-center"><img src="http://identity.kalamuna.com/images/assets/logo_horizontal_tagline.png" alt="Kalamuna, Let\'s Play!"></div><div class="col-md-8"><p class="space-top">Playbox! is a sandbox-proving-ground for people interested in working with us here at Kalamuna. It\'s a magnificent and collaborative code-garden where would-be code artists, site builder and designers alike can play around and show what they\'ve got. Think you\'ve got what it takes?</p><a href="https://github.com/kalamuna/playbox" class="btn btn-success btn-lg" role="button">Then give it shot!</a></div></div>');

$plugin = array(
  'single' => TRUE,
  'title' => t('Kalamuna Pane'),
  'description' => t('WTF this is!'),
  'category' => t('Playbox Static Panes'),
  'edit form' => 'playbox_static_kalamuna_edit_form',
  'render callback' => 'playbox_static_kalamuna_render',
  'defaults' => array(
    'kalamuna_html' => PLAYBOX_STATIC_DEFAULT_KALAMUNA,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function playbox_static_kalamuna_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['kalamuna_html'] = array(
    '#title' => t('HTML for the Kalamuna things'),
    '#description' => t('THIS IS WHAT THIS IS!'),
    '#type' => 'textarea',
    //'#format' => 'panopoly_html_text',
    '#required' => FALSE,
    '#default_value' => ($conf['kalamuna_html'] != PLAYBOX_STATIC_DEFAULT_KALAMUNA) ? $conf['kalamuna_html'] : PLAYBOX_STATIC_DEFAULT_KALAMUNA,
  );

  return $form;
}

/**
 * Make sure our custom stuff is being saved
 */
function playbox_static_kalamuna_edit_form_submit(&$form, &$form_state) {
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
function playbox_static_kalamuna_render($subtype, $conf, $args, $contexts) {

  // Update the strings to allow contexts.
  $content = ($conf['kalamuna_html'] != PLAYBOX_STATIC_DEFAULT_KALAMUNA) ? $conf['kalamuna_html'] : PLAYBOX_STATIC_DEFAULT_KALAMUNA;

  $block = new stdClass();
  $block->title = t('');
  $block->content = $content;

  return $block;
}
