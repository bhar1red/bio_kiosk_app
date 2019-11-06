<?php

class BaseHandler {
  
  protected $event;

  protected $skin_options = [
    'purple-skin',
    'orange-skin',
    'teal-skin',
    'green-skin'
  ]; 

  protected function buildMenu($terms, $activeIndex){
    $items=[];
    for( $i=0; $i < count($terms); $i++){
       $item = [];
       $item['link']['url'] = base_path().drupal_lookup_path('alias','taxonomy/term/'.$terms[$i]->tid); 
       $item['link']['title'] = $terms[$i]->name;
       if($i==$activeIndex){
           $item['active'] = 1;
       }
       $item['styles'] = [$this->skin_options[$i]]; 
       $items[] = $item;
    }
    return $items;
  }
  
}
