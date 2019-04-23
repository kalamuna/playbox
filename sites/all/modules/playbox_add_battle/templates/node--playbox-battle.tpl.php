<?php

/**
 * @file
 * Playbox theme implementation to display a node of type playbox_battle.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */

// Set variables
$battle_name = $node->title;
$battle_bio = $node->field_playbox_battle_bio['und'][0]['value'];
$president_portrait_path = $node->field_playbox_president['und'][0]['entity']->field_playbox_portrait['und'][0]['uri'];
$president_portrait = image_style_url('playbox_portrait_featured', $president_portrait_path);
$president_name = $node->field_playbox_president['und'][0]['entity']->title;
$president_nickname = $node->field_playbox_president['und'][0]['entity']->field_playbox_nickname['und'][0]['value'];
$president_votes = $options['president_votes'];
$robot_portrait_path = $node->field_playbox_robot['und'][0]['entity']->field_playbox_portrait['und'][0]['uri'];
$robot_portrait = image_style_url('playbox_portrait_featured', $robot_portrait_path);
$robot_name = $node->field_playbox_robot['und'][0]['entity']->title;
$robot_nickname = $node->field_playbox_robot['und'][0]['entity']->field_playbox_nickname['und'][0]['value'];
$robot_votes = $options['robot_votes'];

?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="panel-display battler-battle clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
        <section class="section">
            <div class="container">
                <div class="row">
                    <div class="col-md-12 battler-header-area text-center">
                        <div class="battler-battle-bio">
                          <?php print render($battle_bio); ?>
                        </div>
                    </div>
                </div>
            </div>
        </section>
        <section class="section battler-vs">
            <div class="container">
                <div class="row">
                    <div class="col-md-5 battler-column-content-region-1 text-center">
                        <div <?php print drupal_attributes($options['president_attributes']); ?>>
                          <img class="playbox-portrait-featured" src="<?php print $president_portrait; ?>" alt="<?php print render($president_name); ?>" />
                          <?php print render($president_votes); ?>
                        </div>
                        <div class="battler-nickname">
                          <?php print render($president_nickname); ?>
                        </div>
                    </div>
                    <div class="col-md-2 battler-column-content-region-2 text-center">
                        <div class="battler-vs-label">VS</div>
                    </div>
                    <div class="col-md-5 battler-column-content-region-3 text-center">
                        <div <?php print drupal_attributes($options['robot_attributes']); ?>>
                            <img class="playbox-portrait-featured" src="<?php print $robot_portrait; ?>" alt="<?php print render($robot_name); ?>" />
                          <?php print render($robot_votes); ?>
                        </div>
                        <div class="battler-nickname">
                          <?php print render($robot_nickname); ?>
                        </div>
                    </div>
                </div>
            </div>
        </section>
    </div><!-- /.battler -->
</article>
