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
      ->fields('m', ['monkey_id', 'name']);
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'monkey_id' => $this->t('ID of the monkey'),
      'name' => $this->t('Name of monkey'),
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
