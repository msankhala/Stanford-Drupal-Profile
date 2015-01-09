<?php
/**
 * @file
 * Migration class to migrate Stanford Course from D6 to D7 using migrate_d2d.
 */

/**
 * Migration Class for Stanford Courses.
 */
class StanfordCourse6Migration extends DrupalNode6Migration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // dpm($row);
  }
}
