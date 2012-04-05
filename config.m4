PHP_ARG_ENABLE(dbd, whether to enable dbd support,
[  --enable-dbd   Enable dbd support])

if test "$PHP_DBD" = "yes"; then
  AC_DEFINE(HAVE_DBD, 1, [Whether you have dbd])
  PHP_NEW_EXTENSION(dbd, src/dbd.c, $ext_shared)
fi


PHP_ARG_WITH(apxs2,,
[  --with-apxs2[=FILE]    pathname to the Apache apxs tool [apxs]], no, no)

AC_MSG_CHECKING([for Apache 2.0 handler-module support via DSO through APXS])

if test "$PHP_APXS2" != "no"; then
  if test "$PHP_APXS2" = "yes"; then
    APXS=apxs
    $APXS -q CFLAGS >/dev/null 2>&1
    if test "$?" != "0" && test -x /usr/sbin/apxs; then
      APXS=/usr/sbin/apxs
    fi
  else
    PHP_EXPAND_PATH($PHP_APXS2, APXS)
  fi

  $APXS -q CFLAGS >/dev/null 2>&1
  if test "$?" != "0"; then
    AC_MSG_RESULT()
    AC_MSG_RESULT()
    AC_MSG_RESULT([Sorry, I cannot run apxs.  Possible reasons follow:]) 
    AC_MSG_RESULT()
    AC_MSG_RESULT([1. Perl is not installed])
    AC_MSG_RESULT([2. apxs was not found. Try to pass the path using --with-apxs2=/path/to/apxs])
    AC_MSG_RESULT([3. Apache was not built using --enable-so (the apxs usage page is displayed)])
    AC_MSG_RESULT()
    AC_MSG_RESULT([The output of $APXS follows:])
    $APXS -q CFLAGS
    AC_MSG_ERROR([Aborting])
  fi 

  APXS_INCLUDEDIR=`$APXS -q INCLUDEDIR`
  APXS_CFLAGS=`$APXS -q CFLAGS`
  APU_BINDIR=`$APXS -q APU_BINDIR`
  APR_BINDIR=`$APXS -q APR_BINDIR`

  # Pick up ap[ru]-N-config if using httpd >=2.1
  APR_CONFIG=`$APXS -q APR_CONFIG 2>/dev/null ||
    echo $APR_BINDIR/apr-config`
  APU_CONFIG=`$APXS -q APU_CONFIG 2>/dev/null ||
    echo $APU_BINDIR/apu-config`

  APR_CFLAGS="`$APR_CONFIG --cppflags --includes`"
  APU_CFLAGS="`$APU_CONFIG --includes`"

  for flag in $APXS_CFLAGS; do
    case $flag in
    -D*) APACHE_CPPFLAGS="$APACHE_CPPFLAGS $flag";;
    esac
  done

  CFLAGS="$CFLAGS $APACHE_CPPFLAGS -I$APXS_INCLUDEDIR $APR_CFLAGS $APU_CFLAGS"

  # always build thread safe:
  #PHP_BUILD_THREAD_SAFE

  LDFLAGS="$LDFLAGS `$APR_CONFIG --ldflags --link-ld --libs`"
  LDFLAGS="$LDFLAGS `$APU_CONFIG --ldflags --link-ld --libs` $MH_BUNDLE_FLAGS"

  PHP_SUBST(LDFLAGS)
  PHP_SUBST(CFLAGS)
  AC_MSG_RESULT(yes)
  PHP_SUBST(APXS)
else
  AC_MSG_RESULT(no)
fi

