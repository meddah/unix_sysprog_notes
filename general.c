#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include "general.h"

void err_sys(const char *format, ...)
{
	va_list ap;
	char buf[1024];
		
	va_start(ap, format);
	
	vsnprintf(buf, 1024, format, ap);
	snprintf(buf + strlen(buf), 1024 - strlen(buf), ": %s\n", strerror(errno));
	fflush(stdout);
	fputs(buf, stderr);
	
	va_end(ap);
	exit(EXIT_FAILURE);
}

void err_noexit(const char *format, ...)
{
	va_list ap;
	char buf[1024];
		
	va_start(ap, format);
	
	vsnprintf(buf, 1024, format, ap);
	snprintf(buf + strlen(buf), 1024 - strlen(buf), ": %s\n", strerror(errno));
	fflush(stdout);
	fputs(buf, stderr);
	
	va_end(ap);
}

void err_usr(const char *format, ...)
{
	va_list ap;
	char buf[1024];
		
	va_start(ap, format);
	
	vsnprintf(buf, 1024, format, ap);
	
	fflush(stdout);
	fputs(buf, stderr);
	
	va_end(ap);
	exit(EXIT_FAILURE);
}


void err_sys2(const char *msg)
{
	perror(msg);
	fflush(stdout);
	exit(EXIT_FAILURE);
}

#if 0

int main(void)
{
	

	return EXIT_SUCCESS;
}

#endif
