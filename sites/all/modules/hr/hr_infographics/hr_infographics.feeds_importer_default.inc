<?php
/**
 * @file
 * hr_infographics.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_infographics_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_infographic_types';
  $feeds_importer->config = array(
    'name' => 'Infographic Types',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Name:en',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name:fr',
            'target' => 'name_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Name:es',
            'target' => 'name_field:et:es',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_infographic_type',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_infographic_types'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_infographics';
  $feeds_importer->config = array(
    'name' => 'Infographics',
    'description' => 'Import infographics from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'Title:en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Title:fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Title:es',
            'target' => 'title_field:et:es',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Type',
            'target' => 'field_infographic_type:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Description',
            'target' => 'body:et:und',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Description',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'File',
            'target' => 'field_files_collection:field_file',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Language',
            'target' => 'field_files_collection:field_language',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Sectors',
            'target' => 'field_sectors:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Clusters/Sectors',
            'target' => 'field_bundles:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Publication Date',
            'target' => 'field_publication_date:start',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Organization',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Coordination hubs',
            'target' => 'field_coordination_hubs:label',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Locations',
            'target' => 'field_locations:label',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Fundings',
            'target' => 'field_funding_methods:label',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Themes',
            'target' => 'field_themes:label',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Disasters',
            'target' => 'field_disasters:label',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Spaces',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'Post date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Author',
            'target' => 'user_mail',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'Path',
            'target' => 'path_alias',
            'pathauto_override' => 1,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_infographic',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_infographics'] = $feeds_importer;

  return $export;
}
