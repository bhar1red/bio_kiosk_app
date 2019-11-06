<?php

function kiosk_entity_migrate_api() {
  return array(
    'api' => 2,
    'migrations' => array(
      'kiosk_domain' => array('class_name' => 'KioskDomainMigration'),
      'kiosk_topic' => array('class_name' => 'KioskTopicMigration'),
    ),
  );
}
