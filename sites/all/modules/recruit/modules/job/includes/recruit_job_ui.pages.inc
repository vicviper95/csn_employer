<?php

/**
 * @file
 * Page callbacks functions for Job UI module.
 */

function recruit_job_ui_view_page($job) {
  //Load css.
  #drupal_add_css(drupal_get_path('module', 'recruit_job') . '/theme/recruit-job.css');

  //Set page title.
  drupal_set_title(check_plain($job->title));

  return theme('recruit_job', array('job' => $job, 'view_mode' => 'full'));
}

function recruit_job_ui_admin_view_page($job) {
  return theme('recruit_job', array('job' => $job, 'view_mode' => 'admin'));
}