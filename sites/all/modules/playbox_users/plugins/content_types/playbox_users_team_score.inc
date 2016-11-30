<?php
/**
 * @file
 * Include that provides a playbox team score pane
 */


$plugin = array(
  'single' => TRUE,
  'title' => t('President Score Pane'),
  'description' => t('Displays team score for presidents'),
  'category' => t('Presidents'),
  'edit form' => 'playbox_users_president_score_edit_form',
  'render callback' => 'playbox_users_president_score_render',
  'defaults' => array(
    'presidents_html' => PLAYBOX_USERS_DEFAULT_PRESIDENT_SCORE,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function playbox_users_president_score_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['presidents_score'] = array(
    '#title' => t('Presidents Score'),
    '#description' => t('THIS IS WHAT THIS IS!'),
    '#type' => 'textarea',
    //'#format' => 'panopoly_html_text',
    '#required' => FALSE,
    '#default_value' => ($conf['presidents_score'] != PLAYBOX_USERS_DEFAULT_PRESIDENT_SCORE) ? $conf['presidents_score'] : PLAYBOX_USERS_DEFAULT_PRESIDENT_SCORE,
  );

  return $form;
}

/**
 * Make sure our custom stuff is being saved
 */
function playbox_users_president_score_edit_form_submit(&$form, &$form_state) {
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
function playbox_users_president_score_render($subtype, $conf, $args, $contexts) {

  $content = $conf['playbox_users_get_score'];

  $block = new stdClass();
  $block->title = t('');
  $block->content = $content;

  return $block;
}

/**
 * Return a count of playbox_battle nodes where the given type is listed as the
 * winner.
 */
function playbox_users_get_score($bundle = NULL){
  // Get all the playbox_battle nodes. To future proof this from performance
  // issues when there are lots of playbox_battle nodes I would suggest adding
  // an extra--albeit redundant--field that stores the content type of the
  // winner. This way we could use EFQ more effectively without having to load
  // all the battle nodes.
  $type = 'node';
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $type)
    ->entityCondition('bundle', 'playbox_battle');

  $result = $query->execute();

  if (isset($result[$type])) {
    // There are playbox_battle nodes--load them.
    $nodes = node_load_multiple(array_keys($result[$type]));
    $scores = array(
      'playbox_president' => 0,
      'playbox_robot' => 0,
    );
    foreach ($nodes as $nid => $node) {
      // Grab the referenced winner node and increment a counter for that type.
      $wrapper = entity_metadata_wrapper('node', $node);
      $winner_node = $wrapper->field_playbox_winner->value();
      if ($winner_node) {
        $scores[$winner_node->type]++;
      }
    }

    // If $type was passed then return the score for that type, otherwise return
    // the array containing both which can be used with list().
    return $bundle ? $scores[$bundle] : $scores;
  }
}

