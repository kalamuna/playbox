<?php
/**
 * @file
 * Primary pre/preprocess functions and alterations.
 */

/**
 * Override or insert variables into the page template.
 *
 * Implements template_process_page().
 */
function playbox_theme_process_page(&$variables) {
  // Add Bootstrap JS and stock CSS.
  global $base_url;
  $base = parse_url($base_url);
  // Use the CDN if not using libraries
  if (!kalatheme_use_libraries()) {
    $library = theme_get_setting('bootstrap_library');
    if ($library !== 'none' && !empty($library)) {
      // Add the JS
      drupal_add_js($base['scheme'] . ":" . KALATHEME_BOOTSTRAP_JS, 'external');
      // Add the CSS
      $css = ($library === 'default') ? KALATHEME_BOOTSTRAP_CSS : kalatheme_get_bootswatch_theme($library)->cssCdn;
      drupal_add_css($base['scheme'] . ":" . $css, 'external');
    }
  }
  // Use Font Awesome
  if (theme_get_setting('fontawesome')) {
    drupal_add_css($base['scheme'] . ":" . KALATHEME_FONTAWESOME_CSS, 'external');
  }

  // Define variables to theme local actions as a dropdown.
  $dropdown_attributes = array(
    'container' => array(
      'class' => array('dropdown', 'actions', 'pull-right'),
    ),
    'toggle' => array(
      'class' => array('dropdown-toggle', 'enabled'),
      'data-toggle' => array('dropdown'),
      'href' => array('#'),
    ),
    'content' => array(
      'class' => array('dropdown-menu'),
    ),
  );

  // Add local actions as the last item in the local tasks.
  if (!empty($variables['action_links'])) {
    $variables['tabs']['#primary'][]['#markup'] = theme('menu_local_actions', array('menu_actions' => $variables['action_links'], 'attributes' => $dropdown_attributes));
    $variables['action_links'] = FALSE;
  }

  // Get the entire main menu tree.
  $right_menu_tree = array();
  $right_menu_tree = menu_tree_all_data('menu-right-main-menu', NULL, 2);
  $left_menu_tree = array();
  $left_menu_tree = menu_tree_all_data('menu-left-main-menu', NULL, 2);
  // Add the rendered output to the ${left|right}_menu_expanded variable.
  $variables['left_menu_expanded'] = menu_tree_output($left_menu_tree);
  $variables['right_menu_expanded'] = menu_tree_output($right_menu_tree);
  $variables['main_menu'] = $left_menu_tree & $right_menu_tree;

  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty,
    // so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using title_prefix and title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

  // If panels arent being used at all.
  $variables['no_panels'] = !(module_exists('page_manager') && page_manager_get_current_page());

  // Check if we're to always print the page title, even on panelized pages.
  $variables['always_show_page_title'] = theme_get_setting('always_show_page_title') ? TRUE : FALSE;
  
  // Add js variable for path for the logo & alt logo that we will need on larger screens & alt screens.
  drupal_add_js('jQuery.extend(Drupal.settings, { "logo_white": "' . theme_get_setting('logo_white') . '" });', 'inline');
  drupal_add_js('jQuery.extend(Drupal.settings, { "logo": "' . theme_get_setting('logo') . '" });', 'inline');
  
}
