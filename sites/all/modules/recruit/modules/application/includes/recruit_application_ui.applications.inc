<?php

/**
 * @file
 * Page callbacks and forms for applications.
 */

/**
 * Menu callback: display a list of application types that the user can create.
 */
function recruit_application_ui_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  // Bypass the admin/recruit/applications/add listing if only one application type is
  // available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
  return theme('application_add_list', array('content' => $content));
}

/**
 * Displays the list of available application types for application creation.
 *
 * @ingroup themeable
 */
function theme_application_add_list($variables) {
  $content = $variables['content'];
  $output = '';

  if ($content) {
    $output = '<dl class="recruit-application-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer application types')) {
      $output = '<p>' . t('You have not created any application types yet. Go to the <a href="@create-application-type">application type creation page</a> to add a new application type.', array('@create-application-type' => url('admin/recruit/applications/types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No application types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Form callback wrapper: create or edit a application.
 *
 * @param $application
 *   The application object being edited by this form.
 *
 * @see recruit_application_application_form()
 */
function recruit_application_ui_application_form_wrapper($application) {
  
  recruit_application_ui_set_breadcrumb();

  // Include the forms file from the application module.
  module_load_include('inc', 'recruit_application', 'includes/recruit_application.forms');

  return drupal_get_form('recruit_application_ui_application_form', $application);
}

/**
 * Form callback wrapper: confirmation form for deleting a application.
 *
 * @param $application
 *   The application object being deleted by this form.
 *
 * @see recruit_application_application_delete_form()
 */
function recruit_application_ui_application_delete_form_wrapper($application) {

  recruit_application_ui_set_breadcrumb();

  // Include the forms file from the application module.
  module_load_include('inc', 'recruit_application', 'includes/recruit_application.forms');

  return drupal_get_form('recruit_application_ui_application_delete_form', $application);
}
