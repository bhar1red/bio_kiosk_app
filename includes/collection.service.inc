<?php

function kiosk_app_collection_service_resource() {
    $api = array(
        'kiosk-app-get-email' => array(
            'operations' => array(
                'index' => array(
                    'help' => 'Retrieves email based on QR Scan data',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'kiosk_app',
                        'name' => 'includes/collection.service',
                    ),
                    'callback' => 'kiosk_app_service_email_get',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                )
            )
        ),
        'kiosk-app-email-submit' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Process email submit for Kiosk App',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'kiosk_app',
                        'name' => 'includes/collection.service',
                    ),
                    'callback' => 'kiosk_app_service_email_submit',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'node_id',
                            'type' => 'string',
                            'description' => 'Node Id',
                            'source' => 'data',
                            'optional' => FALSE,
                            'default' => '0'
                        ),               
                        array(
                            'name' => 'email',
                            'type' => 'string',
                            'description' => 'Email Id',
                            'source' => 'data', 
                            'optional' => FALSE,
                            'default' => '0'
                        ),
                    ),
                ),
            ),
        ),
    );
    
    return $api;
}

/**
 * Returns api data .
 * @param $email
 * @return array
 * 	 the processed data array.
 */
function kiosk_app_service_email_get() {
    $barcode= $_GET['barcode'];
    $base = variable_get('kiosk_app_api_base');
    $apikey=variable_get('kiosk_app_api_key');
    $actcode=variable_get('kiosk_app_act_code');
    $badgeid=variable_get('kiosk_app_api_badge_id');
    $url = $base.'?apikey='.$apikey.'&actcode='.$actcode.'&badgeid='.$badgeid.'&barcode='.$barcode;
    $request = drupal_http_request($url);
    $user_data = drupal_json_decode($request->data);
        
    //$user_email = $user_data['LeadInfo']['Email'];
    //return $user_email;
    if(!empty($user_data['LeadInfo'])){
        return $user_data['LeadInfo'];
    }
    else{
        throw 500;
    }
    
}


/**
 * Returns api data .
 * @param $email
 * @return array
 * 	 the processed data array.
 */
function kiosk_app_service_email_submit($data) {

    $nid= $data['node_id'];
    $name = !empty($data['name'])? $data['name'] : "";
    $email = !empty($data['email'])? $data['email'] : "";
    
    $node = node_load($nid);
    $data_source = new KioskDataSource();
    $app = new StandardApp();
    $source = $data_source->nodeSource($node);

    $org_emails = $source->multivalField('field_pg_email_receivers','value');
    $org_emails = implode(',',$org_emails);
    
    $from_email = $base = variable_get('kiosk_from_email');
    
    $vars['component'] = $app->getElement('org_detail_page',$source);
    
    $user_greeting = !empty($name)? 'Dear '.$name.',' : '';
    
    $user_data = $data['user_data'];
    
    $lead_id = !empty($user_data['LeadID'])? $user_data['LeadID'] : 00;
    $org_page_title = $vars['component']['model']['title']['value'];

    $domain_tid = $source->simpleField('field_kiosk_domain','tid');
    $domain = taxonomy_term_load($domain_tid);
    $org_page_domain = $domain->name;
    
    $user_variables = [
        '!user_email' => $email,
        '!user_name' => $name,
        '!user_greeting' => $user_greeting,
        '!user_leadID' => !empty($user_data['LeadID'])? $user_data['LeadID'] : '',
        '!user_firstName' => !empty($user_data['FirstName'])? $user_data['FirstName'] : '',
        '!user_lastName' => !empty($user_data['LastName'])? $user_data['LastName'] : '',
        '!user_title' => !empty($user_data['Title'])? $user_data['Title'] : '',
        '!user_company' => !empty($user_data['Company'])? $user_data['Company'] : '',
        '!user_city' => !empty($user_data['City'])? $user_data['City'] : '',
        '!user_stateCode' => !empty($user_data['StateCode'])? $user_data['StateCode'] : '',
    ];
    
    
    //Email to User 
    $email_body = format_string($vars['component']['model']['user_mail']['mailto']['body'], $user_variables);
    $email_subject = format_string($vars['component']['model']['user_mail']['mailto']['subject'], $user_variables);

    $attachments = [];

    if(!empty($node->field_pg_files)){
        foreach($node->field_pg_files['und'] as $file){
            $attachments[] = array(
                'filecontent' => file_get_contents($file['uri']),
                'filename' => $file['filename'],
                'filemime' => $file['filemime'],
            );
        }
    }
    
    $params = array(
        'body' => $email_body,
        'subject'=> $email_subject,
    );
    if(isset($attachments)){
        $params['attachments'] = $attachments;
    }
    try{
        //Save record 
        $data_source->saveSubscriberInfo($lead_id, $email, $nid, $org_page_title, $org_page_domain);
                
        if(!empty($email)){
            drupal_mail('kiosk_app', 'kiosk-email', $email, language_default(), $params, $from = $from_email, $send = TRUE);
        }
        
        //Email to Organization
        if(!empty($org_emails)){
            $email_subject = format_string($vars['component']['model']['org_mail']['mailto']['subject'], $user_variables);
            $email_body = format_string($vars['component']['model']['org_mail']['mailto']['body'], $user_variables);
            drupal_mail('kiosk_app', 'kiosk-email', $org_emails, language_default(), $params = array('body' => $email_body, 'subject'=> $email_subject), $from = $from_email, $send = TRUE);
        }
        
    }
    catch(Exception $e){
        throw $e;
    }
    
    return $email; 
}


