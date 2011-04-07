<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */


/**
 * Act on recruit_application being loaded from the database.
 *
 * This hook is invoked during recruit_application loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param $entities
 *   An array of recruit_application entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_recruit_application_load($applications) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Respond when a recruit_application is inserted.
 *
 * This hook is invoked after the recruit_application is inserted into the database.
 *
 * @param $recruit_application
 *   The recruit_application that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_recruit_application_insert($recruit_application) {
  db_insert('mytable')
    ->fields(array(
      'pid' => $recruit_application->pid,
      'extra' => $recruit_application->extra,
    ))
    ->execute();
}

/**
 * Act on a recruit_application being inserted or updated.
 *
 * This hook is invoked before the recruit_application is saved to the database.
 *
 * @param $recruit_application
 *   The recruit_application that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_recruit_application_presave($recruit_application) {
  $recruit_application->extra = 'foo';
}

/**
 * Respond to a recruit_application being updated.
 *
 * This hook is invoked after the recruit_application has been updated in the database.
 *
 * @param $recruit_application
 *   The recruit_application that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_recruit_application_update($recruit_application) {
  db_update('mytable')
    ->fields(array('extra' => $recruit_application->extra))
    ->condition('pid', $recruit_application->pid)
    ->execute();
}

/**
 * Respond to recruit_application deletion.
 *
 * This hook is invoked after the recruit_application has been removed from the database.
 *
 * @param $recruit_application
 *   The recruit_application that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_recruit_application_delete($recruit_application) {
  db_delete('mytable')
    ->condition('pid', $recruit_application->pid)
    ->execute();
}

/**
 * Act on recruit_application_type being loaded from the database.
 *
 * This hook is invoked during recruit_application_type loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param $entities
 *   An array of recruit_application_type entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_recruit_application_type_load($types) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Respond when a recruit_application_type is inserted.
 *
 * This hook is invoked after the recruit_application_type is inserted into the database.
 *
 * @param $recruit_application_type
 *   The recruit_application_type that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_recruit_application_type_insert($recruit_application_type) {
  db_insert('mytable')
    ->fields(array(
      'pid' => $recruit_application_type->pid,
      'extra' => $recruit_application_type->extra,
    ))
    ->execute();
}

/**
 * Act on a recruit_application_type being inserted or updated.
 *
 * This hook is invoked before the recruit_application_type is saved to the database.
 *
 * @param $recruit_application_type
 *   The recruit_application_type that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_recruit_application_type_presave($recruit_application_type) {
  $recruit_application_type->extra = 'foo';
}

/**
 * Respond to a recruit_application_type being updated.
 *
 * This hook is invoked after the recruit_application_type has been updated in the database.
 *
 * @param $recruit_application_type
 *   The recruit_application_type that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_recruit_application_type_update($recruit_application_type) {
  db_update('mytable')
    ->fields(array('extra' => $recruit_application_type->extra))
    ->condition('pid', $recruit_application_type->pid)
    ->execute();
}

/**
 * Respond to recruit_application_type deletion.
 *
 * This hook is invoked after the recruit_application_type has been removed from the database.
 *
 * @param $recruit_application_type
 *   The recruit_application_type that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_recruit_application_type_delete($recruit_application_type) {
  db_delete('mytable')
    ->condition('pid', $recruit_application_type->pid)
    ->execute();
}