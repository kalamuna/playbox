<?php

/**
 * @file
 * Theme setting callbacks for playbox_theme (sub-theme of kalatheme.)
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function playbox_theme_form_system_theme_settings_alter(&$form, $form_state) {
  $form['logo']['logo_white'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Alternate logo'),
    '#default_value' => theme_get_setting('logo_white'),
    '#description'   => t("Path to the version of the logo to be used for larger screens and logo_bling."),
  );
}