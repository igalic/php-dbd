--TEST--
Test function dbd_prepare() by calling it with its expected arguments
--FILE--
<?php
var_dump( dbd_prepare() );
?>
--EXPECT--
string(8) "prepared"
