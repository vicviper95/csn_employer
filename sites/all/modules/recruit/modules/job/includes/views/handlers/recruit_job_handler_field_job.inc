<?php

/**
 * @file
 * Contains the basic job field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a job.
 */
class recruit_job_handler_field_job extends views_handler_field {
  function init(&$view, $options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_job']) || !empty($this->options['link_to_front_job'])) {
      $this->additional_fields['jid'] = 'jid';

      if (module_exists('translation')) {
        $this->additional_fields['language'] = array('table' => 'recruit_job', 'field' => 'language');
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_job'] = array('default' => FALSE);
    $options['link_to_front_job'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Provide the link to job option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['link_to_job'] = array(
      '#title' => t("Link this field to the job's administrative view page"),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_job']),
    );

    $form['link_to_front_job'] = array(
      '#title' => t("Link this field to the job's public view page"),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_front_job']),
    );
  }

  function render_link($data, $values) {
    if ((!empty($this->options['link_to_job']) || !empty($this->options['link_to_front_job'])) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;

      if ($this->options['link_to_job']) {
        $this->options['alter']['path'] = 'admin/recruit/jobs/' . $values->{$this->aliases['jid']};
      }
      
      if ($this->options['link_to_front_job']) {
        $this->options['alter']['path'] = 'recruit-job/' . $values->{$this->aliases['jid']};
      }


      if (isset($this->aliases['language'])) {
        $languages = language_list();

        if (isset($languages[$values->{$this->aliases['language']}])) {
          $this->options['alter']['language'] = $languages[$values->{$this->aliases['language']}];
        }
      }
    }

    return $data;
  }

  function render($values) {
    return $this->render_link(check_plain($values->{$this->field_alias}), $values);
  }
}
