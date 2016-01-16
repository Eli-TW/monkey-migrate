<?php

namespace Drupal\my_migrate\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SqlBase;

/**
 * Source plugin for trees.
 *
 * @MigrateSource(
 *   id = "tree_node"
 * )
 */
class TreeNode extends SqlBase {

  /**
   * {@inheritdoc}
   */
  public function query() {
    $query = $this->select('trees', 't')
      ->fields('t', ['tree_id', 'name']);
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'tree_id' => $this->t('ID of the tree'),
      'name' => $this->t('Name of tree'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'tree_id' => [
        'type' => 'integer',
        'alias' => 't',
      ],
    ];
  }
}
