<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 *  - $view: The view in use.
 *  - $fields: an array of $field objects. Each one contains:
 *  - $field->content: The output of the field.
 *  - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *  - $field->class: The safe class id to use.
 *  - $field->handler: The Views field handler object controlling this field. Do not use
 *    var_export to dump this object, as it can't handle the recursion.
 *  - $field->inline: Whether or not the field should be inline.
 *  - $field->inline_html: either div or span based on the above flag.
 *  - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *  - $field->wrapper_suffix: The closing tag for the wrapper.
 *  - $field->separator: an optional separator that may appear before a field.
 *  - $field->label: The wrap label text to use.
 *  - $field->label_html: The full HTML of the label to use including
 *    configured element type.
 *  - $row: The raw result object from the query, with all data it fetched.
 *
 *  @ingroup views_templates
 *
 */
?>

<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php /*
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>
*/


?>

<div class="panel-display battler clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <section class="section">
    <div class="container">
      <div class="row">
        <div class="col-md-12 battler-header-area">
          <?php $row = $row; ?>
          <?php $fields = $row; ?>
          <?php $view = $view; ?>
        </div>
      </div>
    </div>
  </section>
  <section class="section">
    <div class="container">
      <div class="row">
        <div class="col-md-5 battler-column-content-region-1">
        </div>
        <div class="col-md-2 battler-column-content-region-2">
        </div>
        <div class="col-md-5 battler-column-content-region-3">
        </div>
      </div>
    </div>
  </section>
  <footer class="section" id="footer">
    <div class="container">
      <div class="row">
        <div class="col-md-12 battler-footer-area">
        </div>
      </div>
    </div>
  </footer>
</div><!-- /.battler -->
