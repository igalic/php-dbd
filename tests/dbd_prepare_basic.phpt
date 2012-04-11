--TEST--
Test function dbd_prepare() by calling it with its expected arguments
--SKIPIF--
<?php 
	if (!extension_loaded('dbd')) print 'skip dbd extension not available';
?>
--FILE--
<?php
var_dump( dbd\prepare() );
?>
--EXPECT--
string(8) "prepared"
