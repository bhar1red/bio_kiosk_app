<?php

/**
 * @file
 * kiosk_entity.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function kiosk_entity_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-patient_group-body'.
  $field_instances['node-patient_group-body'] = array(
    'bundle' => 'patient_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Maximum character count for summary is 210.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_kiosk_domain'.
  $field_instances['node-patient_group-field_kiosk_domain'] = array(
    'bundle' => 'patient_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kiosk_domain',
    'label' => 'Kiosk Domain',
    'required' => 1,
    'settings' => array(
      'description_display' => 'after',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_contact'.
  $field_instances['node-patient_group-field_pg_contact'] = array(
    'bundle' => 'patient_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_contact',
    'label' => 'Key Organization Contacts',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'partner_contact' => 'partner_contact',
        'toolkit_infographic_component' => -1,
      ),
      'bundle_weights' => array(
        'partner_contact' => 2,
        'toolkit_infographic_component' => 3,
      ),
      'default_edit_mode' => 'preview',
      'description_display' => 'after',
      'title' => 'Contact',
      'title_multiple' => 'Contacts',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_email_receivers'.
  $field_instances['node-patient_group-field_pg_email_receivers'] = array(
    'bundle' => 'patient_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_email_receivers',
    'label' => 'Email Receivers',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_files'.
  $field_instances['node-patient_group-field_pg_files'] = array(
    'bundle' => 'patient_group',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_files',
    'label' => 'File Attachments',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt pdf doc docx xls xlsx ppt pptx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_hero_background'.
  $field_instances['node-patient_group-field_pg_hero_background'] = array(
    'bundle' => 'patient_group',
    'deleted' => 0,
    'description' => 'Keep left side of image plain and light to avoid readability issues. Image will auto scale and crop to preferred resolution 1260x400.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_hero_background',
    'label' => 'Hero Background',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'description_display' => 'after',
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_hero_logo'.
  $field_instances['node-patient_group-field_pg_hero_logo'] = array(
    'bundle' => 'patient_group',
    'deleted' => 0,
    'description' => 'Image will auto scale and crop to preferred resolution 300x200. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_hero_logo',
    'label' => 'Hero Logo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'description_display' => 'after',
      'file_directory' => 'images/organization',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_round_logo'.
  $field_instances['node-patient_group-field_pg_round_logo'] = array(
    'bundle' => 'patient_group',
    'deleted' => 0,
    'description' => 'Image will auto scale and crop to preferred resolution 200x200. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_round_logo',
    'label' => 'Round Logo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'description_display' => 'after',
      'file_directory' => 'images/organization',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_topics'.
  $field_instances['node-patient_group-field_pg_topics'] = array(
    'bundle' => 'patient_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_topics',
    'label' => 'Topics',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-patient_group-field_pg_website'.
  $field_instances['node-patient_group-field_pg_website'] = array(
    'bundle' => 'patient_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pg_website',
    'label' => 'Organization Website',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'description_display' => 'after',
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-partner_contact-field_rep_email'.
  $field_instances['paragraphs_item-partner_contact-field_rep_email'] = array(
    'bundle' => 'partner_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rep_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-partner_contact-field_rep_name'.
  $field_instances['paragraphs_item-partner_contact-field_rep_name'] = array(
    'bundle' => 'partner_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rep_name',
    'label' => 'Name',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-partner_contact-field_rep_onsite'.
  $field_instances['paragraphs_item-partner_contact-field_rep_onsite'] = array(
    'bundle' => 'partner_contact',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rep_onsite',
    'label' => 'On site at Event',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-partner_contact-field_rep_phone'.
  $field_instances['paragraphs_item-partner_contact-field_rep_phone'] = array(
    'bundle' => 'partner_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_rep_phone',
    'label' => 'Phone',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_background_video'.
  $field_instances['taxonomy_term-kiosk_domain-field_background_video'] = array(
    'bundle' => 'kiosk_domain',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_background_video',
    'label' => 'Background Video',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'description_field' => 0,
      'file_directory' => 'videos',
      'file_extensions' => 'mov mp4',
      'max_filesize' => '100 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 0,
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_domain_bg_image'.
  $field_instances['taxonomy_term-kiosk_domain-field_domain_bg_image'] = array(
    'bundle' => 'kiosk_domain',
    'deleted' => 0,
    'description' => 'Image will auto scale and crop to preferred resolution 1080x1920. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_domain_bg_image',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'description_display' => 'after',
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-kiosk_domain-field_domain_caption'.
  $field_instances['taxonomy_term-kiosk_domain-field_domain_caption'] = array(
    'bundle' => 'kiosk_domain',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_domain_caption',
    'label' => 'Caption',
    'required' => 1,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-kiosk_domain-field_domain_enable'.
  $field_instances['taxonomy_term-kiosk_domain-field_domain_enable'] = array(
    'bundle' => 'kiosk_domain',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_domain_enable',
    'label' => 'Enabled',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_email_subject_to_organiza'.
  $field_instances['taxonomy_term-kiosk_domain-field_email_subject_to_organiza'] = array(
    'bundle' => 'kiosk_domain',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Supports same tokens as template. 
Default Value: New Connection for !org_name: !user_email',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_email_subject_to_organiza',
    'label' => 'Email Subject To Organization',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_email_subject_to_user'.
  $field_instances['taxonomy_term-kiosk_domain-field_email_subject_to_user'] = array(
    'bundle' => 'kiosk_domain',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Supports same tokens as template. 
Default Value: Info requested on !org_name',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_email_subject_to_user',
    'label' => 'Email Subject To User',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_email_template_to_organiza'.
  $field_instances['taxonomy_term-kiosk_domain-field_email_template_to_organiza'] = array(
    'bundle' => 'kiosk_domain',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Supported Tokens: <br> <br> 
User Tokens: <br>
         \'!user_email\' => User Email,
        \'!user_name\' => Name ,
        \'!user_greeting\' => User Greeting (Dear !user_name, ), 
        \'!user_leadID\' => User\'s Lead ID,
       \'!user_firstName\' => First Name of User, 
       \'!user_lastName\' => Last Name of User, 
       \'!user_title\'=> User Title
       \'!user_company\' => Comapny
        \'!user_city\' => City
       \'!user_stateCode\' => State Code <br/> 
 
Organization Tokens: <br/>
          \'!org_name\' => Organization Name,
          \'!org_domain\' => Organization Domain,
          \'!org_summary\' => Summary,
          \'!org_website\' => website,
          \'!org_description\' => description,
          \'!org_link\' => Link to the page,
          \'!org_contact\' => Contact Info Widget,
          \'!org_logo\' => Logo URL ,
          \'!convention_title\' => Convention Title (Can be configured in kisok config form. Default Value: BIO 2019),
          \'!org_header_background\' => Email header background (Static),
          \'!bio_link\' => Link to bio.org ,
          \'!bio_logo\' => Bio Logo ,
          \'!email_disclaimer\' => Email Disclaimer ,
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_email_template_to_organiza',
    'label' => 'Email Template To Organization',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_email_template_to_user'.
  $field_instances['taxonomy_term-kiosk_domain-field_email_template_to_user'] = array(
    'bundle' => 'kiosk_domain',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Supported Tokens: <br> <br> 
User Tokens: <br>
         \'!user_email\' => User Email,
        \'!user_name\' => Name ,
        \'!user_greeting\' => User Greeting (Dear !user_name, ), <br> 
Organization Tokens: <br/>
          \'!org_name\' => Organization Name,
          \'!org_domain\' => Organization Domain,
          \'!org_summary\' => Summary,
          \'!org_website\' => website,
          \'!org_description\' => description,
          \'!org_link\' => Link to the page,
          \'!org_contact\' => Contact Info Widget,
          \'!org_logo\' => Logo URL ,
          \'!convention_title\' => Convention Title (Can be configured in kisok config form. Default Value: BIO 2019), 
          \'!org_header_background\' => Email header background (Static),
          \'!bio_link\' => Link to bio.org ,
          \'!bio_logo\' => Bio Logo ,
          \'!email_disclaimer\' => Email Disclaimer ,
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_email_template_to_user',
    'label' => 'Email Template To User',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-kiosk_domain-field_pg_hero_background'.
  $field_instances['taxonomy_term-kiosk_domain-field_pg_hero_background'] = array(
    'bundle' => 'kiosk_domain',
    'deleted' => 0,
    'description' => 'Carousel background. If kiosk item do not have a background image set, it would use this one. 

',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_pg_hero_background',
    'label' => 'Carousel background',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'description_display' => 'after',
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Image');
  t('Background Video');
  t('Caption');
  t('Carousel background');
  t('Carousel background. If kiosk item do not have a background image set, it would use this one. 

');
  t('Description');
  t('Email');
  t('Email Receivers');
  t('Email Subject To Organization');
  t('Email Subject To User');
  t('Email Template To Organization');
  t('Email Template To User');
  t('Enabled');
  t('File Attachments');
  t('Hero Background');
  t('Hero Logo');
  t('Image will auto scale and crop to preferred resolution 1080x1920. ');
  t('Image will auto scale and crop to preferred resolution 200x200. ');
  t('Image will auto scale and crop to preferred resolution 300x200. ');
  t('Keep left side of image plain and light to avoid readability issues. Image will auto scale and crop to preferred resolution 1260x400.');
  t('Key Organization Contacts');
  t('Kiosk Domain');
  t('Maximum character count for summary is 210.');
  t('Name');
  t('On site at Event');
  t('Organization Website');
  t('Phone');
  t('Round Logo');
  t('Supported Tokens: <br> <br> 
User Tokens: <br>
         \'!user_email\' => User Email,
        \'!user_name\' => Name ,
        \'!user_greeting\' => User Greeting (Dear !user_name, ), 
        \'!user_leadID\' => User\'s Lead ID,
       \'!user_firstName\' => First Name of User, 
       \'!user_lastName\' => Last Name of User, 
       \'!user_title\'=> User Title
       \'!user_company\' => Comapny
        \'!user_city\' => City
       \'!user_stateCode\' => State Code <br/> 
 
Organization Tokens: <br/>
          \'!org_name\' => Organization Name,
          \'!org_domain\' => Organization Domain,
          \'!org_summary\' => Summary,
          \'!org_website\' => website,
          \'!org_description\' => description,
          \'!org_link\' => Link to the page,
          \'!org_contact\' => Contact Info Widget,
          \'!org_logo\' => Logo URL ,
          \'!convention_title\' => Convention Title (Can be configured in kisok config form. Default Value: BIO 2019),
          \'!org_header_background\' => Email header background (Static),
          \'!bio_link\' => Link to bio.org ,
          \'!bio_logo\' => Bio Logo ,
          \'!email_disclaimer\' => Email Disclaimer ,
');
  t('Supported Tokens: <br> <br> 
User Tokens: <br>
         \'!user_email\' => User Email,
        \'!user_name\' => Name ,
        \'!user_greeting\' => User Greeting (Dear !user_name, ), <br> 
Organization Tokens: <br/>
          \'!org_name\' => Organization Name,
          \'!org_domain\' => Organization Domain,
          \'!org_summary\' => Summary,
          \'!org_website\' => website,
          \'!org_description\' => description,
          \'!org_link\' => Link to the page,
          \'!org_contact\' => Contact Info Widget,
          \'!org_logo\' => Logo URL ,
          \'!convention_title\' => Convention Title (Can be configured in kisok config form. Default Value: BIO 2019), 
          \'!org_header_background\' => Email header background (Static),
          \'!bio_link\' => Link to bio.org ,
          \'!bio_logo\' => Bio Logo ,
          \'!email_disclaimer\' => Email Disclaimer ,
');
  t('Supports same tokens as template. 
Default Value: Info requested on !org_name');
  t('Supports same tokens as template. 
Default Value: New Connection for !org_name: !user_email');
  t('Topics');

  return $field_instances;
}
