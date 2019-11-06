<?php

class KioskTopicMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    ini_set('auto_detect_line_endings', TRUE);

    $module_path = drupal_get_path('module', 'kiosk_entity');
    $root_path = DRUPAL_ROOT . '/'. $module_path . '/import'; 
    $image_path = $root_path . '/images';
    $csv_name = 'kiosk_topic.csv';
    $vocab_name = 'kiosk_topics';
    
    $this->description = t('Import Kiosk Topic Taxonomy Terms.');    

    $this->map = new MigrateSQLMap($this->machineName, array(
      'name' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
        ), MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceCSV($root_path . '/' . $csv_name, $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm($vocab_name, array('text_format' => 'full_html'));

    $this->addSimpleMappings(array(
      'name'
    ));
    
    $this->addFieldMapping('pathauto')->defaultValue(1); 
    
  }

  public function csvcolumns() {
    return array(
      array('name', 'Term name'),
    );
  }

  public function processImport(array $options = array()) {
    parent::processImport($options = array());
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // on each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

}
