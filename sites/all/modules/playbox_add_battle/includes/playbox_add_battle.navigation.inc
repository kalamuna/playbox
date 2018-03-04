<?php

/**
 * Create progress bar header.
 *
 * @file
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_get_header($form, &$form_state) {

  $form_state['stage'] = isset($form_state['stage']) ? $form_state['stage'] : 1;

  $form_stages = [
    'select_president' => 1,
    'select_robot' => 2,
    'battle_details' => 3,
  ];

  if (isset($form_stages[$form_state['stage']])) {
    $current_step = $form_stages[$form_state['stage']];
  }
  else {
    $current_step = 1;
  }

  // Variables for progress image handling.
  $form_state['selected_president'] = isset($form_state['multistep_values']['select_president']['el_presidente'])
    ? $form_state['multistep_values']['select_president']['el_presidente'] : 0;
  $form_state['selected_robot'] = isset($form_state['multistep_values']['select_robot']['tin_man'])
    ? $form_state['multistep_values']['select_robot']['tin_man'] : 0;

  // Presidents.
  if (isset($form_state['multistep_values']['select_president']['el_presidente'])) {
    $node = node_load($form_state['selected_president']);
    $president_portrait_uri = $node->field_playbox_portrait['und'][0]['uri'];
    $style = image_style_load('avatar');
    $derivative_uri = image_style_path($style['name'], $president_portrait_uri);
    // Make sure image style file gets generated if it doesn't exist yet.
    if (!file_exists($derivative_uri)) {
      image_style_create_derivative($style, $president_portrait_uri, $derivative_uri);
    }
    $form_state['president_path'] = file_create_url($derivative_uri);

    $form_state['president_alt'] = $node->title;
  }
  else {
    if ($form_state['stage'] == 'select_president') {
      $form_state['president_path'] = '/sites/all/modules/playbox_add_battle/images/president-placeholder-active.png';
      $form_state['president_alt'] = t('Select President');
    }
    else {
      $form_state['president_path'] = '/sites/all/modules/playbox_add_battle/images/president-placeholder-inactive.png';
      $form_state['president_alt'] = t('Select President');
    }
  }

  // Robots.
  if (isset($form_state['multistep_values']['select_robot']['tin_man'])) {
    $node = node_load($form_state['selected_robot']);
    $robot_portrait_uri = $node->field_playbox_portrait['und'][0]['uri'];
    $style = image_style_load('avatar');
    $derivative_uri = image_style_path($style['name'], $robot_portrait_uri);
    // Make sure image style file gets generated if it doesn't exist yet.
    if (!file_exists($derivative_uri)) {
      image_style_create_derivative($style, $robot_portrait_uri, $derivative_uri);
    }
    $form_state['robot_path'] = file_create_url($derivative_uri);

    $form_state['robot_alt'] = $node->title;
  }
  else {
    if ($form_state['stage'] == 'select_robot') {
      $form_state['robot_path'] = '/sites/all/modules/playbox_add_battle/images/robot-placeholder-active.png';
      $form_state['robot_alt'] = t('Select Robot');
    }
    else {
      $form_state['robot_path'] = '/sites/all/modules/playbox_add_battle/images/robot-placeholder-inactive.png';
      $form_state['robot_alt'] = t('Select Robot');
    }
  }

  // Details.
  if ($form_state['stage'] == 'battle_details') {
    $form_state['details_path'] = '/sites/all/modules/playbox_add_battle/images/details-placeholder-active.png';
    $form_state['details_alt'] = t('Enter Details');
  }
  else {
    $form_state['details_path'] = '/sites/all/modules/playbox_add_battle/images/details-placeholder-inactive.png';
    $form_state['details_alt'] = t('Enter Details');
  }

  $form_state['president_image'] = '<img src="' . $form_state['president_path'] . '" alt="' . $form_state['president_alt'] . '" />';
  $form_state['robot_image'] = '<img src="' . $form_state['robot_path'] . '" alt="' . $form_state['robot_alt'] . '" />';
  $form_state['details_image'] = '<img src="' . $form_state['details_path'] . '" alt="' . $form_state['details_alt'] . '" />';


  $stages = [
    1 => ['data' => $form_state['president_image'] . '<label>1 President</label>'],
    2 => ['data' => $form_state['robot_image'] . '<label>2 Robot</label>'],
    3 => ['data' => $form_state['details_image'] . '<label>3 Battle</label>']
  ];

  $stages[$current_step]['class'] = ['active'];

  $stages_list = theme('item_list', ['items' => $stages]);

  $form['header'] = [
    '#type' => 'fieldset',
    '#title' => '',
    '#value' => $stages_list,
  ];

  return $form;

}

/**
 * Next button functionality.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_move_to_next_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'select_president':
      return 'select_robot';
      break;

    case 'select_robot':
      return 'battle_details';
      break;
  }

}

/**
 * Previous button functionality.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function playbox_add_battle_move_to_previous_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'select_robot':
      return 'select_president';
      break;

    case 'battle_details':
      return 'select_robot';
      break;
  }

}