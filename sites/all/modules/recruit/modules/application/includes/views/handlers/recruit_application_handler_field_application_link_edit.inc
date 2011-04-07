<?php

/**
 * @file
 * Contains the application edit link field handler.
 */

/**
 * Field handler to present a application edit link.
 */
class recruit_application_handler_field_application_link_edit extends recruit_application_handler_field_application_link {
  function construct() {
    parent::construct();

    $this->additional_fields['type'] = 'type';
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // Ensure the user has access to edit this application.
    $application = recruit_application_new();
    $application->aid = $values->{$this->aliases['aid']};
    $application->type = $values->{$this->aliases['type']};
    $application->uid = $values->{$this->aliases['uid']};

    if (!recruit_application_access('update', $application)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    return l($text, 'admin/recruit/applications/' . $application->aid . '/edit', array('query' => drupal_get_destination()));
  }
}
