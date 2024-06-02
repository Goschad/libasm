#ifndef LIBASM_H
#define LIBASM_H

#include "define.h"

/* size_t */

size_t     ft_strlen(const char *s);

/* ssize_t */

ssize_t     ft_read(int fd, void *buf, size_t count);
ssize_t     ft_write(int fd, const void *buf, size_t count);

/* int */

int         ft_strcmp(const char *s1, const char *s2);

/* char * */

char        *ft_strdup(const char *s);
char        *ft_strcpy(char *dest, const char *src);

/* end */

#endif