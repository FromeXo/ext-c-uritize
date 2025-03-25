--TEST--
Ret arr returns all parsed values
--EXTENSIONS--
c_uritize
--FILE--
<?php
var_dump(c_uritize("https://user:password@www.example.com:8080/path/to/resource?key1=value1&key2=value2#section1"));
?>
--EXPECT--
array(8) {
  ["uri"]=>
  string(92) "https://user:password@www.example.com:8080/path/to/resource?key1=value1&key2=value2#section1"
  ["userinfo"]=>
  string(13) "user:password"
  ["host"]=>
  string(15) "www.example.com"
  ["port"]=>
  int(8080)
  ["path"]=>
  string(16) "path/to/resource"
  ["query"]=>
  string(23) "key1=value1&key2=value2"
  ["fragment"]=>
  string(8) "section1"
  ["scheme"]=>
  string(5) "https"
}
