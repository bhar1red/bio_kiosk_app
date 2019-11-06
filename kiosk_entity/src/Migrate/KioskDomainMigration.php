<?php

class KioskDomainMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    ini_set('auto_detect_line_endings', TRUE);

    $module_path = drupal_get_path('module', 'kiosk_entity');
    $root_path = DRUPAL_ROOT . '/'. $module_path . '/import'; 
    $image_path = $root_path . '/images';
    $csv_name = 'kiosk_domain.csv';
    $vocab_name = 'kiosk_domain';
    
    $this->description = t('Import Kiosk Domain Taxonomy Terms.');    

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
      'name',
      'description',
      'weight',
    ));
    $this->addFieldMapping('field_domain_caption', 'caption');
    $this->addFieldMapping('field_domain_enable', 'enable');

    $this->addFieldMapping('field_domain_bg_image', 'bg_image');
    $this->addFieldMapping('field_domain_bg_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_domain_bg_image:source_dir')->defaultValue($image_path);
    
    $this->addFieldMapping('path', 'path_alias');
    $this->addFieldMapping('pathauto')->defaultValue(0); // use path alias defined in csv
    
  }

  public function csvcolumns() {
    return array(
      array('name', 'Term name'),
      array('weight', 'Weight'),
      array('path_alias', 'Path Alias'),
      array('caption', 'Caption'),
      array('bg_image', 'Background Image'),
      array('enable', 'Enable'),
      array('description', 'Description'),
    );
  }

  public function prepare($term, $row) {
    $term->path['pathauto'] = 0; // use path alias defined in csv and uncheck the pathauto option
  }
    
  public function processImport(array $options = array()) {
    parent::processImport($options = array());
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // on each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

}
