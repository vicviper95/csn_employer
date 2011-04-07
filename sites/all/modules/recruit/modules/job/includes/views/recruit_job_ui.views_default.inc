<?php

/**
 * @file
 * Default views table used for admin/recruit/jobs page.
 */

/**
 * Views for the default job UI.
 */

/**
 * Implement hook_views_default_views().
 */
function recruit_job_ui_views_default_views() {
  /*
   * View 'recruit_job'
   */
  $view = new view;
  $view->name = 'recruit_job';
  $view->description = '';
  $view->tag = 'recruit';
  $view->base_table = 'recruit_job';
  $view->human_name = 'Recruit Job';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Jobs';
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
  $handler->display->display_options['empty']['area']['content'] = 'No jobs have been created yet.';
  /* Field: Job: Job Reference */
  $handler->display->display_options['fields']['job_ref']['id'] = 'job_ref';
  $handler->display->display_options['fields']['job_ref']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['job_ref']['field'] = 'job_ref';
  $handler->display->display_options['fields']['job_ref']['label'] = 'ref';
  $handler->display->display_options['fields']['job_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['job_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['job_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['job_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['job_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['job_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['job_ref']['empty_zero'] = 0;
  /* Field: Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_job'] = 1;
  $handler->display->display_options['fields']['title']['link_to_front_job'] = 0;
  /* Field: Job: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'recruit_job';
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
  /* Field: Job: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'recruit_job';
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
  /* Field: Job: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'recruit_job';
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
  /* Field: Job: Edit link */
  $handler->display->display_options['fields']['edit_job']['id'] = 'edit_job';
  $handler->display->display_options['fields']['edit_job']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['edit_job']['field'] = 'edit_job';
  $handler->display->display_options['fields']['edit_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_job']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_job']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_job']['empty_zero'] = 0;
  /* Field: Job: Delete link */
  $handler->display->display_options['fields']['delete_job']['id'] = 'delete_job';
  $handler->display->display_options['fields']['delete_job']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['delete_job']['field'] = 'delete_job';
  $handler->display->display_options['fields']['delete_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_job']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_job']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_job']['empty_zero'] = 0;

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['path'] = 'admin/recruit/jobs/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Jobs';
  $handler->display->display_options['tab_options']['description'] = 'Manage jobs and job types on your site.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['recruit_job'] = array(
    t('Defaults'),
    t('Jobs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No jobs have been created yet.'),
    t('ref'),
    t('Title'),
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
