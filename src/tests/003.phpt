--TEST--
Ret arr contains parsed and empty values
--EXTENSIONS--
c_uritize
--FILE--
<?php
var_dump(c_uritize("http://example.com"));
?>
--EXPECT--
array(8) {
  ["uri"]=>
  string(18) "http://example.com"
  ["userinfo"]=>
  string(0) ""
  ["host"]=>
  string(11) "example.com"
  ["port"]=>
  NULL
  ["path"]=>
  string(0) ""
  ["query"]=>
  string(0) ""
  ["fragment"]=>
  string(0) ""
  ["scheme"]=>
  string(4) "http"
}
