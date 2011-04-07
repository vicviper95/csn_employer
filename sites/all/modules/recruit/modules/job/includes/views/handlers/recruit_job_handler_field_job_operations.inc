<?php

/**
 * @file
 * Contains the basic job operations field.
 */

/**
 * Field handler to present a jobs's operations links.
 */
class recruit_job_handler_field_job_operations extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['jid'] = 'jid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $jid = $values->{$this->aliases['jid']};

    $links = menu_contextual_links('recruit_job', 'admin/recruit/jobs', array($jid));
    
    if (!empty($links)) {
      drupal_add_css(drupal_get_path('module', 'recruit_job') . '/theme/recruit_job_views.css');

      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
