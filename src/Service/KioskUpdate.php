<?php

/**
 *  Application data source agent to create AdapterSource instance based of different types of drupal data object
 */
class KioskUpdate {

  public static function domainCleanAll() {
    $voc = taxonomy_vocabulary_machine_name_load('kiosk_domain');
    $terms = taxonomy_get_tree($voc->vid);
    foreach ($terms as $term) {
      taxonomy_term_delete($term->tid);
    }
  }

  public static function updateContentDomain() {
    $data_source = new KioskDataSource();
    $nodes = $data_source->getPatientGroupList();
    $term = taxonomy_get_term_by_name('Patient Advocacy Connection');
    $term = reset($term);
    foreach ($nodes as $node) {
      $node->field_kiosk_domain['und'][0]['tid'] = $term->tid;
      node_save($node);
    }
  }

  public static function resaveContent() {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'patient_group');
    $result = $query->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $nodes = node_load_multiple($nids);
      foreach ($nodes as $nid => $node)
        node_save($node);
    }
  }
  
  public static function initSubsciberLog() {
    $dataSource = new KioskDataSource();
    $dataSource->createSubscriberTable();
  }

}
