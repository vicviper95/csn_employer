<?php

/**
 * @file
 * Contains the job delete link field handler.
 */

/**
 * Field handler to present a link to delete a job.
 */
class recruit_job_handler_field_job_link_delete extends recruit_job_handler_field_job_link {
  function construct() {
    parent::construct();

    $this->additional_fields['type'] = 'type';
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // Ensure the user has access to delete this job.
    $job = recruit_job_new();
    $job->job_id = $values->{$this->aliases['jid']};
    $job->type = $values->{$this->aliases['type']};
    $job->uid = $values->{$this->aliases['uid']};

    if (!recruit_job_access('update', $job)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');

    return l($text, 'admin/recruit/jobs/' . $job->job_id . '/delete', array('query' => drupal_get_destination()));
  }
}
