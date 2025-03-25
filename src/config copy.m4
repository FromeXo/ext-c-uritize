dnl config.m4 for extension c_uritize

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([c_uritize],
dnl   [for c_uritize support],
dnl   [AS_HELP_STRING([--with-c_uritize],
dnl     [Include c_uritize support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([c_uritize],
  [whether to enable c_uritize support],
  [AS_HELP_STRING([--enable-c_uritize],
    [Enable c_uritize support])],
  [no])

if test "$PHP_C_URITIZE" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, C_URITIZE_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-c_uritize -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/c_uritize.h"  # you most likely want to change this
  dnl if test -r $PHP_C_URITIZE/$SEARCH_FOR; then # path given as parameter
  dnl   C_URITIZE_DIR=$PHP_C_URITIZE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for c_uritize files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       C_URITIZE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$C_URITIZE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the c_uritize distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-c_uritize -> add include path
  dnl PHP_ADD_INCLUDE($C_URITIZE_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-c_uritize -> check for lib and symbol presence
  dnl LIBNAME=C_URITIZE # you may want to change this
  dnl LIBSYMBOL=C_URITIZE # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_C_URITIZE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your c_uritize library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $C_URITIZE_DIR/$PHP_LIBDIR, C_URITIZE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_C_URITIZE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your c_uritize library.])
  dnl ],[
  dnl   -L$C_URITIZE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(C_URITIZE_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_C_URITIZE, 1, [ Have c_uritize support ])

  PHP_NEW_EXTENSION(c_uritize, c_uritize.c, $ext_shared)
fi
