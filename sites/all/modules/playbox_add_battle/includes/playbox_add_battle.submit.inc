<?php

/**
 * Form submit.
 *
 * @file
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_form_submit($form, &$form_state) {

  switch ($form_state['stage']) {

    case 'battle_details':
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      if ($form_state['triggering_element']['#value'] != 'Back') {
        playbox_add_battle_battle_details_submit($form, $form_state);
        $node_link = $form_state['destination'];
        $form_state['complete'] = TRUE;
      }
     break;

    default:
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      $form_state['new_stage'] = playbox_add_battle_move_to_next_stage($form, $form_state);
     break;

  }

  if (isset($form_state['complete'])) {
    drupal_goto($node_link);
  }

  if ($form_state['triggering_element']['#value'] == 'Back') {
    $form_state['new_stage'] = playbox_add_battle_move_to_previous_stage($form, $form_state);
  }

  if (isset($form_state['multistep_values']['form_build_id'])) {
    $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }
  $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
  $form_state['stage'] = $form_state['new_stage'];
  $form_state['rebuild'] = TRUE;

}

/**
 * Create a battle node and pupulate fields with submitted values.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_battle_details_submit($form, &$form_state) {

  // Create a new node object.
  $node = new stdClass();
  $node->type = 'playbox_battle';
  $node->language = LANGUAGE_NONE;

  // Pass gathered values to new node's fields.
  $node->title = $form_state['values']['battle_name'];
  $node->field_playbox_battle_bio[LANGUAGE_NONE][0]['value'] = $form_state['values']['battle_description'];
  $node->field_playbox_votes_to_win[LANGUAGE_NONE][0]['value'] = $form_state['values']['battle_votes_to_win'];
  $node->field_playbox_president[$node->language][]['target_id'] = $form_state['multistep_values']['select_president']['el_presidente'];
  $node->field_playbox_president[$node->language][]['target_type'] = 'node';
  $node->field_playbox_robot[$node->language][]['target_id'] = $form_state['multistep_values']['select_robot']['tin_man'];
  $node->field_playbox_robot[$node->language][]['target_type'] = 'node';

  // Set node to Published.
  $node->status = 1;

  // Save the node.
  node_save($node);

  // Capture path of new node.
  $internal_path = 'node/' . $node->nid;
  // Set destination to human-friendly path alias.
  $form_state['destination'] = drupal_get_path_alias($internal_path);

}