<?php
/**
 * @file
 * Admin Settings form for Trump It!
 */
function playbox_trumpit_admin_settings() {
  $form['playbox_trumpit_phrases'] = array(
    '#type' => 'textarea',
    '#title' => t('A list of wonderful quotes from D.T.'),
    '#description' => t('This is the list of quotes of wonder and beauty from D.T. that will be used as a signature for each - randomly - decided battle.<br />Originally copied from "<strong><a target="_blank" href="http://www.usmagazine.com/celebrity-news/news/donald-trumps-craziest-quotes-the-2016-presidential-hopeful-speaks-201568">http://www.usmagazine.com/celebrity-news/news/donald-trumps-craziest-quotes-the-2016-presidential-hopeful-speaks-201568</a></strong>".'),
    '#default_value' => variable_get('playbox_trumpit_phrases', ''),
    '#required' => TRUE,
    '#rows' => 30,	
  );
  
  return system_settings_form($form);
}