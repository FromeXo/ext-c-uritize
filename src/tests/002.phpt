--TEST--
Ret arr contains empty values
--EXTENSIONS--
c_uritize
--FILE--
<?php
$ret = c_uritize("");
var_dump($ret);
?>
--EXPECT--
array(7) {
  ["uri"]=>
  string(0) ""
  ["userinfo"]=>
  string(0) ""
  ["host"]=>
  string(0) ""
  ["port"]=>
  NULL
  ["path"]=>
  string(0) ""
  ["query"]=>
  string(0) ""
  ["fragment"]=>
  string(0) ""
}