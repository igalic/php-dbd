--TEST--
Test function dbd_prepare() by calling it more than or less than its expected arguments
--FILE--
<?php
$extra_arg = "lulz";
var_dump(dbd_prepare( $extra_arg ) );
var_dump(dbd_prepare(  ) );
?>
--EXPECT--
string(8) "prepared"
string(8) "prepared"
