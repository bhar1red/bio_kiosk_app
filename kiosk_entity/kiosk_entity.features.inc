<?php
/**
 * @file
 * kiosk_entity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kiosk_entity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function kiosk_entity_image_default_styles() {
  $styles = array();

  // Exported image style: kiosk_hero_image.
  $styles['kiosk_hero_image'] = array(
    'label' => 'Kiosk Hero Image',
    'effects' => array(
      22 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1260,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kiosk_hero_logo.
  $styles['kiosk_hero_logo'] = array(
    'label' => 'Kiosk Hero Logo',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kiosk_round_logo.
  $styles['kiosk_round_logo'] = array(
    'label' => 'Kiosk Round Logo',
    'effects' => array(
      22 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kiosk_splash_bg.
  $styles['kiosk_splash_bg'] = array(
    'label' => 'Kiosk Splash Background',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1080,
          'height' => 1920,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function kiosk_entity_node_info() {
  $items = array(
    'patient_group' => array(
      'name' => t('Kiosk Page'),
      'base' => 'node_content',
      'description' => t('Kiosk Page for Kiosk App'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function kiosk_entity_paragraphs_info() {
  $items = array(
    'partner_contact' => array(
      'name' => 'Partner Contact',
      'bundle' => 'partner_contact',
      'locked' => '1',
    ),
  );
  return $items;
}
