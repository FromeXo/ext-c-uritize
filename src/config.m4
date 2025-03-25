PHP_ARG_ENABLE([c_uritize],
  [whether to enable c_uritize support],
  [AS_HELP_STRING([--enable-c_uritize],
    [Enable c_uritize support])],
  [no])

dnl PHP_ARG_WITH([uriparser],
dnl   [for uriparser support],
dnl   [AS_HELP_STRING([--with-uriparser],
dnl     [Include uriparser support])],
dnl   [no])


if test "$PHP_C_URITIZE" != "no"; then
  
  dnl AC_DEFINE(HAVE_C_URITIZE, 1, [ Have c_uritize support ])

  dnl if test "$PHP_URIPARSER" != "no"; then
  dnl   PKG_CHECK_MODULES([LIBURIPARSER], [liburiparser],
  dnl   [
  dnl     PHP_EVAL_INCLINE($LIBURIPARSER_CFLAGS)
  dnl     PHP_EVAL_LIBLINE($LIBURIPARSER_LIBS, C_URITIZE_SHARED_LIBADD)
  dnl     AC_DEFINE(HAVE_LIBURIPARSER, 1, [ Have liburiparser support ])
  dnl   ],[
  dnl     AC_MSG_ERROR([liburiparser not found via pkg-config])
  dnl   ])
  dnl fi
  
  PHP_ADD_INCLUDE([$ext_srcdir/lib])
  PHP_SUBST(C_URITIZE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(c_uritize, c_uritize.c, $ext_shared)
fi
