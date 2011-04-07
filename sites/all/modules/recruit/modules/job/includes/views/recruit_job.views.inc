<?php

/**
 * @file
 * Exposes recruit_job.module fields to views.
 */

/**
 * Export Recruit jobs to Views.
 */

/**
 * Implements hook_views_data_alter()
 * EntityAPI implements hook_views_data for the recruit_job. 
 */
function recruit_job_views_data_alter(&$data) {
  //Overrides
  $data['recruit_job']['table']['base']['help'] = t('Job posting.');

  $data['recruit_job']['jid']['field']['handler'] = 'recruit_job_handler_field_job';
  $data['recruit_job']['job_ref']['field']['handler'] = 'recruit_job_handler_field_job';
  $data['recruit_job']['title']['field']['handler'] = 'recruit_job_handler_field_job';
  
  $data['recruit_job']['type']['field']['handler'] = 'recruit_job_handler_field_job_type';

  //Defining custom link fields.
  $data['recruit_job']['view_job'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the job.'),
      'handler' => 'recruit_job_handler_field_job_link',
    ),
  );

  $data['recruit_job']['edit_job'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the job.'),
      'handler' => 'recruit_job_handler_field_job_link_edit',
    ),
  );
  $data['recruit_job']['delete_job'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the job.'),
      'handler' => 'recruit_job_handler_field_job_link_delete',
    ),
  );

  $data['recruit_job']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the job.'),
      'handler' => 'recruit_job_handler_field_job_operations',
    ),
  );
}