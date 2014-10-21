<?php
/**
 * @file
 * playbox_scores.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function playbox_scores_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function playbox_scores_image_default_styles() {
  $styles = array();

  // Exported image style: stats_portrait.
  $styles['stats_portrait'] = array(
    'name' => 'stats_portrait',
    'label' => 'stats_portrait',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 33,
          'height' => 33,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
