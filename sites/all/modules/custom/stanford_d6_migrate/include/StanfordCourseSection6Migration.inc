<?php
/**
 * @file
 * Migration class to migrate Stanford Course from D6 to D7 using migrate_d2d.
 */

/**
 * Migration Class for Stanford Courses.
 */
class StanfordCourseSection6Migration extends DrupalNode6Migration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_s_course_section_info',
      array('host_entity_type' => 'node')
    );
    $this->addFieldMapping('host_entity_id', 'field_stanford_section_course')
    ->sourceMigration('StanfordCourse');
  }
  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // dpm($row);
  }
  // public function prepare($node, stdClass $row) {
  //   // Let's pretend we couldn't have done this as easily in prepareRow...
  //   // $node->title = 'My site: ' . $row->source_title;
  //   dpm($node);
  // }
}
