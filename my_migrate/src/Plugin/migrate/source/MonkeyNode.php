<?php

namespace Drupal\my_migrate\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SqlBase;

/**
 * Source plugin for monkeys.
 *
 * @MigrateSource(
 *   id = "monkey_node"
 * )
 */
class MonkeyNode extends SqlBase {

  /**
   * @inheritdoc
   */
  public function query() {
    $query = $this->select('monkeys', 'm')
      ->fields('m', ['monkey_id', 'name', 'best_friend_id', 'favourite_tree_id']);
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'monkey_id' => $this->t('ID of the monkey'),
      'name' => $this->t('Name of monkey'),
      'best_friend_id' => $this->t('Best friend of monkey'),
      'favourite_tree_id' => $this->t('Favourite tree of monkey'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'monkey_id' => [
        'type' => 'integer',
        'alias' => 'm',
      ],
    ];
  }
}
