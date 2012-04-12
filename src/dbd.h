#ifndef PHP_DBD_H
#define PHP_DBD_H 1

#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP_DBD_VERSION "0.1"
#define PHP_DBD_EXTNAME "DBD"
#define DBD_NS "dbd"

# include <httpd.h>
# include <apr_dbd.h>
# include <mod_dbd.h>

ZEND_BEGIN_MODULE_GLOBALS(dbd)
  request_rec *r;
  ap_dbd_t *d;
  char *pool;
ZEND_END_MODULE_GLOBALS(dbd)

#ifdef ZTS
#define DBD_G(v) TSRMG(dbd_globals_id, zend_dbd_globals *, v)
#else
#define DBD_G(v) (dbd_globals.v)
#endif

PHP_RINIT_FUNCTION(dbd);
PHP_RSHUTDOWN_FUNCTION(dbd);

PHP_FUNCTION(prepare);

extern zend_module_entry dbd_module_entry;
#define phpext_dbd_ptr &dbd_module_entry

#endif
