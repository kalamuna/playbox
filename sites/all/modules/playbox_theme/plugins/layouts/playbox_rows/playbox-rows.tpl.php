<?php
/**
 * @file
 * Template for Playbox Rows.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<?php if ($content['jumbotron']): ?>
  <header id="home" class="jumbotron">
    <div class="container">
      <div class="row">
        <?php print $content['jumbotron']; ?>
      </div>
    </div>
  </header>
<?php endif; ?>

<?php if ($content['row1']): ?>
  <section id="services" class="white-bg padding-top-bottom">
    <div class="container">
      <?php print $content['row1']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['row2']): ?>
  <section id="feat-project" class="gray-bg padding-top-bottom">
    <div class="container">
      <?php print $content['row2']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['row3']): ?>
  <section id="about" class="dark-bg light-typo padding-top-bottom">
    <div class="container">
      <?php print $content['row3']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['row4']): ?>
  <section id="skills" class="white-bg padding-top-bottom">
    <div class="container">
      <?php print $content['row4']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['row5']): ?>
  <section id="portfolio" class="gray-bg padding-top-bottom">
    <div class="container">
      <?php print $content['row5']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['row6']): ?>
  <section id="dribbble">
    <?php print $content['row6']; ?>
  </section>
<?php endif; ?>

<?php if ($content['row7']): ?>
  <section id="contact" class="dark-bg light-typo padding-top-bottom">
    <div class="container">
      <?php print $content['row7']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['footer']): ?>
  <footer id="main-footer" class="dark-bg light-typo">
    <div class="container">
      <?php print $content['footer']; ?>
    </div>
  </footer>
<?php endif; ?>
<!-- /.playbox_rows -->
