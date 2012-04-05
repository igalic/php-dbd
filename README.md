The goal of this project is to create a PHP extension which provides
a clear, Object Oriented, PHP 5.4 compatible API, using Apache httpd's mod_dbd
as backend.

mod_dbd offers a database interface which equipped with all bells
and whistles one would expect from a full-fletched Application server:
Connection Setup and Teardown, as well as Connection Pooling, Query Preparation

It supports all Databases that apr_dbd supports, while keeping the
interface transparent.

As of this writing [those are](http://httpd.apache.org/docs/current/mod/mod_dbd.html#dbdparams)

* FreeTDS (for MSSQL and SyBase)
* MySQL
* Oracle
* PostgreSQL
* SQLite 2 and 3, as well as
* ODBC


`php-dbd` will only work in an Apache HTTPD environment
under `mod_php` which has `mod_dbd` loaded.

An application's database conneciton must be configured through
`httpd.conf` and. As of yet, it will only work be able to use
one connection per VirtualHost.

There is [bug with a patch](https://issues.apache.org/bugzilla/show_bug.cgi?id=45456)
that addresses this limitation.
