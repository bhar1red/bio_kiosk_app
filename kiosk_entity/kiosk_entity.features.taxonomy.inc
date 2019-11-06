<?php
/**
 * @file
 * kiosk_entity.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kiosk_entity_taxonomy_default_vocabularies() {
  return array(
    'kiosk_domain' => array(
      'name' => 'Kiosk Domain',
      'machine_name' => 'kiosk_domain',
      'description' => 'Kiosk App Domain',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'kiosk_topics' => array(
      'name' => 'Kiosk Topics',
      'machine_name' => 'kiosk_topics',
      'description' => 'Kiosk Topics',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
