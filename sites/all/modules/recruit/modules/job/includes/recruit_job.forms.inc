<?php

/**
 * @file
 * General forms for jobs and job types.
 */

/**
 * Form callback: create or edit a job.
 *
 * @param $job
 */
function recruit_job_job_form($form, &$form_state, $job) {
 
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'recruit_job_ui') . '/includes/recruit_job.forms.inc';
  
  // Add the default field elements.
  $form['job_ref'] = array(
    '#type' => 'textfield',
    '#title' => t('Job Reference'),
    '#description' => t('Supply a unique identifier for this job using letters, numbers, hypens, and underscores.'),
    '#default_value' => $job->job_ref,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#weight' => -10,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $job->title,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  // Add the field related form elements. Attached fields.
  $form_state['recruit_job'] = $job;
  field_attach_form('recruit_job', $job, $form, $form_state);

  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#description' => t(''),
    '#options' => array(
      '1' => t('Active'),
      '0' => t('Disabled'),
    ),
    '#default_value' => $job->status,
    '#required' => TRUE,
    '#weight' => 35,
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 40,
  );

  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save job'),
    '#submit' => $submit + array('recruit_job_job_form_submit'),
  );

  $form['#validate'][] = 'recruit_job_job_form_validate';

  return $form;
}

/**
 * Validation callback for recruit_job_job_form().
 */
function recruit_job_job_form_validate($form, &$form_state) {
  $job = $form_state['recruit_job'];

  $job_ref = $form_state['values']['job_ref'];

  if ($job_ref === FALSE) {
    form_set_error('job_ref', 'The job_ref contains invalid tokens.');
  }
  else {

    if (!recruit_job_validate_job_ref_characters($job_ref)) {
      form_set_error('job_ref', t('The job reference must contain only letters, numbers, hyphens, and underscores.'));
    }

    //Ensure job ref is unique.
    if (!recruit_job_validate_job_ref_unique($job_ref, $job->jid)) {
      form_set_error('job_ref', 'This job reference is already in use and must be unique. Please supply another value.');
    }
  }

  // Notify field widgets to validate their data.
  field_attach_form_validate('recruit_job', $job, $form, $form_state);
}

/**
 * Submit callback for recruit_job_job_form().
 */
function recruit_job_job_form_submit($form, &$form_state) {
  global $user;

  $job = &$form_state['recruit_job'];

  //Set parameters.
  $job->job_ref = $form_state['values']['job_ref'];
  $job->title = $form_state['values']['title'];
  $job->status = $form_state['values']['status'];

  if (empty($job->jid)) {
    $job->uid = $user->uid;
  }
  
  // Notify field widgets.
  field_attach_submit('recruit_job', $job, $form, $form_state);

  // Save the job.
  recruit_job_save($job);

  // Set message.
  drupal_set_message(t('Job saved.'));
}

/**
 * Form callback: confirmation form for deleting a job.
 *
 * @param $job
 *   The job object to be deleted.
 *
 * @see confirm_form()
 */
function recruit_job_job_delete_form($form, &$form_state, $job) {
  $form_state['recruit_job'] = $job;

   $form_state['build_info']['files']['form'] = drupal_get_path('module', 'recruit_job_ui') . '/includes/recruit_job.forms.inc';

  $form['#submit'][] = 'recruit_job_job_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $job->title)),
    '',
    '<p>' . t('Job Reference: @job_ref. Deleting this job cannot be undone.', array('@job_ref' => $job->job_ref)) . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for recruit_job_job_delete_form().
 */
function recruit_job_job_delete_form_submit($form, &$form_state) {
  $job = $form_state['recruit_job'];

  recruit_job_delete($job);
  
  drupal_set_message(t('%title has been deleted.', array('%title' => $job->title)));
  watchdog('recruit_job', 'Deleted job %title (Job Reference: @job_ref).', array('%title' => $job->title, '@job_ref' => $job->job_ref), WATCHDOG_NOTICE);
}


