/* c_uritize extension for PHP */

#ifndef PHP_C_URITIZE_H
# define PHP_C_URITIZE_H

extern zend_module_entry c_uritize_module_entry;
# define phpext_c_uritize_ptr &c_uritize_module_entry

#define PHP_C_URITIZE_EXTNAME "c_uritize"
/* Verson */
#define PHP_C_URITIZE_VER_MAJOR   0
#define PHP_C_URITIZE_VER_MINOR   1
#define PHP_C_URITIZE_VER_RELEASE 0
#define PHP_C_URITIZE_VER_FULL "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_C_URITIZE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_C_URITIZE_H */
