<?php

/**
 * @file
 * Contains the application type field handler.
 */

/**
 * Field handler to translate a application type into its readable form.
 */
class recruit_application_handler_field_application_type extends recruit_application_handler_field_application {
  function render($values) {
    $value = recruit_application_get_types($values->{$this->field_alias});

    return $this->render_link((check_plain($value->label)), $values);
  }
}
