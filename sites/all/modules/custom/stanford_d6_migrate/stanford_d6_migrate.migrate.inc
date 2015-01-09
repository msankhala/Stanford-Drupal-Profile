<?php
/**
 * @file
 * Standford Drupal 6 to Drupal 7 migration.
 */

define('STANFORD_SOURCE_D6_DTABASE_NAME', 'legacy');
define('STANFORD_EVENT_AUDIENCE_VOCABULARY_ID', 1);
define('STANFORD_EVENT_CATEGORIES_VOCABULARY_ID', 2);
/**
 * Implements hook_migrate_api().
 */
function stanford_d6_migrate_migrate_api() {
  $api = array(
    'api' => 2,
  );
  return $api;
}

/**
 * Implements hook_flush_caches().
 */
function stanford_d6_migrate_flush_caches() {
  stanford_d6_migrate_register_migrations();
}

/**
 * Register all D6->D7 migrations.
 */
function stanford_d6_migrate_register_migrations() {
  /**
   * Each migration being registered takes an array of arguments, some required
   * and some optional. Start with the common arguments required by all - the
   * source_connection (connection key, set up in settings.php, pointing to
   * the Drupal 6 database) and source_version (major version of Drupal).
   */
  $common_arguments = array(
    'source_connection' => STANFORD_SOURCE_D6_DTABASE_NAME,
    'source_version' => 6,
    'group_name' => 'Standford import',
  );

  // The description and the migration machine name are also required arguments,
  // which will be unique for each migration you register.
  $arguments = $common_arguments + array(
    'description' => t('Migration of users from Drupal 6'),
    'machine_name' => 'StanfordUser',
  );

  // We use StanfordUser6Migration D6 migration class as-is.
  Migration::registerMigration('StanfordUser6Migration', $arguments['machine_name'],
                               $arguments);

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 6 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  $vocabulary_arguments = array(
    array(
      'description' => t('Migration of Countries terms from Drupal 6'),
      'machine_name' => 'StanfordEventAudience',
      'source_vocabulary' => STANFORD_EVENT_AUDIENCE_VOCABULARY_ID,  // D6 Vocabulary ID
      'destination_vocabulary' => 'stanford_event_audience',
    ),
    array(
      'description' => t('Migration of Topics terms from Drupal 6'),
      'machine_name' => 'StanfordEventCategories',
      'source_vocabulary' => STANFORD_EVENT_CATEGORIES_VOCABULARY_ID,  // D6 Vocabulary ID
      'destination_vocabulary' => 'stanford_event_categories',
    ),
  );

  // Again, we're using the migrate_d2d class directly.
  // The soft dependency says that while we don't have to run the user migration
  // first, we want to make sure it's listed first so the vocubularies are
  // listed right ahead of the node migrations.
  $common_vocabulary_arguments = $common_arguments + array(
    'class_name' => 'DrupalTerm6Migration',
    'soft_dependencies' => array('StanfordUser'),
  );
  foreach ($vocabulary_arguments as $arguments) {
    $arguments += $common_vocabulary_arguments;
    Migration::registerMigration($arguments['class_name'], $arguments['machine_name'],
                                 $arguments);
  }

  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    array(
      'class_name' => 'StanfordCourse6Migration',
      'description' => t('Migration of stanford course nodes from Drupal 6.'),
      'machine_name' => 'StanfordCourse',
      'source_type' => 'stanford_course',
      'destination_type' => 'stanford_course',
      'dependencies' => array('StanfordUser'),
    ),
  );
  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
    'user_migration' => 'StanfordUser',
  );
  foreach ($node_arguments as $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    Migration::registerMigration($arguments['class_name'], $arguments['machine_name'],
                                 $arguments);
  }

  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    array(
      'class_name' => 'StanfordCourseSection6Migration',
      'description' => t('Migration of stanford course section nodes from Drupal 6 to Drupal 7 Field Collection.'),
      'machine_name' => 'StanfordCourseSection',
      'source_type' => 'stanford_section',
      'destination_type' => 'stanford_course',
      'dependencies' => array('StanfordUser', 'StanfordCourse'),
    ),
  );
  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
    'user_migration' => 'StanfordUser',
  );
  foreach ($node_arguments as $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    Migration::registerMigration($arguments['class_name'], $arguments['machine_name'],
                                 $arguments);
  }

  // Menu migrations -- same requirements as users
  // $menu_arguments = $common_arguments + array(
  //   'description' => t('Migration of menus from Drupal 6'),
  //   'machine_name' => 'Menu',
  // );

  // // We just use the migrate_d2d D6 migration class as-is.
  // Migration::registerMigration('DrupalMenu6Migration', $menu_arguments['machine_name'],
  //                              $menu_arguments);

  // // Menu links migrations -- basic requirements, plus must set up menu dependency
  // $menu_links_arguments = $common_arguments + array(
  //   'description' => t('Migration of menu links from Drupal 6'),
  //   'machine_name' => 'MenuLinks',
  //   'menu_migration' => $menu_arguments['machine_name'],
  // );
  // Migration::registerMigration('DrupalMenuLinks6Migration', $menu_links_arguments['machine_name'],
  //                              $menu_links_arguments);
}
