--TEST--
Ret arr is empty
--EXTENSIONS--
c_uritize
--FILE--
<?php
var_dump(c_uritize(":http://example.com"));
?>
--EXPECT--
array(0) {
}