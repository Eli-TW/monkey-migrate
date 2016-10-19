<?php

namespace Drupal\my_migrate\EventSubscriber;

use Drupal\Core\Logger\LoggerChannelInterface;
use Drupal\migrate\Event\MigrateEvents;
use Drupal\migrate\Event\MigrateImportEvent;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;

class MonkeyEventSubscriber implements EventSubscriberInterface {
  /**
   * Logger channel.
   *
   * @var \Drupal\Core\Logger\LoggerChannelInterface $loggerChannel
   */
  protected $loggerChannel;

  /**
   * MonkeyEventSubscriber constructor.
   *
   * @param \Drupal\Core\Logger\LoggerChannelInterface $logger_channel
   *   Channel through which to log events.
   */
  public function __construct(LoggerChannelInterface $logger_channel) {
    $this->loggerChannel = $logger_channel;
  }

  /**
   * {@inheritdoc}
   */
  public static function getSubscribedEvents() {
    $events = [];
    $events[MigrateEvents::PRE_IMPORT][] = ['logPreImport'];
    return $events;
  }

  /**
   * Log the fact we're about to migrate an event.
   *
   * @param \Drupal\migrate\Event\MigrateImportEvent $event
   *   Migrate event about to pre-import.
   */
  public function logPreImport(MigrateImportEvent $event) {
    // We only want to act on migrations we've defined.
    if ($event->getMigration()->id() != 'monkey_node'
      && $event->getMigration()->id() != 'tree_node') {
      return;
    }
    $this->loggerChannel->info('Migrating some shizz via @migration_id',
      ['@migration_id' => $event->getMigration()->id()]);
  }
}
