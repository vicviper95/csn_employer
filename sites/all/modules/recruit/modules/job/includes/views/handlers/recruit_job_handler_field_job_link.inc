<?php

/**
 * @file
 * Contains the job link field handler.
 */

/**
 * Field handler to present a link to a job.
 */
class recruit_job_handler_field_job_link extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['jid'] = 'jid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $job_id = $values->{$this->aliases['job_id']};

    return l($text, 'admin/recruit/jobs/' . $job_id);
  }
}
