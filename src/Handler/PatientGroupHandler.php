<?php

class PatientGroupHandler extends BaseHandler {

  /**
   * Constructor
   */
  public function __construct(AdapterTransformEvent $event) {
    $this->event = $event;
  }
  
  public function processLandingMenu(){
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $context = $source->getContext();    
    if(empty($context['domains'])) return;
    
    $terms = $context['domains'];
    $cur_domain_id = $context['cur_domain_id'];
    $active_index = -1;
    for($i = 0; $i < count($terms); $i++){
      if($cur_domain_id == $terms[$i]->tid){
        $active_index = $i;
        break;
      }
    }
    $model['tabs']=$this->buildMenu($terms,$active_index);
    $destination->setResult($model);
  }
  
  public function processDetailBreadcrumb(){
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $context = $source->getContext();    
    $model['back_link']['url'] = base_path().drupal_lookup_path('alias','taxonomy/term/'.$context['cur_domain_id']); 
    $destination->setResult($model);
  }
  
  public function processDetail(){
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();

    if(empty($model['hero_bg']['src'])){
        $model['hero_bg']['src'] = $this->getDomainHeroImage($source);
    } 
    
    $model['website']['title'] = str_replace('http://', '', $model['website']['url']);
    $model['description']['label'] = $model['title']['value'];
    $summary = empty($model['summary']['value']) ? strip_tags($source->simpleField('body','value')) : strip_tags($model['summary']['value']);
    $model['summary']['value'] = truncate_utf8($summary, 300, TRUE, TRUE);
    
    $this->prepareEmails($model, $source);
    
    $cur_nid = $source->property('nid');
//    if(($skin=$this->getSkinOptions($cur_nid))===FALSE) return;
    $skin = 'orange-skin';
    $model['styles'][] = $skin;
    $destination->setResult($model);
  }
  
  public function processEmailContactList(){
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();

    $data_source = new KioskDataSource();
    $app = new StandardApp();   

    $entities = $source->rawSource(); 
    foreach($entities as $entity){
      $contact_source = $data_source->entitySource($entity,'paragraphs_item');
      $element = $app->getElement('email_contact_item',$contact_source);
      $model['items'][] = $element;
    }
    $destination->setResult($model);
  }
  
  protected function prepareEmails(&$model, $source){
      
      $domain_tid = $source->simpleField('field_kiosk_domain','tid');
      $domain = taxonomy_term_load($domain_tid);
      $data_source = new KioskDataSource();
      $templates = $data_source->getEmailTemplates($domain);
      
      $org_name = $model['title']['value'];
      
      $org_domain = $domain->name;
      $org_website = $source->simpleField('field_pg_website', 'url');
      $org_description = $source->simpleField('body','value');
      
      
      $convention_title = variable_get('kiosk_convention_title');

      $summary = strip_tags($source->simpleField('body','summary'));
      if(empty($summary)){
          $summary = strip_tags($source->simpleField('body','value'));
          $summary = truncate_utf8($summary, 300, TRUE, TRUE);
      }
     
      $item_ids = $source->multivalField('field_pg_contact', 'value');
      $contact_info = '';
      if(!empty($item_ids)){
          $entities = entity_load('paragraphs_item',$item_ids);
          if(!empty($entities)){
              $entities = array_values($entities);
              $app = new StandardApp();
              $contact_source = $data_source->arraySource($entities,[]);
              $element = $app->getElement('email_contact_list',$contact_source);
              $contact_info = TPLRender::component($element['model'],$element['tpl']);     
          }
      }
      
      $curr_nid = $source->property('nid');
      $alias = drupal_lookup_path('alias',"node/".$curr_nid);
      global $base_url;
      $link = $base_url.base_path().$alias;
      
      $logo_url = empty($model['logo']['src']) ? '' : $base_url.base_path().$model['logo']['src'];
      
      if(empty($model['hero_bg']['src'])){
          $model['hero_bg']['src'] = $this->getDomainHeroImage($source);
      } 
      $org_header_background = $model['hero_bg']['src'];
      
      $email_disclaimer = variable_get('kiosk_email_disclaimer')['value'];
      
      $bio_link = $base_url.base_path();
      $bio_logo = $base_url.base_path().'sites/default/files/BIO-Logo-Horizontal-bioorg-160.png';
      $org_variables = [
          '!org_name' => $org_name,
          '!org_domain' => $org_domain,
          '!org_summary' => $summary,
          '!org_website' => $org_website,
          '!org_description' => $org_description,
          '!org_link' => $link,
          '!org_contact' => $contact_info,
          '!org_logo' => $logo_url,
          '!convention_title' => $convention_title,
          '!org_header_background' => $org_header_background,
          '!bio_link' => $bio_link,
          '!bio_logo' => $bio_logo,
          '!email_disclaimer' => $email_disclaimer
      ];
      
      
      $model['user_mail']['mailto']['subject'] = format_string($templates['user']['subject'], $org_variables);
      $model['user_mail']['mailto']['body'] = format_string($templates['user']['body'], $org_variables);
      
      $model['org_mail']['mailto']['subject'] = format_string($templates['org']['subject'], $org_variables);
      $model['org_mail']['mailto']['body'] = format_string($templates['org']['body'], $org_variables);
  }
  
  protected function getSkinOptions($cur_nid){
    $data_source = new KioskDataSource();
    $nids = $data_source->getPatientGroupIDs();
    $index = array_search($cur_nid,$nids);
    if($index===FALSE) return FALSE;
    return $this->skin_options[$index%4];
  }
  
  public function loadCarousel(){
    $destination = $this->event->getDestination();
    $source = $this->event->getSource();
    $config = $this->event->getConfig();
    $context = $source->getContext();    
    $model = $destination->getResult();
    
    $current_term = $source->rawSource();
    if(empty($current_term->tid)){
      // backward compatibility, can be removed later
      $data_source = new KioskDataSource();
      $terms = $data_source->getKioskDomainTerms();
      $current_path = '/'.current_path();
      foreach($terms as $term){
        $url = drupal_lookup_path('alias','taxonomy/term/'.$term->tid); 
        if($url == $current_path){
          $current_term = $term;
          break;
        }
      }
    }

    $model['slider_list'] = []; 
    if(!empty($current_term->tid)){
      // first slider
      $slider_item = [
        'item_type' => 'branding-item'
      ];
      $term_context = ['entity_type' => 'taxonomy_term'];
      $item_source = new EntityModel($current_term, $term_context);   
      $element_exec = new ElementExecutable();  
      $element = $element_exec->process('brand_item', $item_source, $config);
      $slider_item = array_merge_recursive($slider_item,$element);
      $model['slider_list'][] = $slider_item;
    }
    
    if(!empty($context['nodes'])){
      foreach($context['nodes'] as $nid => $node){
        $slider_item = [
          'item_type' => 'overview-item'
        ];
        $node_context = ['entity_type' => 'node'];
        $item_source = new EntityModel($node, $node_context);   
        $element_exec = new ElementExecutable();  
        $element = $element_exec->process('overview_item', $item_source, $config);
        $slider_item = array_merge_recursive($slider_item,$element);
        $model['slider_list'][] = $slider_item;
      }
    }
    
    $destination->setResult($model);
  }
  
  public function loadLogoList(){
    $destination = $this->event->getDestination();
    $source = $this->event->getSource();
    $config = $this->event->getConfig();
    $context = $source->getContext();    
    $model = $destination->getResult();
    if(empty($context['nodes'])) return;

    $model['items'] = []; 
    foreach($context['nodes'] as $nid => $node){
      $context = ['entity_type' => 'node'];
      $item_source = new EntityModel($node, $context);   
      $element_exec = new ElementExecutable();  
      $model['items'][] = $element_exec->process('logo_item', $item_source, $config);
    }
    $destination->setResult($model);
  }
  
  public function loadRelatedOrganizations(){
      $destination = $this->event->getDestination();
      $source = $this->event->getSource();
      $config = $this->event->getConfig();
      $context = $source->getContext();
      $model = $destination->getResult();

      $current_nid = $source->property('nid');
      $domain_tid = $source->simpleField('field_kiosk_domain','tid');
      $topic_tids = $source->multivalField('field_pg_topics','tid');
      $cur_node = $source->rawSource();
      $weights = [];
      $model['related_organizations'] = [];
      
      // set weight 1 to all nodes
      $node_list = $this->getNodesByDomain($domain_tid); 
      foreach($node_list as $nid => $node){
        if($nid == $current_nid) continue;
        $weights[$nid] = 1;
        // add more weights to matched topics
        if(!empty($node->field_pg_topics['und'])){
          foreach($node->field_pg_topics['und'] as $item){
            if(in_array($item['tid'],$topic_tids))
              $weights[$nid] = $weights[$nid]+1;
          }        
        }
      }
      // weight sort
      $weight_list = array_unique(array_values($weights));
      arsort($weight_list); 
      $total = 0;  $nids = [];
      // pick nodes by weight,randomize on the same weight 
      foreach($weight_list as $weight){
        $nid_list = array_keys(array_intersect($weights, [$weight]));
        $count = min(3-$total, count($nid_list));
        $random_keys = $count <= 1 ? [0] : array_rand($nid_list, $count);
        foreach($random_keys as $key)
          $nids[] = $nid_list[$key];
        $total = count($nids);
        if($total >= 3) break;
      }     
      foreach($nids as $nid){
        $node = $node_list[$nid];
        $context = ['entity_type' => 'node'];
        $item_source = new EntityModel($node, $context);
        $element_exec = new ElementExecutable();
        $model['related_organizations'][] = $element_exec->process('logo_item', $item_source, $config);
      } 
      
      $model['landing_link'] = base_path().drupal_lookup_path('alias','taxonomy/term/'.$domain_tid); 
      
      $destination->setResult($model);
  }
  
  protected function getNodesByDomain($domain_tid){
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'patient_group')          
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_kiosk_domain', 'tid', $domain_tid, '=');
      $result = $query->execute();
      if(isset($result['node'])){
        $nids = array_keys($result['node']);
        $nodes = node_load_multiple($nids);
        return $nodes;
      }
      return [];
  }
  
  public function processLogoTeaser(){
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $cur_nid = $source->property('nid');
    $model['target_link']['url'] = base_path().drupal_lookup_path('alias','node/'.$cur_nid);
    $model['target_link']['title'] = truncate_utf8($model['target_link']['title'], 80, TRUE, TRUE);
    if(($skin=$this->getSkinOptions($cur_nid))!==FALSE){
      $model['styles'][] = $skin;
    }
    $destination->setResult($model);
  }

  public function processOverview(){
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $cur_nid = $source->property('nid');
    if(empty($model['hero_bg']['src'])){
     $model['hero_bg']['src'] = $this->getDomainHeroImage($source);
    } 
    $model['target_link']['url'] = base_path().drupal_lookup_path('alias','node/'.$cur_nid);
    $summary = empty($model['summary']['value']) ? strip_tags($source->simpleField('body','value')) : strip_tags($model['summary']['value']);
    $model['summary']['value'] = truncate_utf8($summary, 300, TRUE, TRUE);
    $destination->setResult($model);
  }
  
  public function getDomainHeroImage($source){
      $domain_tid = $source->simpleField('field_kiosk_domain','tid');
      $domain = taxonomy_term_load($domain_tid);
      $data_source = new KioskDataSource();
      $domain_source = $data_source->entitySource($domain,'taxonomy_term');
      $image_uri = $domain_source->imageField('field_pg_hero_background','uri');
      if(empty($image_uri)){
          $module_path = drupal_get_path('module', 'kiosk_app');
          return base_path().$module_path.'/pattern_lib/kiosk/images/carousel-bg.jpg';
      }
      else{
          return image_style_url('kiosk_hero_image', $image_uri);          
      }
  }
  
}
