<?php

/**
 * @file
 * Contains the basic application field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a application.
 */
class recruit_application_handler_field_application extends views_handler_field {
  function init(&$view, $options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_application']) || !empty($this->options['link_to_front_application'])) {
      $this->additional_fields['aid'] = 'aid';

      if (module_exists('translation')) {
        $this->additional_fields['language'] = array('table' => 'recruit_application', 'field' => 'language');
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_application'] = array('default' => FALSE);
    $options['link_to_front_application'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Provide the link to application option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['link_to_application'] = array(
      '#title' => t("Link this field to the application's administrative view page"),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_application']),
    );

    $form['link_to_front_application'] = array(
      '#title' => t("Link this field to the application's public view page"),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_front_application']),
    );
  }

  function render_link($data, $values) {
    if ((!empty($this->options['link_to_application']) || !empty($this->options['link_to_front_application'])) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;

      if ($this->options['link_to_application']) {
        $this->options['alter']['path'] = 'admin/recruit/applications/' . $values->{$this->aliases['aid']};
      }
      
      if ($this->options['link_to_front_application']) {
        $this->options['alter']['path'] = 'recruit-application/' . $values->{$this->aliases['aid']};
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
