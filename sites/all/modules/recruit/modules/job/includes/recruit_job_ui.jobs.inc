<?php

/**
 * @file
 * Page callbacks and forms for jobs.
 */

/**
 * Menu callback: display a list of job types that the user can create.
 */
function recruit_job_ui_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  // Bypass the admin/recruit/jobs/add listing if only one job type is
  // available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
  return theme('job_add_list', array('content' => $content));
}

/**
 * Displays the list of available job types for job creation.
 *
 * @ingroup themeable
 */
function theme_job_add_list($variables) {
  $content = $variables['content'];
  $output = '';

  if ($content) {
    $output = '<dl class="recruit-job-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer job types')) {
      $output = '<p>' . t('You have not created any job types yet. Go to the <a href="@create-job-type">job type creation page</a> to add a new job type.', array('@create-job-type' => url('admin/recruit/jobs/types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No job types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Form callback wrapper: create or edit a job.
 *
 * @param $job
 *   The job object being edited by this form.
 *
 * @see recruit_job_job_form()
 */
function recruit_job_ui_job_form_wrapper($job) {
  
  recruit_job_ui_set_breadcrumb();

  // Include the forms file from the Job module.
  module_load_include('inc', 'recruit_job', 'includes/recruit_job.forms');

  return drupal_get_form('recruit_job_ui_job_form', $job);
}

/**
 * Form callback wrapper: confirmation form for deleting a job.
 *
 * @param $job
 *   The job object being deleted by this form.
 *
 * @see recruit_job_job_delete_form()
 */
function recruit_job_ui_job_delete_form_wrapper($job) {

  recruit_job_ui_set_breadcrumb();

  // Include the forms file from the Job module.
  module_load_include('inc', 'recruit_job', 'includes/recruit_job.forms');

  return drupal_get_form('recruit_job_ui_job_delete_form', $job);
}
