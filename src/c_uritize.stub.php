<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

/**
 * Parse a URI into its components using uriparser.
 *
 * This function is not meant to validate the given URI,
 * it only breaks it up into it's components.
 *
 * If the URI string can't be parsed, an empty array will be returned.
 * 
 * If no port component is found, the port element will be null,
 * else it will be an int.
 *
 * @param string $uri The URI to parse (e.g., "http://example.com:8080/path")
 * @return array<string, mixed> An array with URI components (e.g., scheme, host, port)
 */
function c_uritize(string $str): array {}
