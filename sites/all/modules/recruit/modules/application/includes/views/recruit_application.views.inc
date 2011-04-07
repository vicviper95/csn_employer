<?php

/**
 * @file
 * Exposes recruit_application.module fields to views.
 */

/**
 * Export Recruit applications to Views.
 */

/**
 * Implements hook_views_data_alter()
 * EntityAPI implements hook_views_data for the recruit_application.
 */
function recruit_application_views_data_alter(&$data) {
  //Overrides
  $data['recruit_application']['table']['base']['help'] = t('application posting.');

  $data['recruit_application']['aid']['field']['handler'] = 'recruit_application_handler_field_application';
  $data['recruit_application']['application_ref']['field']['handler'] = 'recruit_application_handler_field_application';
  $data['recruit_application']['title']['field']['handler'] = 'recruit_application_handler_field_application';
  
  $data['recruit_application']['type']['field']['handler'] = 'recruit_application_handler_field_application_type';

  //Defining custom link fields.
  $data['recruit_application']['view_application'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the application.'),
      'handler' => 'recruit_application_handler_field_application_link',
    ),
  );

  $data['recruit_application']['edit_application'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the application.'),
      'handler' => 'recruit_application_handler_field_application_link_edit',
    ),
  );
  $data['recruit_application']['delete_application'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the application.'),
      'handler' => 'recruit_application_handler_field_application_link_delete',
    ),
  );

  $data['recruit_application']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the application.'),
      'handler' => 'recruit_application_handler_field_application_operations',
    ),
  );

  $data['recruit_application']['full_name'] = array(
    'field' => array(
      'title' => t('Applicants full name'),
      'help' => t('Display applicants full name.'),
      'handler' => 'recruit_application_handler_field_application_full_name',
    ),
  );
}