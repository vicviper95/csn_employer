<?php

/**
 * @file
 * Contains the basic application full name field.
 */

/**
 * Field handler to present a applications's operations links.
 */
class recruit_application_handler_field_application_full_name extends recruit_application_handler_field_application {
  function construct() {
    parent::construct();

    $this->additional_fields['aid'] = 'aid';
    $this->additional_fields['first_name'] = 'first_name';
    $this->additional_fields['last_name'] = 'last_name';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $aid = $values->{$this->aliases['aid']};
    $first_name = $values->{$this->aliases['first_name']};
    $last_name = $values->{$this->aliases['last_name']};

    return $this->render_link((check_plain($first_name . ' ' . $last_name)), $values);
  }
}
