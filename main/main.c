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
    printf("\n=== strdup ===\n");
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
    printf("\n=== strcpy ===\n");
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
    printf("\n=== strcmp ===\n");
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
    printf("\n=== strcmp ===\n");
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
    printf("\n=== write ===\n");
    {
        write(1, "STD:\n", 5);
        int fd = STDOUT_FILENO;
        int status = 0;
        write(fd, "[\"", 2);
        status = write(fd, "STDOUT_FILENO", 13);
        write(fd, "\"]: ", 4);
        printf("%d\n", status);
        
        fd = STDERR_FILENO;
        write(fd, "[\"", 2);
        status = write(fd, "STDERR_FILENO", 13);
        write(fd, "\"]: ", 4);
        printf("%d\n", status);

        fd = STDOUT_FILENO;
        write(fd, "[\"", 2);
        status = write(fd, WORD, 8);
        write(fd, "\"]: ", 4);
        printf("%d\n", status);

        write(fd, "[\"", 2);
        status = write(fd, WORD, 4);
        write(fd, "\"]: ", 4);
        printf("%d\n", status);

        /* warning */

        /*write(fd, "[\"", 2);
        status = write(fd, WORD, 13);
        write(fd, "\"]: ", 4);
        printf("%d\n", status);

        fd = STDOUT_FILENO;
        write(fd, "[\"", 2);
        status = write(fd, "abcdefghijklmnopqrstuvwxyz\n", -1);
        write(fd, "\"]: ", 4);
        printf("%d\n", status);*/

        /* end */

        fd = open(WRITE_STD, O_WRONLY | O_TRUNC);
        status = write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %d\n", WRITE_STD, status);
        close(fd);

        fd = open(ERROR, O_WRONLY | O_TRUNC);
        status = write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %d\n", ERROR, status);
    }
    {
        ft_write(1, "\nFT:\n", 5);
        int fd = STDOUT_FILENO;
        int status = 0;
        ft_write(fd, "[\"", 2);
        status = ft_write(fd, "STDOUT_FILENO", 13);
        ft_write(fd, "\"]: ", 4);
        printf("%d\n", status);
        
        fd = STDERR_FILENO;
        ft_write(fd, "[\"", 2);
        status = ft_write(fd, "STDERR_FILENO", 13);
        ft_write(fd, "\"]: ", 4);
        printf("%d\n", status);

        fd = STDOUT_FILENO;
        ft_write(fd, "[\"", 2);
        status = ft_write(fd, WORD, 8);
        ft_write(fd, "\"]: ", 4);
        printf("%d\n", status);

        ft_write(fd, "[\"", 2);
        status = ft_write(fd, WORD, 4);
        ft_write(fd, "\"]: ", 4);
        printf("%d\n", status);

        /* warning */

        /*ft_write(fd, "[\"", 2);
        status = ft_write(fd, WORD, 13);
        ft_write(fd, "\"]: ", 4);
        printf("%d\n", status);

        fd = STDOUT_FILENO;
        ft_write(fd, "[\"", 2);
        status = ft_write(fd, "abcdefghijklmnopqrstuvwxyz\n", -1);
        ft_write(fd, "\"]: ", 4);
        printf("%d\n", status);*/

        /* end */

        fd = open(WRITE_FT, O_WRONLY | O_TRUNC);
        status = ft_write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %d\n", WRITE_STD, status);
        close(fd);

        fd = open(ERROR, O_WRONLY | O_TRUNC);
        status = ft_write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
        printf("write in %s: %d\n", ERROR, status);
    }
}

/* read */

static void read_test()
{
    printf("\n=== read ===\n");
    {

    }
    {
        
    }
}

int main(void)
{
    read_test();
    //write_test();
    //strlen_test();
    // strcmp_test();
    // strcpy_test();
    // strdup_test();
}