<?php
/**
 * @file
 * Include that provides a bookshare searchable pane
 */

// CONSTANTS
define('PLAYBOX_STATIC_DEFAULT_INSTRUCTIONS', ' <div class="container"><div class="row"><div class="col-md-12"><h2>So, how does this work?</h2><p>You need to vote on who would win in a fight: A president or a Megaman boss. The first player to the predetermined vote total is named the winner. You should consider the following factors:</p></div><div class="row"><div class="col-md-3 text-center"><i class="fa fa-bomb fa-5x space-bottom space-top"></i><h3>Explosiveness</h3><small>Everyone has an x-factor.</small></div><div class="col-md-3 text-center"><i class="fa fa-crosshairs fa-5x space-bottom space-top"></i><h3>Precision</h3><small>Doing the most with the least.</small></div><div class="col-md-3 text-center"><i class="fa fa-heart fa-5x space-bottom space-top"></i><h3>Passion</h3><small>Love and determination conquer all.</small></div><div class="col-md-3 text-center"><i class="fa fa-flask fa-5x space-bottom space-top"></i><h3>Logic</h3><small>Shrewd, cold, mechanic calculus.</small></div></div><div class="row"><div class="col-md-12 text-center space-top"><a href="battles" class="btn btn-success btn-lg" role="button">Check out the battles!</a></div></div>');

$plugin = array(
  'single' => TRUE,
  'title' => t('Playbox Instructions'),
  'description' => t('Instructions for the Playbox.'),
  'category' => t('Playbox Static Panes'),
  'edit form' => 'playbox_static_instructions_edit_form',
  'render callback' => 'playbox_static_instructions_render',
  'defaults' => array(
    'instructions_html' => PLAYBOX_STATIC_DEFAULT_INSTRUCTIONS,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function playbox_static_instructions_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['instructions_html'] = array(
    '#title' => t('HTML for the instructions'),
    '#description' => t('Playbox instructions'),
    '#type' => 'textarea',
    //'#format' => 'panopoly_html_text',
    '#required' => FALSE,
    '#default_value' => ($conf['instructions_html'] != PLAYBOX_STATIC_DEFAULT_INSTRUCTIONS) ? $conf['instructions_html'] : PLAYBOX_STATIC_DEFAULT_INSTRUCTIONS,
  );

  return $form;
}

/**
 * Make sure our custom stuff is being saved
 */
function playbox_static_instructions_edit_form_submit(&$form, &$form_state) {
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
function playbox_static_instructions_render($subtype, $conf, $args, $contexts) {

  // Update the strings to allow contexts.
  $content = ($conf['instructions_html'] != PLAYBOX_STATIC_DEFAULT_INSTRUCTIONS) ? $conf['instructions_html'] : PLAYBOX_STATIC_DEFAULT_INSTRUCTIONS;

  $block = new stdClass();
  $block->title = t('');
  $block->content = $content;

  return $block;
}
