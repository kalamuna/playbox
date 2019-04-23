<?php

/**
 * Validation.
 *
 * @file
 */
function playbox_add_battle_form_validate($form, &$form_state) {

  if ($form_state['triggering_element']['#value'] == 'Back') {
    return;
  }

  switch ($form_state['stage']) {

    case 'select_president':
      return playbox_add_battle_select_president_validate($form, $form_state);
      break;

    case 'select_robot':
      return playbox_add_battle_select_robot_validate($form, $form_state);
      break;

    case 'battle_details':
      return playbox_add_battle_battle_details_validate($form, $form_state);
      break;

  }
}

/**
 * Validation for Select President form step.
 */
function playbox_add_battle_select_president_validate($form, $form_state) {
  if ($form_state['values']['el_presidente'] == '') {
    form_set_error('el_presidente', t('You must select a president.'));
  }
}

/**
 * Validation for Select Robot form step.
 */
function playbox_add_battle_select_robot_validate($form, $form_state) {
  if ($form_state['values']['tin_man'] == '') {
    form_set_error('tin_man', t('You must select a robot.'));
  }
}

/**
 * Validation for Battle Details form step.
 */
function playbox_add_battle_battle_details_validate($form, $form_state) {
  if ($form_state['values']['battle_name'] == '') {
    form_set_error('battle_name', t('You must give this battle a name.'));
  }
  if ($form_state['values']['battle_description'] == '') {
    form_set_error('battle_description', t('You must provide a description of this battle.'));
  }
  if ($form_state['values']['battle_votes_to_win'] == '') {
    form_set_error('battle_votes_to_win', t('You must provide the number of votes needed to win battle.'));
  }
}