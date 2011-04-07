<?php

/**
 * @file
 * application type editing UI.
 */

/**
 * UI controller.
 */
class RecruitApplicationTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    $items[$this->path]['description'] = 'Manage application types, including fields.';
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    return $items;
  }
}

/**
 * Generates the application type editing form.
 * @see EntityDefaultUIController
 */
function recruit_application_type_form($form, &$form_state, $application_type, $op = 'edit') {

  if ($op == 'clone') {
    $application_type->label .= ' (cloned)';
    $application_type->type .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $application_type->label,
    '#description' => t('The human-readable name of this application type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($application_type->type) ? $application_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $application_type->isLocked(),
    '#machine_name' => array(
      'exists' => 'recruit_application_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this application type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Describe this application type. The text will be displayed on the <em>Add new content</em> page.'),
    '#default_value' => $application_type->description,
    '#rows' => 3,
  );

  $form['help'] = array(
    '#type' => 'textarea',
    '#title' => t('Explanation or submission guidelines'),
    '#description' => t('This text will be displayed at the top of the page when creating or editing applications of this type.'),
    '#default_value' => $application_type->help,
    '#rows' => 3,
  );

  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application type'),
    '#weight' => 40,
  );

  if (!$application_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete application type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('recruit_application_type_form_submit_delete')
    );
  }
  
  return $form;
}

function recruit_application_type_form_validate(&$form, &$form_state) {
  $application_type = $form_state['recruit_application_type'];

  // If saving a new application type, ensure it has a unique machine name.
  if (empty($application_type->type)) {
    if (!recruit_application_type_validate_type_unique($form_state['values']['type'])) {
      form_set_error('type', 'The machine name specified is already in use.');
    }
  }
}


/**
 * Form API submit callback for the type form.
 */
function recruit_application_type_form_submit(&$form, &$form_state) {
  $recruit_application_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $recruit_application_type->save();
  $form_state['redirect'] = 'admin/recruit/applications/types';
}

/**
 * Form API submit callback for the delete button.
 */
function recruit_application_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/recruit/applications/types/manage/' . $form_state['recruit_application_type']->type . '/delete';
}
