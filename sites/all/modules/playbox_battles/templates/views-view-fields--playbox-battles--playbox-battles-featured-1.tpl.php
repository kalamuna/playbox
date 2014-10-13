<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 *  - $view: The view in use.
 *  - $fields: an array of $field objects.
 *  - $row: The raw result object from the query, with all data it fetched.
 *
 *  @ingroup views_templates
 *
 */

// More semantic vars
$battle_name = $row->node_title;
$battle_bio = $row->field_field_playbox_battle_bio[0]['rendered'];

$president_portrait = $row->field_field_playbox_portrait[0]['rendered'];
$president_nickname = $row->field_field_playbox_nickname[0]['rendered'];
$president_votes = $options['president_votes'];

$robot_portrait = $row->field_field_playbox_portrait_1[0]['rendered'];
$robot_nickname = $row->field_field_playbox_nickname_1[0]['rendered'];
$robot_votes = $options['robot_votes'];
?>

<div class="panel-display battler-battle clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <section class="section">
    <div class="container">
      <div class="row">
        <div class="col-md-12 battler-header-area text-center">
          <div class="battler-battle-name">
            <h2><?php print render($battle_name); ?></h2>
          </div>
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
            <?php print render($president_portrait); ?>
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
            <?php print render($robot_portrait); ?>
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
