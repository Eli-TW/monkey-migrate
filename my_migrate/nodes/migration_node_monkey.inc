<?php
class MigrationNodeMonkey extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('AnimalNodeMigration'));
    $this->description = t('Migrate the Monkeys');

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
      ->condition('type', 'monkey');
    $query->addField('n', 'nid');

    $this->addSimpleMappings($node_columns);

/* restore this section for the second migration

    // join body field
    $query->leftJoin('field_data_body', 'fdb', 'n.vid = fdb.entity_id');
    $query->addField('fdb', 'body_value');
    $query->addField('fdb', 'body_summary');
    $query->addField('fdb', 'body_format');
    $query->addField('fdb', 'language', 'body_language');

    $this->addFieldMapping('body', 'body_value');
    $this->addFieldMapping('body:summary', 'body_summary');
    $this->addFieldMapping('body:format', 'body_format');
    $this->addFieldMapping('body:language', 'body_language');

    // join image field
    $query->leftJoin('field_data_field_picture', 'fdfp', 'n.vid = fdfp.entity_id');
    $query->addField('fdfp', 'field_picture_title');

    // join file_managed
    $query->leftJoin('file_managed', 'fm', 'fdfp.field_picture_fid = fm.fid');
    $query->addField('fm', 'filename');

    $this->addFieldMapping('field_picture', 'filename');
    $this->addFieldMapping('field_picture:title', 'field_picture_title');
    $this->addFieldMapping('field_picture:source_dir')
      ->defaultValue('/home/quickstart/websites/source.local/sites/default/files');
/* restore this section for the second migration */

/* restore this section for the third migration
    // Monkeys' favourite tree
    $query->leftJoin('field_data_field_favourite_tree', 'fdfft', 'n.vid = fdfft.entity_id');
    $query->addField('fdfft', 'field_favourite_tree_target_id');

    $this->addFieldMapping('field_favourite_tree', 'field_favourite_tree_target_id')
      ->sourceMigration('MigrationNodeTree');

    $this->dependencies[] = 'MigrationNodeTree';

    // Monkeys' best friend
    $query->leftJoin('field_data_field_best_friend', 'fdfbf', 'n.vid = fdfbf.entity_id');
    $query->addField('fdfbf', 'field_best_friend_target_id');

    $this->addFieldMapping('field_best_friend', 'field_best_friend_target_id')
      ->sourceMigration('MigrationNodeMonkey');
/* restore this section for the third migration */

    $query->groupBy('n.nid');
    $query->distinct();

    // Create a MigrateSource object, which manages retrieving the input data.
    // map_joinable is false as the map table can't be joined to the source as they are in different DBs
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

    // Set up our destination
    $this->destination = new MigrateDestinationNode('monkey');

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

    // Add explicitly unmigrated destination fields
    $unmigrated_destinations = array(
      'uid',
      'revision',
      'log',
      'translate',
      'revision_uid',
      'is_new',
      'path',
      'comment',
    );
    $this->addUnmigratedDestinations($unmigrated_destinations);
  }

  protected function createStub($migration, $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for') . $source_id[0];
    $node->body = t('Stub body');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }
}
