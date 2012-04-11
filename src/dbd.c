#ifndef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "php.h"
#include "TSRM.h"
#include "SAPI.h"
#include "php_dbd.h"
#include <apr_dbd.h>
#include <mod_dbd.h>

ZEND_DECLARE_MODULE_GLOBALS(dbd)

static zend_function_entry dbd_functions[] = {
  ZEND_NS_FE(DBD_NS, prepare, NULL)
  {NULL, NULL, NULL}
};

zend_module_entry dbd_module_entry = {
#if ZEND_MODULE_API_NO >= 20100525
  STANDARD_MODULE_HEADER,
#endif
  PHP_DBD_EXTNAME,
  dbd_functions,
  NULL,
  NULL,
  PHP_RINIT(dbd),
  PHP_RSHUTDOWN(dbd),
  NULL,
#if ZEND_MODULE_API_NO >= 20100525
  PHP_DBD_VERSION,
#endif
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_DBD
ZEND_GET_MODULE(dbd)
#endif

static void
php_dbd_init_globals(zend_dbd_globals *dbd_globals)
{
  dbd_globals->r = NULL;
  dbd_globals->d = NULL;
  dbd_globals->pool = NULL;
}

PHP_RINIT_FUNCION(dbd TSRMLS_CC)
{
  DBD_G(r) = SG(server_context);
  return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(dbd)
{
  DBD_G(r) = NULL;
  DBD_G(d) = NULL;
  if (DBD_G(pool)) efree(DBD_G(pool));
  DBD_G(pool) = NULL;

  return SUCCESS;
}

PHP_FUNCTION(prepare)
{
    RETURN_STRING("prepared", 1);
}

