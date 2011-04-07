<?php

/**
 * @file
 * Provides entity metadata for the application entity.
 */


/**
 * Extend the defaults.
 */
class RecruitApplicationMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['aid'] += array(
      'validation callback' => 'entity_metadata_validate_integer_positive',
    );

    $properties['type'] = array(
      'label' => t('Type'),
      'description' => t('The human readable name of the application type.'),
      'type' => 'text',
      'options list' => 'recruit_application_type_get_name',
      'required' => TRUE,
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['first_name'] = array(
      'label' => t('First name'),
      'description' => t('The first name of the application.'),
      'type' => 'text',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['last_name'] = array(
      'label' => t('Last name'),
      'description' => t('The last name of the application.'),
      'type' => 'text',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'query callback' => 'entity_metadata_table_query',
    );
    $properties['edit-url'] = array(
      'label' => t('Edit URL'),
      'description' => t("The URL of the application's edit page."),
      'getter callback' => 'recruit_application_get_properties',
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
      'description' => t("The unique ID of the application creator."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer applications',
      'clear' => array('creator'),
      'query callback' => 'entity_metadata_table_query',
    );

    $properties['creator'] = array(
      'label' => t("Creator"),
      'type' => 'user',
      'description' => t("The creator of the application."),
      'getter callback' => 'entity_metadata_getter_method',
      'setter callback' => 'entity_metadata_setter_method',
      'setter permission' => 'administer applications',
      'required' => TRUE,
      'clear' => array('uid'),
    );

    return $info;
  }
}