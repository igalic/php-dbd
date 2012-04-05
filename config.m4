PHP_ARG_ENABLE(dbd, whether to enable dbd support,
[ --enable-dbd   Enable dbd support])

if test "$PHP_DBD" = "yes"; then
  AC_DEFINE(HAVE_DBD, 1, [Whether you have dbd])
  PHP_NEW_EXTENSION(dbd, src/dbd.c, $ext_shared)
fi

