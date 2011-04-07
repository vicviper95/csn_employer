<?php

/**
 * @file
 * Contains the basic application operations field.
 */

/**
 * Field handler to present a applications's operations links.
 */
class recruit_application_handler_field_application_operations extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['aid'] = 'aid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $aid = $values->{$this->aliases['aid']};

    $links = menu_contextual_links('recruit_application', 'admin/recruit/applications', array($aid));
    
    if (!empty($links)) {
      drupal_add_css(drupal_get_path('module', 'recruit_application') . '/theme/recruit_application_views.css');

      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
