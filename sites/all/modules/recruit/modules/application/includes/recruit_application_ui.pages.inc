<?php

/**
 * @file
 * Page callbacks functions for frontend displayed applications.
 */


function recruit_application_ui_apply_page($type) {

  //Get entity details from GET.
  $entity_type = $_GET['et'];
  $entity_id = $_GET['id'];

  drupal_set_title(check_plain($type->label));
  module_load_include('inc', 'recruit_application', 'includes/recruit_application.forms');


  $entity = recruit_entity_load_single($entity_type, $entity_id);
  $application = recruit_application_new($type->type);
  $content = drupal_get_form('recruit_application_ui_application_apply_form', $application, $entity);
  
  return theme('recruit_application_form', array('content' => $content, 'type' => $type));
}

function recruit_application_ui_admin_view_page($application) {
  return theme('recruit_application', array('application' => $application, 'view_mode' => 'admin'));
}