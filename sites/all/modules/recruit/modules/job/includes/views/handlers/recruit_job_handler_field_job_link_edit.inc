<?php

/**
 * @file
 * Contains the job edit link field handler.
 */

/**
 * Field handler to present a job edit link.
 */
class recruit_job_handler_field_job_link_edit extends recruit_job_handler_field_job_link {
  function construct() {
    parent::construct();

    $this->additional_fields['type'] = 'type';
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // Ensure the user has access to edit this job.
    $job = recruit_job_new();
    $job->job_id = $values->{$this->aliases['jid']};
    $job->type = $values->{$this->aliases['type']};
    $job->uid = $values->{$this->aliases['uid']};

    if (!recruit_job_access('update', $job)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    return l($text, 'admin/recruit/jobs/' . $job->job_id . '/edit', array('query' => drupal_get_destination()));
  }
}
