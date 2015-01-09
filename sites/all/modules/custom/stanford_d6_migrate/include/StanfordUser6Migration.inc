<?php
/**
 * @file
 * Migration class to migrate Stanford Course from D6 to D7 using migrate_d2d.
 */

/**
 * Handling specific to a Drupal 6 source for users.
 */
class StanfordUser6Migration extends DrupalUser6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}
