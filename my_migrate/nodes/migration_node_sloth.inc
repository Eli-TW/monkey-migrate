<?php
class MigrationNodeSloth extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('AnimalNodeMigration'));
    $this->description = t('Migrate the Sloths');

    // create query and add columns from node table
    $node_columns = array(
      'title',
      'language',
      'status',
      'created',
      'changed',
      'promote',
      'sticky',
      'tnid',
    );

    $query = Database::getConnection('default', 'source_db')
      ->select('node', 'n')
      ->fields('n', $node_columns)
      ->condition('type', 'sloth');
    $query->addField('n', 'nid');

    $query->groupBy('n.nid');
    $query->distinct();

    // Create a MigrateSource object, which manages retrieving the input data.
    // map_joinable is false as the map table can't be joined to the source as they are in different DBs
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

    // Set up our destination
    $this->destination = new MigrateDestinationNode('sloth');

    // Set up mapping between source and destination
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'description' => 'ID of destination node',
          'alias' => 'n',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->addSimpleMappings($node_columns);
  }
}
