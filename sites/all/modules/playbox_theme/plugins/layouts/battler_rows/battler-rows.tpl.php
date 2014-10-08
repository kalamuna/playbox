<?php
/**
 * @file
 * Template for Battler Rows.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<?php if ($content['core'] || $content['des'] ): ?>
  <header id="home" class="jumbotron">
    <div class="container">
      <div class="row">
        <div class="col-md-4 battler-rows-sidebar-area">
          <?php print $content['core']; ?>
        </div>
        <div class="col-md-8 battler-rows-main-content">
          <?php print $content['des']; ?>
        </div>
      </div>
    </div>
  </header>
<?php endif; ?>

<?php if ($content['powers']): ?>
  <section id="powers" class="white-bg padding-top-bottom">
    <div class="container">
      <?php print $content['powers']; ?>
    </div>
  </section>
<?php endif; ?>

<?php if ($content['footer']): ?>
  <footer id="main-footer" class="dark-bg light-typo">
    <div class="container">
      <div class="col-md-12 battler-rows-footer-area">
        <?php print $content['footer']; ?>
      </div>
    </div>
  </footer>
<?php endif; ?>
<!-- /.battler_rows -->
