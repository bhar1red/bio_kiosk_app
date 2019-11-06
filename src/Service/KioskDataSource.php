<?php

/**
 *  Application data source agent to create AdapterSource instance based of different types of drupal data object
 */
class KioskDataSource {

  /**
   * Constructor
   */
  public function __construct() {
  }

  public function nullSource($context){
    return new ArrayModel([], $context);
  }
  public function arraySource($items, $context){
    return new ArrayModel($items, $context);
  }

  public function yamlSource($full_path, $file_root){
    return new YamlModel($full_path, ['file_root' => $file_root]);
  }

  public function entitySource($entity, $type){
    return new EntityModel($entity, ['entity_type' => $type]);
  }
  
  public function nodeSource($entity, $context=[]){
    $context['entity_type'] = 'node';
    $context['bundle'] = $entity->type;
    $context['nid'] = $entity->nid;

    return new EntityModel($entity, $context);
  }
  
  public function domainLandingSource($term, $context=[]){
    if(empty($term->vocabulary_machine_name) || $term->vocabulary_machine_name!='kiosk_domain')
      return FALSE;

    $context['entity_type'] = 'taxonomy_term';
    $context['bundle'] = $term->vocabulary_machine_name;
    $context['nodes'] = $this->getPatientGroupList($term);
    $context['domains'] = $this->getKioskDomainTerms();
    $context['cur_domain_id'] = $term->tid;
    return new EntityModel($term, $context);
  }

  public function detailSource($node, $context=[]){
    $context['domains'] = $this->getKioskDomainTerms();
    $context['cur_domain_id'] = $node->field_kiosk_domain['und'][0]['tid'];
    return $this->nodeSource($node, $context);
  }
  
  
  public function getPatientGroupList($term=null,$sort='alpha-asc'){
    $nids = $this->getPatientGroupIDs($term, $sort);
    if(!empty($nids)){
      $nodes = node_load_multiple($nids);
      return $nodes;
    }
    return FALSE;
  }

  public function getPatientGroupIDs($term=null, $sort='alpha-asc'){
    $query = new EntityFieldQuery();
    switch($sort){
      case 'alpha-asc':
      default:
        if(empty($term->tid)){
          $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'patient_group')          
            ->propertyCondition('status', NODE_PUBLISHED)     
            ->propertyOrderBy('title', 'ASC');
        }else{
          $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'patient_group')          
            ->propertyCondition('status', NODE_PUBLISHED)     
            ->fieldCondition('field_kiosk_domain', 'tid', $term->tid, '=')         
            ->propertyOrderBy('title', 'ASC');
        }
        break;
    }
    $result = $query->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      return $nids;
    }
    return FALSE;    
  }
  
  public function getKioskDomainTerms(){
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'kiosk_domain')  
    ->fieldCondition('field_domain_enable', 'value', 1, '=')         
    ->propertyOrderBy('weight', 'ASC');
    $result = $query->execute();
    if (isset($result['taxonomy_term'])) {
      $tids = array_keys($result['taxonomy_term']);
      $terms = taxonomy_term_load_multiple($tids);
      return array_values($terms);
    }
    return FALSE;
  }
  
  public function getEmailTemplates($term) {
    $templates = [];
    $domain_source = $this->entitySource($term,'taxonomy_term');

    $default_value_handler = new DefaultValueHandler();

    $templates['user']['subject'] = trim($domain_source->simpleField('field_email_subject_to_user', 'value'));
    $templates['user']['subject'] = empty($templates['user']['subject']) ? 
        $default_value_handler->getDefaultValue('user_email_subject') : 
        $templates['user']['subject'];

    $templates['user']['body'] = trim($domain_source->simpleField('field_email_template_to_user', 'value'));
    $templates['user']['body'] = empty($templates['user']['body']) ? 
        $default_value_handler->getDefaultValue('user_email_template') :
        $templates['user']['body'];

    $templates['org']['subject'] = trim($domain_source->simpleField('field_email_subject_to_organiza', 'value'));
    $templates['org']['subject'] = empty($templates['org']['subject']) ?
        $default_value_handler->getDefaultValue('org_email_subject') :
        $templates['org']['subject'];

    $templates['org']['body'] = trim($domain_source->simpleField('field_email_template_to_organiza', 'value'));
    $templates['org']['body'] = empty($templates['org']['body']) ?
        $default_value_handler->getDefaultValue('org_email_template') :
        $templates['org']['body'];
    return $templates;
  }
  
  public function createSubscriberTable() {
    $table = array(
      'description' => 'Table for storing kiosk subscriber data.',
      'fields' => array(
        'email'     => array('type' => 'varchar', 'length' => 256, 'not null' => TRUE, 'default' => ''),
        'lead_id'   => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE),
        'nid'       => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE),     
        'page'      => array('type' => 'varchar', 'length' => 256, 'not null' => TRUE, 'default' => ''),
        'domain'    => array('type' => 'varchar', 'length' => 256, 'not null' => TRUE, 'default' => ''),
        'timestamp' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'default' => '0'),
      ),
    );
    db_create_table('kiosk_subscribers_schema', $table);    
  }  
  
  public function saveSubscriberInfo($lead_id, $email, $nid, $page, $domain){
      $date = new DateTime();
      $timestamp = $date->getTimestamp();
      $result = db_insert('kiosk_subscribers_schema')
      ->fields(array(
          lead_id => $lead_id,
          email => $email,
          nid => $nid,
          page => $page,
          domain => $domain,
          timestamp => $timestamp
      ))
      ->execute();
      return ;
  }  
}
