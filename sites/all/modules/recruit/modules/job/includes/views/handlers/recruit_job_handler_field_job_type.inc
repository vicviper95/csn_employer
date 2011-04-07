<?php

/**
 * @file
 * Contains the job type field handler.
 */

/**
 * Field handler to translate a job type into its readable form.
 */
class recruit_job_handler_field_job_type extends recruit_job_handler_field_job {
  function render($values) {
    $value = recruit_job_get_types($values->{$this->field_alias});

    return $this->render_link((check_plain($value->label)), $values);
  }
}
