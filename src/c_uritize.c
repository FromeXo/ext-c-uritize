/* c_uritize extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_c_uritize.h"
#include "c_uritize_arginfo.h"
#include "lib/uriparser/include/uriparser/Uri.h"
#include "lib/uriparser/include/uriparser/UriBase.h"
//#include "uriparser/Uri.h"
//#include "uriparser/UriBase.h"

PHP_FUNCTION(c_uritize)
{
	// php function arguments.
	char *uriStr;
	size_t uriStrLen;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(uriStr, uriStrLen)
	ZEND_PARSE_PARAMETERS_END();

	zval ret;

	// Information about the recognized parts
	UriUriA uri;
	// points to the first character starting invalid syntax
	const char * errorPos;

	if (uriParseSingleUriA(&uri, uriStr, &errorPos) != URI_SUCCESS) {
		/* Failure (no need to call uriFreeUriMembersA) */
		array_init_size(&ret, 0);
		RETURN_ZVAL(&ret, 1, 1);
    }

	// Init the php array we will return with 8 elements.
	array_init_size(&ret, 8);
	add_assoc_string(&ret, "uri", "");
	add_assoc_string(&ret, "scheme", "");
	add_assoc_string(&ret, "userinfo", "");
	add_assoc_string(&ret, "host", "");
	add_assoc_null(&ret, "port");
	add_assoc_string(&ret, "path", "");
	add_assoc_string(&ret, "query", "");
	add_assoc_string(&ret, "fragment", "");

	size_t
		schemeLen = uri.scheme.afterLast - uri.scheme.first, 
        userLen = uri.userInfo.afterLast - uri.userInfo.first,
		hostLen = uri.hostText.afterLast - uri.hostText.first,
		portLen = uri.portText.afterLast - uri.portText.first,
		pathLen = 0,
		fragLen = uri.fragment.afterLast - uri.fragment.first,
		queyLen = uri.query.afterLast    - uri.query.first;
	
	if (uriStrLen > 0) {
		add_assoc_string(&ret, "uri", uriStr);
	}

	if (schemeLen > 0) {
		char *scheme = ecalloc(schemeLen +1, sizeof(char));
		strncpy(scheme, uri.scheme.first, schemeLen);
		scheme[schemeLen+1] = '\0';
		add_assoc_string(&ret, "scheme", scheme);
		efree(scheme);
	}

	if (userLen > 0) {
		char *user = ecalloc(userLen + 1, sizeof(char));
		strncpy(user, uri.userInfo.first, userLen);
		add_assoc_string(&ret, "userinfo", user);
		efree(user);
	} 

	if (hostLen > 0) {
		char *host = ecalloc(hostLen + 1, sizeof(char));
		strncpy(host, uri.hostText.first, hostLen);
		add_assoc_string(&ret, "host", host);
		efree(host);
	}
	
	if (portLen > 0) {
		char *port = ecalloc(portLen + 1, sizeof(char));
		strncpy(port, uri.portText.first, portLen);
		char *endptr;
		add_assoc_long(&ret, "port", strtoul(port, &endptr, 10));
		efree(port);
	}

	if (uri.pathHead > 0) {
		UriPathSegmentA *segment = uri.pathHead;

		while (segment) {
            pathLen += (segment->text.afterLast - segment->text.first) + 1;
            segment = segment->next;
        }
		char *path = ecalloc(pathLen, sizeof(char));
		strncpy(path, uri.pathHead->text.first, pathLen - 1);
		add_assoc_string(&ret, "path", path);
		efree(path);
	}

	if (queyLen > 0) {
		char *query = ecalloc(queyLen + 1, sizeof(char));
		strncpy(query, uri.query.first, queyLen);
		add_assoc_string(&ret, "query", query);
		efree(query);
	}
		
	if (fragLen > 0) {
		char *fragment = ecalloc(fragLen + 1, sizeof(char));
		strncpy(fragment, uri.fragment.first, fragLen);
		add_assoc_string(&ret, "fragment", fragment);
		efree(fragment);
	}

    uriFreeUriMembersA(&uri);
	
	RETURN_ZVAL(&ret, 1, 1);
}


PHP_RINIT_FUNCTION(c_uritize)
{
	#if defined(ZTS) && defined(COMPILE_DL_C_URITIZE)
		ZEND_TSRMLS_CACHE_UPDATE();
	#endif

	return SUCCESS;
}

PHP_MINFO_FUNCTION(c_uritize)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_C_URITIZE_EXTNAME, "enabled");
	php_info_print_table_row(2, "Version", PHP_C_URITIZE_VER_FULL);
	php_info_print_table_row(2, "Built with uriparser", URI_VER_ANSI);
	php_info_print_table_end();
}

zend_module_entry c_uritize_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_C_URITIZE_EXTNAME,		    /* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(c_uritize),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(c_uritize),			/* PHP_MINFO - Module info */
	PHP_C_URITIZE_VER_FULL,			/* Version */
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_C_URITIZE
	# ifdef ZTS
		ZEND_TSRMLS_CACHE_DEFINE()
	# endif
	ZEND_GET_MODULE(c_uritize)
#endif
