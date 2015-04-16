<?php
/*
 * Copy this file to local.settings.php in order to override configuration within settings.php
 * local.settings.php is ignored by git and not deployed to Pantheon
 */
 $databases['default']['default'] = array(
	'driver' => 'mysql',
	'database' => 'kalamuna_playbox',
	'username' => 'root',
	'password' => 'root',
	'host' => 'localhost',
  'port' => '8889',
	'prefix' => '',
);

$update_free_access = TRUE;


$base_url = 'http://'.$_SERVER['HTTP_HOST'].'/kalamuna/playbox'; // NO trailing slash!
$cookie_domain = $_SERVER['HTTP_HOST'];

#disables Drupal Caching if desired
/*$conf = array(
	'cache' => '0',
	'preprocess_css' => '0',
	'preprocess_js' => '0',
	'block_cache' => '0',
	'page_compression' => '0',
);*/

ini_set('memory_limit', '500M');
ini_set('max_execution_time', 300);
