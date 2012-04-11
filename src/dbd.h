#ifndef PHP_DBD_H
#define PHP_DBD_H 1

#define PHP_DBD_VERSION "0.1"
#define PHP_DBD_EXTNAME "DBD"
#define DBD_NS "dbd"

# include <httpd.h>
# include <apr_dbd.h>
# include <mod_dbd.h>

PHP_FUNCTION(prepare);

struct dbd_t {
  request_rec *r;
  ap_dbd_t *d;
  const char *pool;
};

extern zend_module_entry dbd_module_entry;
#define phpext_dbd_ptr &dbd_module_entry

#endif
