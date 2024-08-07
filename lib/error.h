#ifndef ERROR_H
#define ERROR_H

#include "unp.h"
#include <stdarg.h>
#include <syslog.h>

static void err_doit(int, int, const char *, va_list);
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);

#endif //ERROR_H

