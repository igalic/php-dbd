--TEST--
Test function dbd_prepare() by calling it more than or less than its expected arguments
--SKIPIF--
<?php 
	if (!extension_loaded('dbd')) print 'skip dbd extension not available';
?>
--FILE--
<?php
$extra_arg = "lulz";
var_dump(dbd\prepare( $extra_arg ) );
var_dump(dbd\prepare(  ) );
?>
--EXPECT--
string(8) "prepared"
string(8) "prepared"
