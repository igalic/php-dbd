#ifndef PHP_DBD_H
#define PHP_DBD_H 1

#define PHP_DBD_VERSION "0.1"
#define PHP_DBD_EXTNAME "DBD"

PHP_FUNCTION(dbd_prepare);

extern zend_module_entry dbd_module_entry;
#define phpext_dbd_ptr &dbd_module_entry

#endif
