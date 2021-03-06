<?php

/**
 * @file
 * Generates a first name + last name format.
 */

$plugin = array(
  'title' => t('Name (single line)'),
  'format callback' => 'addressfield_format_name_oneline_generate',
  'type' => 'name',
  'weight' => 0,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_name_oneline_generate(&$format, $address) {
  $format['name_block'] = array(
    '#type' => 'addressfield_container',
    '#attributes' => array('class' => array('addressfield-container-inline', 'name-block')),
    '#weight' => -100,
    // The addressfield is considered empty without a country, hide all fields
    // until one is selected.
    '#access' => !empty($address['country']),
  );
  $format['name_block']['name_line'] = array(
    '#title' => t('Full name'),
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array('name-block'),
      'autocomplete' => 'name',
    ),
    '#size' => 30,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
}
