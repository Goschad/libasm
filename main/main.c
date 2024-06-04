#include "../include/libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* strdup */

void strdup_test(void)
{
    printf("\n=== strdup ===\n\n");
	{
		char *s = "Hello World !";
		char *ret1 = strdup(s);
		char *ret2 = ft_strdup(s);

		printf("STD: [%s] | FT: [%s]\n", ret1, ret2);
		free(ret1); free(ret2);
	}
    {
        char *s = "";
		char *ret1 = strdup(s);
		char *ret2 = ft_strdup(s);

		printf("STD: [%s] | FT: [%s]\n", ret1, ret2);
		free(ret1); free(ret2);
    }
    {
        char *s = LOREM;
		char *ret1 = strdup(s);
		char *ret2 = ft_strdup(s);

		printf("STD && FT: lorem | strcmp: %d\n", strcmp(ret1, ret2));
		free(ret1); free(ret2);
    }
    {
        /* segfault */

        /*char *s = NULL;
		char *ret1 = strdup(s);
		char *ret2 = ft_strdup(s);

		printf("STD: [%s]\n", ret1);
        printf("FT:  [%s]\n", ret2);
		free(ret1); free(ret2);*/
    }
}

/* strcpy */

static void strcpy_test(void)
{
    printf("\n=== strcpy ===\n\n");
	{
	    printf("STD:\n");
	    char *src = "Hello World";
	    char dest[200];

	    char * ret = strcpy(dest, src);
	    printf("src : [%s] [%p]\n", src, src);
	    printf("dest : [%s] | ret = [%s]\n", dest, ret);
	    printf("dest : [%p] | ret = [%p]\n", dest, ret);
	}
	{
	    printf("\nFT:\n");
	    char *src = "Hello World";
	    char dest[200];
        
	    char * ret = ft_strcpy(dest, src);
	    printf("src : [%s] [%p]\n", src, src);
	    printf("dest : [%s] | ret = [%s]\n", dest, ret);
	    printf("dest : [%p] | ret = [%p]\n", dest, ret);
	}
}

/* strcmp */

static void strcmp_test(void)
{
    printf("\n=== strcmp ===\n\n");
    {
        printf("STD:\n");
        char *ret1 = "Hello World !";
        char *ret2 = "Hello Wordk !";
        printf("[%s] && [%s]: %d\n", ret1, ret2, strcmp(ret1, ret2));

        ret1 = "Prout !";
        ret2 = "Ouaf !";
        printf("[%s] && [%s]: %d\n", ret1, ret2, strcmp(ret1, ret2));

        ret1 = "";
        ret2 = "Bing chilling - John Xina";
        printf("[%s] && [%s]: %d\n", ret1, ret2, strcmp(ret1, ret2));

        ret1 = "Miaou !";
        ret2 = "Miaou !";
        printf("[%s] && [%s]: %d\n", ret1, ret2, strcmp(ret1, ret2));

        /* segfault */

        /*ret1 = NULL;
        ret2 = NULL;
        printf("[%s] && [%s] = %d\n", ret1, ret2, strcmp(ret1, ret2));*/
    }
    {
        printf("\nFT:\n");
        char *ret1 = "Hello World !";
        char *ret2 = "Hello Wordk !";
        printf("[%s] && [%s]: %d\n", ret1, ret2, ft_strcmp(ret1, ret2));

        ret1 = "Prout !";
        ret2 = "Ouaf !";
        printf("[%s] && [%s]: %d\n", ret1, ret2, ft_strcmp(ret1, ret2));

        ret1 = "";
        ret2 = "Bing chilling - John Xina";
        printf("[%s] && [%s]: %d\n", ret1, ret2, ft_strcmp(ret1, ret2));

        ret1 = "Miaou !";
        ret2 = "Miaou !";
        printf("[%s] && [%s]: %d\n", ret1, ret2, ft_strcmp(ret1, ret2));

        /* segfault */
        
        /*ret1 = NULL;
        ret2 = NULL;
        printf("[%s] && [%s] = %d\n", ret1, ret2, ft_strcmp(ret1, ret2));*/
    }
}

/* strlen */

static void strlen_test(void)
{
    printf("\n=== strlen ===\n\n");
    {
        printf("STD:\n");
        char *ret1 = "Hello World !";
        printf("[%s]: %ld\n", ret1, strlen(ret1));

        ret1 = "Read Berserk";
        printf("[%s]: %ld\n", ret1, strlen(ret1));

        ret1 = WORD;
        printf("[%s]: %ld\n", ret1, strlen(ret1));

        ret1 = "";
        printf("[%s]: %ld\n", ret1, strlen(ret1));

        ret1 = LOREM;
        printf("lorem: %ld\n", strlen(ret1));

        /* segfault */

        /*ret1 = NULL;
        printf("[%s]: %ld\n", ret1, strlen(ret1));*/
    }
    {
        printf("\nFT:\n");
        char *ret1 = "Hello World !";
        printf("[%s]: %ld\n", ret1, ft_strlen(ret1));

        ret1 = "Read Berserk";
        printf("[%s]: %ld\n", ret1, ft_strlen(ret1));

        ret1 = WORD;
        printf("[%s]: %ld\n", ret1, ft_strlen(ret1));

        ret1 = "";
        printf("[%s]: %ld\n", ret1, ft_strlen(ret1));

        ret1 = LOREM;
        printf("lorem: %ld\n", ft_strlen(ret1));

        /* segfault */

        /*ret1 = NULL;
        printf("[%s]: %ld\n", ret1, ft_strlen(ret1));*/
    }
}

/* write */

static void write_test(void)
{
    printf("\n=== write ===\n\n");
    {
        errno = 0;
        printf("STD:\n");
        int fd = STDOUT_FILENO;
        int status = 0;
        status = write(fd, "STDOUT_FILENO", 13);
        printf(": %s: %d\n", strerror(errno), status);
        
        errno = 0;
        fd = STDERR_FILENO;
        status = write(fd, "STDERR_FILENO", 13);
        printf(": %s: %d\n", strerror(errno), status);

        errno = 0;
        fd = STDOUT_FILENO;
        status = write(fd, WORD, 8);
        printf(": %s: %d\n", strerror(errno), status);

        errno = 0;
        status = write(fd, WORD, 4);
        printf(": %s: %d\n", strerror(errno), status);

        /* warning */

        /*errno = 0;
        status = write(fd, WORD, 13);
        printf(": %s: %d\n", strerror(errno), status);

        errno = 0;
        fd = STDOUT_FILENO;
        status = write(fd, "abcdefghijklmnopqrstuvwxyz\n", -1);
        printf("%s: %d\n", strerror(errno), status);*/

        /* end */

        errno = 0;
        fd = open(WRITE_STD, O_WRONLY | O_TRUNC);
        status = write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %s: %d\n", WRITE_FT, strerror(errno), status);
        close(fd);

        fd = open(ERROR, O_WRONLY | O_TRUNC);
        status = write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %s: %d\n", ERROR, strerror(errno), status);
    }
    {
        errno = 0;
        printf("\nFT:\n");
        int fd = STDOUT_FILENO;
        int status = 0;
        status = ft_write(fd, "STDOUT_FILENO", 13);
        printf(": %s: %d\n", strerror(errno), status);
        
        errno = 0;
        fd = STDERR_FILENO;
        status = ft_write(fd, "STDERR_FILENO", 13);
        printf(": %s: %d\n", strerror(errno), status);

        errno = 0;
        fd = STDOUT_FILENO;
        status = ft_write(fd, WORD, 8);
        printf(": %s: %d\n", strerror(errno), status);

        errno = 0;
        status = ft_write(fd, WORD, 4);
        printf(": %s: %d\n", strerror(errno), status);

        /* warning in std */

        /*errno = 0;
        status = ft_write(fd, WORD, 13);
        printf(": %s: %d\n", strerror(errno), status);

        errno = 0;
        fd = STDOUT_FILENO;
        status = ft_write(fd, "abcdefghijklmnopqrstuvwxyz\n", -1);
        printf("%s: %d\n", strerror(errno), status);*/

        /* end */

        errno = 0;
        fd = open(WRITE_FT, O_WRONLY | O_TRUNC);
        status = ft_write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %s: %d\n", WRITE_FT, strerror(errno), status);
        close(fd);

        fd = open(ERROR, O_WRONLY | O_TRUNC);
        status = ft_write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %s: %d\n", ERROR, strerror(errno), status);
    }
}

/* read */

static void read_test()
{
    printf("=== read ===\n");
    {
        errno = 0;
        int fd = open(NL_FILE, O_RDONLY);
	    char std_buffer[11];
	    char ft_buffer[11];
        ssize_t res1;
        ssize_t res2;

        printf("\n[%s]\n", NL_FILE);
	    res1 = read(fd, std_buffer, 10);
        printf("STD: %s\n", strerror(errno));
        errno = 0;
	    lseek(fd, 0, SEEK_SET);
	    res2 = ft_read(fd, ft_buffer, 10);
        printf("FT: %s\n", strerror(errno));
        errno = 0;
	    printf("std: %ld | ft: %ld\n", res1, res2);
	    std_buffer[res1] = '\0';
	    ft_buffer[res2] = '\0';
	    printf("std_buffer: [%s] | ft_buffer: [%s]\n\n", std_buffer, ft_buffer);
        close(fd);
    }
    {
        int fd = open(LITTLE_LOREM, O_RDONLY);
	    char std_buffer[21];
	    char ft_buffer[21];
        ssize_t res1;
        ssize_t res2;
        errno = 0;

        printf("[%s]\n", LITTLE_LOREM);
	    res1 = read(fd, std_buffer, 20);
        printf("STD: %s\n", strerror(errno));
        errno = 0;
	    lseek(fd, 0, SEEK_SET);
	    res2 = ft_read(fd, ft_buffer, 20);
        printf("FT: %s\n", strerror(errno));
        errno = 0;
	    printf("std: %ld | ft: %ld\n", res1, res2);
	    std_buffer[res1] = '\0';
	    ft_buffer[res2] = '\0';
	    printf("std_buffer: [%s] | ft_buffer: [%s]\n", std_buffer, ft_buffer);

        lseek(fd, 0, SEEK_SET);
        res1 = read(fd, std_buffer, 20);
        res1 += read(fd, std_buffer, 10);
        printf("STD: %s\n", strerror(errno));
        errno = 0;
	    lseek(fd, 0, SEEK_SET);
	    res2 = ft_read(fd, ft_buffer, 20);
        res2 = ft_read(fd, ft_buffer, 10);
        printf("\nstd: %ld | ft: %ld\n", res1, res2);
        std_buffer[res1] = '\0';
	    ft_buffer[res2] = '\0';
        printf("std_buffer: [%s] | ft_buffer: [%s]\n\n", std_buffer, ft_buffer);
        close(fd);
    }
    {
        int fd = open(EMPT, O_RDONLY);
	    char std_buffer[21];
	    char ft_buffer[21];
        ssize_t res1;
        ssize_t res2;
        errno = 0;

        printf("[%s]\n", EMPT);
	    res1 = read(fd, std_buffer, 20);
        printf("STD: %s\n", strerror(errno));
        errno = 0;
	    lseek(fd, 0, SEEK_SET);
	    res2 = ft_read(fd, ft_buffer, 20);
        printf("FT: %s\n", strerror(errno));
        errno = 0;
	    printf("std: %ld | ft: %ld\n", res1, res2);
	    std_buffer[res1] = '\0';
	    ft_buffer[res2] = '\0';
	    printf("std_buffer: [%s] | ft_buffer: [%s]\n\n", std_buffer, ft_buffer);
        close(fd);
    }
    {
        int fd = open(NL_FILE, O_RDONLY);
	    char std_buffer[11];
	    char ft_buffer[11];
        ssize_t res1;
        ssize_t res2;
        errno = 0;
        
        printf("[%s]\n", "fd = 400");
	    res1 = read(400, std_buffer, 10);
		printf("STD: %s\n", strerror(errno));
        errno = 0;
	    res2 = ft_read(400, ft_buffer, 10);
		printf("FT: %s\n", strerror(errno));
        errno = 0;
	    printf("std: %ld | ft: %ld\n", res1, res2);

	    if (res1 != -1)
	        std_buffer[res1] = '\0';
	    if (res2 != -1)
	        ft_buffer[res2] = '\0';
	    if (res1 != -1 && res2 != -1)
	        printf("std_buffer: [%s] | ft_buffer: [%s]\n", std_buffer, ft_buffer);
    }
    {
        /* warning */

        /*errno = 0;
        int fd = open(ALPH, O_RDONLY);
	    char std_buffer[27];
	    char ft_buffer[27];
        ssize_t res1;
        ssize_t res2;

        printf("[%s]\n", ALPH);
	    res1 = read(fd, std_buffer, 40);
        printf("STD: %s\n", strerror(errno));
	    lseek(fd, 0, SEEK_SET);
	    res2 = ft_read(fd, ft_buffer, 40);
        printf("FT: %s\n", strerror(errno));
	    printf("std: %ld | ft: %ld\n", res1, res2);
	    std_buffer[res1] = '\0';
	    ft_buffer[res2] = '\0';
	    printf("std_buffer: [%s] | ft_buffer: [%s]\n\n", std_buffer, ft_buffer);
        close(fd);*/
    }
}

/* Test */

int main(void)
{
    read_test();
    write_test();
    strlen_test();
    strcmp_test();
    strcpy_test();
    strdup_test();
}