<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */


/**
 * Act on recruit_job being loaded from the database.
 *
 * This hook is invoked during recruit_job loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param $entities
 *   An array of recruit_job entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_recruit_job_load($jobs) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Respond when a recruit_job is inserted.
 *
 * This hook is invoked after the recruit_job is inserted into the database.
 *
 * @param $recruit_job
 *   The recruit_job that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_recruit_job_insert($recruit_job) {
  db_insert('mytable')
    ->fields(array(
      'pid' => $recruit_job->pid,
      'extra' => $recruit_job->extra,
    ))
    ->execute();
}

/**
 * Act on a recruit_job being inserted or updated.
 *
 * This hook is invoked before the recruit_job is saved to the database.
 *
 * @param $recruit_job
 *   The recruit_job that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_recruit_job_presave($recruit_job) {
  $recruit_job->extra = 'foo';
}

/**
 * Respond to a recruit_job being updated.
 *
 * This hook is invoked after the recruit_job has been updated in the database.
 *
 * @param $recruit_job
 *   The recruit_job that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_recruit_job_update($recruit_job) {
  db_update('mytable')
    ->fields(array('extra' => $recruit_job->extra))
    ->condition('pid', $recruit_job->pid)
    ->execute();
}

/**
 * Respond to recruit_job deletion.
 *
 * This hook is invoked after the recruit_job has been removed from the database.
 *
 * @param $recruit_job
 *   The recruit_job that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_recruit_job_delete($recruit_job) {
  db_delete('mytable')
    ->condition('pid', $recruit_job->pid)
    ->execute();
}

/**
 * Act on recruit_job_type being loaded from the database.
 *
 * This hook is invoked during recruit_job_type loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param $entities
 *   An array of recruit_job_type entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_recruit_job_type_load($types) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Respond when a recruit_job_type is inserted.
 *
 * This hook is invoked after the recruit_job_type is inserted into the database.
 *
 * @param $recruit_job_type
 *   The recruit_job_type that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_recruit_job_type_insert($recruit_job_type) {
  db_insert('mytable')
    ->fields(array(
      'pid' => $recruit_job_type->pid,
      'extra' => $recruit_job_type->extra,
    ))
    ->execute();
}

/**
 * Act on a recruit_job_type being inserted or updated.
 *
 * This hook is invoked before the recruit_job_type is saved to the database.
 *
 * @param $recruit_job_type
 *   The recruit_job_type that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_recruit_job_type_presave($recruit_job_type) {
  $recruit_job_type->extra = 'foo';
}

/**
 * Respond to a recruit_job_type being updated.
 *
 * This hook is invoked after the recruit_job_type has been updated in the database.
 *
 * @param $recruit_job_type
 *   The recruit_job_type that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_recruit_job_type_update($recruit_job_type) {
  db_update('mytable')
    ->fields(array('extra' => $recruit_job_type->extra))
    ->condition('pid', $recruit_job_type->pid)
    ->execute();
}

/**
 * Respond to recruit_job_type deletion.
 *
 * This hook is invoked after the recruit_job_type has been removed from the database.
 *
 * @param $recruit_job_type
 *   The recruit_job_type that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_recruit_job_type_delete($recruit_job_type) {
  db_delete('mytable')
    ->condition('pid', $recruit_job_type->pid)
    ->execute();
}