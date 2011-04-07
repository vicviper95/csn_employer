<?php

/**
 * @file
 * Provides entity metadata for the job entity.
 */


/**
 * Extend the defaults.
 */
class RecruitJobMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['jid'] += array(
      'validation callback' => 'entity_metadata_validate_integer_positive',
    );

    $properties['job_ref'] = array(
      'label' => t('Job Reference'),
      'description' => t('The human readable job reference.'),
      'type' => 'text',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['type'] = array(
      'label' => t('Type'),
      'description' => t('The human readable name of the job type.'),
      'type' => 'text',
      'options list' => 'recruit_job_type_get_name',
      'required' => TRUE,
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['title'] = array(
      'label' => t('Title'),
      'description' => t('The title of the job.'),
      'type' => 'text',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['edit-url'] = array(
      'label' => t('Edit URL'),
      'description' => t("The URL of the job's edit page."),
      'getter callback' => 'recruit_job_get_properties',
      'type' => 'uri',
    );
    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the node was posted."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer nodes',
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'query callback' => 'entity_metadata_table_query',
      'description' => t("The date the node was most recently updated."),
    );
    $properties['uid'] = array(
      'label' => t("Creator ID"),
      'type' => 'integer',
      'description' => t("The unique ID of the job creator."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer jobs',
      'clear' => array('creator'),
      'query callback' => 'entity_metadata_table_query',
    );

    $properties['creator'] = array(
      'label' => t("Creator"),
      'type' => 'user',
      'description' => t("The creator of the job."),
      'getter callback' => 'entity_metadata_getter_method',
      'setter callback' => 'entity_metadata_setter_method',
      'setter permission' => 'administer jobs',
      'required' => TRUE,
      'clear' => array('uid'),
    );

    return $info;
  }
}