<?php
/**
 * @file
 * kiosk_entity.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kiosk_entity_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets|node|patient_group|form';
  $field_group->group_name = 'group_assets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_container';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '21',
    'children' => array(
      0 => 'field_pg_hero_logo',
      1 => 'field_pg_round_logo',
      2 => 'field_pg_files',
      3 => 'field_pg_hero_background',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-assets field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_assets|node|patient_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_category|node|patient_group|form';
  $field_group->group_name = 'group_category';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_container';
  $field_group->data = array(
    'label' => 'Category',
    'weight' => '20',
    'children' => array(
      0 => 'field_kiosk_domain',
      1 => 'field_pg_topics',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-category field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_category|node|patient_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|patient_group|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_container';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '22',
    'children' => array(
      0 => 'field_pg_contact',
      1 => 'field_pg_email_receivers',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact|node|patient_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container|node|patient_group|form';
  $field_group->group_name = 'group_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Container',
    'weight' => '1',
    'children' => array(
      0 => 'group_assets',
      1 => 'group_category',
      2 => 'group_contact',
      3 => 'group_general',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-container field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_container|node|patient_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container|taxonomy_term|kiosk_domain|form';
  $field_group->group_name = 'group_container';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'kiosk_domain';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'container',
    'weight' => '1',
    'children' => array(
      0 => 'group_email',
      1 => 'group_general',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-container field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_container|taxonomy_term|kiosk_domain|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_to_organization|taxonomy_term|kiosk_domain|form';
  $field_group->group_name = 'group_email_to_organization';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'kiosk_domain';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_email';
  $field_group->data = array(
    'label' => 'Email To Organization',
    'weight' => '17',
    'children' => array(
      0 => 'field_email_template_to_organiza',
      1 => 'field_email_subject_to_organiza',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-email-to-organization field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_email_to_organization|taxonomy_term|kiosk_domain|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_to_user|taxonomy_term|kiosk_domain|form';
  $field_group->group_name = 'group_email_to_user';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'kiosk_domain';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_email';
  $field_group->data = array(
    'label' => 'Email To User',
    'weight' => '16',
    'children' => array(
      0 => 'field_email_template_to_user',
      1 => 'field_email_subject_to_user',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-email-to-user field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_email_to_user|taxonomy_term|kiosk_domain|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email|taxonomy_term|kiosk_domain|form';
  $field_group->group_name = 'group_email';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'kiosk_domain';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_container';
  $field_group->data = array(
    'label' => 'Email',
    'weight' => '3',
    'children' => array(
      0 => 'group_email_to_organization',
      1 => 'group_email_to_user',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-email field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_email|taxonomy_term|kiosk_domain|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|patient_group|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_container';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '19',
    'children' => array(
      0 => 'body',
      1 => 'field_pg_website',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|patient_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|taxonomy_term|kiosk_domain|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'kiosk_domain';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_container';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '2',
    'children' => array(
      0 => 'field_domain_caption',
      1 => 'field_domain_bg_image',
      2 => 'field_domain_enable',
      3 => 'field_background_video',
      4 => 'field_pg_hero_background',
      5 => 'path',
      6 => 'redirect',
      7 => 'description',
      8 => 'xmlsitemap',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|taxonomy_term|kiosk_domain|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assets');
  t('Category');
  t('Contact');
  t('Container');
  t('Email');
  t('Email To Organization');
  t('Email To User');
  t('General');
  t('container');

  return $field_groups;
}
