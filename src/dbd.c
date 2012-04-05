#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "dbd.h"
#include <apr_dbd.h>
#include <mod_dbd.h>

static zend_function_entry dbd_functions[] = {
    PHP_FE(dbd_prepare, NULL)
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
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20100525
    PHP_DBD_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_DBD
ZEND_GET_MODULE(dbd)
#endif

PHP_FUNCTION(dbd_prepare)
{
    RETURN_STRING("prepared", 1);
}

