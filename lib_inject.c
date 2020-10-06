#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

static void *(*real_clGEFA)(char *) = NULL;

void *clGetExtensionFunctionAddress(char *fname)
{
	if (!strcmp(fname, "clGetGLContextInfoKHR"))
		return NULL;

	if (!real_clGEFA)
		real_clGEFA = dlsym(RTLD_NEXT, "clGetExtensionFunctionAddress");

	return real_clGEFA(fname);
}

