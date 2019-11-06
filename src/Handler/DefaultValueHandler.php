<?php

class DefaultValueHandler extends BaseHandler {

  protected $data_source;
  protected $app;
  /**
   * Constructor
   */
  public function __construct() {
      $this->data_source = new KioskDataSource();
      $this->app = new StandardApp();
  }

  public function getDefaultValue($term) {
     
      switch($term){
          case 'user_email_subject': 
              return $this->getDefaultEmailSubjectToUser();
          case 'user_email_template':
              return $this->getDefaultEmailTemplateToUser();
          case 'org_email_subject':
              return $this->getDefaultEmailSubjectToOrganization();
          case 'org_email_template':
              return $this->getDefaultEmailTemplateToOrganization();
      }
  }
  
  function getDefaultEmailSubjectToUser(){
      $template = 'Info requested on !org_name';
      return $template;
  }
  
  function getDefaultEmailTemplateToUser(){
      $context = [];
      $source = $this->data_source->nullSource($context);
      $element = $this->app->getElement('email_to_user',$source);
      $template = TPLRender::component([],$element['tpl']);
      return $template;
  }
  
  function getDefaultEmailSubjectToOrganization(){
      $template = 'New Connection for !org_name: !user_email';
      return $template;
  }
  
  function getDefaultEmailTemplateToOrganization(){
      $context = [];
      $source = $this->data_source->nullSource($context);
      $element = $this->app->getElement('email_to_org',$source);
      $template = TPLRender::component([],$element['tpl']);
      return $template;
  }
}