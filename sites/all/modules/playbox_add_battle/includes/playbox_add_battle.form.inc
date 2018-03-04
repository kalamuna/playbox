<?php
/**
 * @file
 * Handles the form elements of the add battle form
 * All hooks are in the .module file.
 */
/**
 * Master form which calls an individual form for each step.
 *
 * @see playbox_add_battle_form_validate().
 * @see playbox_add_battle_form_submit().
 *
 * @param type $form
 * @param string $form_state
 * @return type
 */
function playbox_add_battle_form($form, &$form_state) {

  if (!isset($form_state['stage'])) $form_state['stage'] = 'select_president';

  $form = [];
  $form = playbox_add_battle_get_header($form, $form_state);
  switch ($form_state['stage']) {

    case 'select_president':
      return playbox_add_battle_select_president_form($form, $form_state);
      break;

    case 'select_robot':
      return playbox_add_battle_select_robot_form($form, $form_state);
      break;

    case 'battle_details':
      return playbox_add_battle_battle_details_form($form, $form_state);
      break;

    default:
      return playbox_add_battle_select_president_form($form, $form_state);
      break;
  }

  return $form;

}
/**
 * Form for the select_president step.
 *
 * @see playbox_add_battle_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_select_president_form($form, &$form_state) {

  $node_type = 'playbox_president';

  $result = playbox_add_battle_get_presidents_robots($node_type);

  $options = playbox_add_battle_create_options($result);

  $values = isset($form_state['multistep_values']['select_president']) ? $form_state['multistep_values']['select_president'] : [];

  $form['select_president']['el_presidente'] = [
    '#type' => 'radios',
    '#title' => '1 Select a President who kicks robot ass',
    '#options' => $options,
    '#default_value' => isset($values['el_presidente']) ? $values['el_presidente'] : NULL
  ];

  $form['next'] = [
    '#type' => 'submit',
    '#value' => t('Next'),
    '#attributes' => ['class' => ['btn', 'btn-primary']]
  ];

  return $form;
}
/**
 * Form for the select_robot step.
 *
 * @see playbox_add_battle_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_select_robot_form($form, &$form_state) {

  $node_type = 'playbox_robot';

  $result = playbox_add_battle_get_presidents_robots($node_type);

  $options = playbox_add_battle_create_options($result);

  $values = isset($form_state['multistep_values']['select_robot']) ? $form_state['multistep_values']['select_robot'] : [];

  $form['select_robot']['tin_man'] = [
    '#type' => 'radios',
    '#title' => '2 Select a robot contender',
    '#options' => $options,
    '#default_value' => isset($values['tin_man']) ? $values['tin_man'] : NULL
  ];

  $form['back'] = [
    '#type' => 'submit',
    '#value' => t('Back'),
    '#attributes' => ['class' => ['btn', 'btn-secondary']]
  ];

  $form['next'] = [
    '#type' => 'submit',
    '#value' => t('Next'),
    '#attributes' => ['class' => ['btn', 'btn-primary']]
  ];

  return $form;
}

/**
 * Form for the battle_details step.
 *
 * @see playbox_add_battle_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_battle_details_form($form, &$form_state) {
  $values = isset($form_state['multistep_values']['battle_details']) ? $form_state['multistep_values']['battle_details'] : [];
  $form['battle_details']['battle_name'] = [
    '#type' => 'textfield',
    '#title' => 'Battle Name',
    '#default_value' => isset($values['battle_name']) ? $values['battle_name'] : NULL
  ];

  $form['battle_details']['battle_description'] = [
    '#type' => 'textfield',
    '#title' => 'Description',
    '#default_value' => isset($values['battle_description']) ? $values['battle_description'] : NULL
  ];

  $form['battle_details']['battle_votes_to_win'] = [
    '#type' => 'textfield',
    '#title' => 'Number of votes needed to win',
    '#default_value' => isset($values['battle_votes_to_win']) ? $values['battle_votes_to_win'] : NULL,
    '#element_validate' => ['element_validate_integer_positive']
  ];

  $form['back'] = [
    '#type' => 'submit',
    '#value' => t('Back'),
    '#attributes' => ['class' => ['btn', 'btn-secondary']]
  ];

  $form['next'] = [
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#attributes' => ['class' => ['btn', 'btn-primary']]
  ];

  return $form;
}