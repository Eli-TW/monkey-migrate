<?php

namespace Drupal\my_drush_migrate\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SqlBase;

/**
 * Source plugin for sloths.
 *
 * @MigrateSource(
 *   id = "sloth_node"
 * )
 */
class SlothNode extends SqlBase {

  /**
   * {@inheritdoc}
   */
  public function query() {
    $query = $this->select('sloths', 's')
      ->fields('s', ['sloth_id', 'name']);
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'sloth_id' => $this->t('ID of the sloth'),
      'name' => $this->t('Name of sloth'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'sloth_id' => [
        'type' => 'integer',
        'alias' => 's',
      ],
    ];
  }
}
