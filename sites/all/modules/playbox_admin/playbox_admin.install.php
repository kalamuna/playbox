<?php
/** 
 * Install file for playbox_admin
 */

function playbox_admin_uninstall() {
	variable_del('playbox_admin_president');
	variable_del('playbox_admin_boss');
	variable_del('playbox_admin_color');
	variable_del('playbox_admin_disco');
}