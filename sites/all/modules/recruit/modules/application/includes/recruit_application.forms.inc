<?php

/**
 * @file
 * General forms for applications and application types.
 */

/**
 * Form callback: create or edit a application.
 *
 * @param $application
 */
function recruit_application_application_form($form, &$form_state, $application, $entity = NULL) {

  if (!empty($entity)) {
    $form_state['entity'] = $entity;
  }

  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'recruit_application_ui') . '/includes/recruit_application.forms.inc';

  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => $application->first_name,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => $application->last_name,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -4,
  );
  
  // Add the field related form elements. Attached fields.
  $form_state['recruit_application'] = $application;
  field_attach_form('recruit_application', $application, $form, $form_state);

  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#description' => t(''),
    '#options' => array(
      '1' => t('Active'),
      '0' => t('Disabled'),
    ),
    '#default_value' => $application->status,
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
    '#value' => t('Save application'),
    '#submit' => $submit + array('recruit_application_application_form_submit'),
  );

  $form['#validate'][] = 'recruit_application_application_form_validate';
  
  return $form;
}

/**
 * Validation callback for recruit_application_application_form().
 */
function recruit_application_application_form_validate($form, &$form_state) {
  $application = $form_state['recruit_application'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('recruit_application', $application, $form, $form_state);
}

/**
 * Submit callback for recruit_application_application_form().
 */
function recruit_application_application_form_submit($form, &$form_state) {
  global $user;

  $application = &$form_state['recruit_application'];

  //Set parameters.
  $application->first_name = $form_state['values']['first_name'];
  $application->last_name = $form_state['values']['last_name'];
  #$application->status = $form_state['values']['status'];

  if (empty($application->aid)) {
    $application->uid = $user->uid;
  }
  
  // Notify field widgets.
  field_attach_submit('recruit_application', $application, $form, $form_state);

  // Save the application.
  recruit_application_save($application);
}

/**
 * Form callback: confirmation form for deleting a application.
 *
 * @param $application
 *   The application object to be deleted.
 *
 * @see confirm_form()
 */
function recruit_application_application_delete_form($form, &$form_state, $application) {
  $form_state['recruit_application'] = $application;

  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'recruit_application_ui') . '/includes/recruit_application.forms.inc';

  $form['#submit'][] = 'recruit_application_application_delete_form_submit';
 
  $form = confirm_form($form,
    t('Are you sure you want to delete application ID:%aid?', array('%aid' => $application->aid)),
    '',
    '<p>' . t('Application ID: @aid. Deleting this application cannot be undone.', array('@aid' => $application->aid)) . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for recruit_application_application_delete_form().
 */
function recruit_application_application_delete_form_submit($form, &$form_state) {
  $application = $form_state['recruit_application'];

  recruit_application_delete($application);
  
  drupal_set_message(t('Application ID:%aid has been deleted.', array('%aid' => $application->aid)));
  watchdog('recruit_application', 'Deleted application ID %aid (Full name: @full_name).', array('%aid' => $application->aid, '@full_name' => $application->getFullName()), WATCHDOG_NOTICE);
}


