<?php

/**
 * @file
 * Default views table used for admin/recruit/applications page.
 */

/**
 * Views for the default application UI.
 */

/**
 * Implement hook_views_default_views().
 */
function recruit_application_ui_views_default_views() {
  /*
   * View 'recruit_application'
   */
  $view = new view;
  $view->name = 'recruit_application';
  $view->description = '';
  $view->tag = 'recruit';
  $view->base_table = 'recruit_application';
  $view->human_name = 'Recruit application';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Applications';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Empty text: Empty text */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['ui_name'] = 'Empty text';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No applications have been created yet.';
  /* Field: Application: Application ID */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = 'ID';
  $handler->display->display_options['fields']['aid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['aid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['aid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['aid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['aid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['aid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['aid']['link_to_application'] = 1;
  $handler->display->display_options['fields']['aid']['link_to_front_application'] = 0;
  /* Field: Application: Applicants full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['label'] = 'Full name';
  $handler->display->display_options['fields']['full_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['full_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['full_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['full_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['full_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['full_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['full_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['full_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['full_name']['link_to_application'] = 1;
  $handler->display->display_options['fields']['full_name']['link_to_front_application'] = 0;
  /* Field: Fields: field_application_ref */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'field_data_field_application_ref';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'Job';
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_id']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['entity_id']['field_api_classes'] = 0;
  /* Field: Application: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  /* Field: Application: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  /* Field: Application: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  /* Field: Application: Edit link */
  $handler->display->display_options['fields']['edit_application']['id'] = 'edit_application';
  $handler->display->display_options['fields']['edit_application']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['edit_application']['field'] = 'edit_application';
  $handler->display->display_options['fields']['edit_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_application']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_application']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_application']['empty_zero'] = 0;
  /* Field: Application: Delete link */
  $handler->display->display_options['fields']['delete_application']['id'] = 'delete_application';
  $handler->display->display_options['fields']['delete_application']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['delete_application']['field'] = 'delete_application';
  $handler->display->display_options['fields']['delete_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_application']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_application']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_application']['empty_zero'] = 0;

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['path'] = 'admin/recruit/applications/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Applications';
  $handler->display->display_options['tab_options']['description'] = 'Manage applications and application types on your site.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['recruit_application'] = array(
    t('Defaults'),
    t('Applications'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No applications have been created yet.'),
    t('ID'),
    t('Full name'),
    t('Job'),
    t('Type'),
    t('Date created'),
    t('Date changed'),
    t('Edit link'),
    t('Delete link'),
    t('Admin page'),
  );
  $views[$view->name] = $view;

  return $views;
}
