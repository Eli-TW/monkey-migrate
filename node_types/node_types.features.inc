<?php
/**
 * @file
 * node_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function node_types_node_info() {
  $items = array(
    'monkey' => array(
      'name' => t('Monkey'),
      'base' => 'node_content',
      'description' => t('This describes a specific monkey'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'sloth' => array(
      'name' => t('Sloth'),
      'base' => 'node_content',
      'description' => t('This describes a specific sloth'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'tree' => array(
      'name' => t('Tree'),
      'base' => 'node_content',
      'description' => t('This describes a tree'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
