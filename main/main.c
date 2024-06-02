#include "../include/libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* other */

static char *alloc(int size, char *str)
{
    char *new;

    new = NULL;
    if (str)
        free(str);
    new = malloc((size + 1) * sizeof(char));
    if (!new)
        return (NULL);
    return (new);
}

static void fill(int size, char *str, char c)
{
    int i;

    i = 0;
    while (i <= size)
        str[i++] = c;
}

/* strlen */

static void strlen_test(void)
{
    int len;
    int asm_len;

    printf(" __[ strlen ]__\n|\n");

    /* segfault (strlen same reaction)*/

    /*len = strlen(NULL); 
    asm_len = ft_strlen(NULL); 
    printf("NULL => %d\n", len);
    printf(" asm NULL => %d\n\n", asm_len); */

    len = strlen(EMPTY); 
    asm_len = ft_strlen(EMPTY); 
    printf("| EMPTY => %d\n", len);
    printf("| asm EMPTY => %d\n|\n", asm_len);

    len = strlen(WORD); 
    asm_len = ft_strlen(WORD); 
    printf("| WORD => %d\n", len);
    printf("| asm WORD => %d\n|\n", asm_len);

    len = strlen(NUM); 
    asm_len = ft_strlen(NUM); 
    printf("| NUM => %d\n", len);
    printf("| asm NUM => %d\n|\n", asm_len);

    len = strlen(NL); 
    asm_len = ft_strlen(NL); 
    printf("| NL => %d\n", len);
    printf("| asm NL => %d\n|\n", asm_len);

    len = strlen(LOREM); 
    asm_len = ft_strlen(LOREM); 
    printf("| LOREM => %d\n", len);
    printf("| LOREM => %d\n", asm_len);
}

/* strcpy */

static void strcpy_test(void)
{
    char dst[] = "dst";
    char src[] = "src";

    char dst_asm[7] = "dst_asm";
    char src_asm[7] = "src_asm";
    char *as = malloc(7);

    printf(" __[ strcpy ]__\n|\n");

    /* segfault */

    /* printf("| WORD => %s\n", strcpy(dst, NULL);
    printf("| WORD => %s\n", strcpy(NULL, src); */

    as = ft_strcpy(dst_asm, src_asm);
    printf("%s\n", as);
}

/* write */

static void write_test(void)
{
    int fd;
    int i = 0;

    printf(" __[ write ]__\n|\n");

    i = write(1, "Hello_world !\n", 14);
    printf("| write value => %d\n", i);

    i = ft_write(1, "Hello_world !\n", 14);
    printf("| ft_write value => %d\n", i);

    i = write(667, "Fd error\n", 9);
    printf("| write value => %d\n", i);

    i = ft_write(667, "Fd error\n", 9);
    printf("| ft_write value => %d\n", i);

    i = write(1, "| line to\n long\n", 10);
    printf("| write value => %d\n", i);

    i = ft_write(1, "| line to\n long\n", 10);
    printf("| ft_write value => %d\n", i);

    /* Same error i = write(1, "| waaaaaaaaaaaaaaaaaaaa!", 777);
    printf("| write value => %d\n", i);

    i = ft_write(1, "| waaaaaaaaaaaaaaaaaaaa!", 777);
    printf("| ft_write value => %d\n", i); */

    fd = open("./main/write_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (!fd)
        return ;
    ft_write(fd, "Hello_World !\n", 14);
    close(fd);
}

/* read */

static void read_test()
{
    int fd;
    int status;
    char *buffer;
    char *ft_buffer;

    fd = 0;
    status = 0;
    buffer = NULL;
    ft_buffer = NULL;

    printf(" __[ read ]__\n|\n");

    /* first */

    buffer = alloc(13, NULL);
    ft_buffer = alloc(13, NULL);
    fd = open(ALPH, O_RDONLY);
    if (fd < 0)    
        return ;
    status = read(fd, buffer, 13);
    if (status != -1)
        buffer[status] = '\0';
    printf("| buffer => %c%s%c\n| status =>  %d\n", '\"', buffer, '\"', status);
    status = ft_read(fd, ft_buffer, 13);
    if (status != -1)
        buffer[status] = '\0';
    printf("| ft_buffer => %c%s%c\n| status =>  %d\n", '\"', ft_buffer, '\"', status);
    close(fd);

    /* seconde */

    buffer = alloc(10, buffer);
    ft_buffer = alloc(10, ft_buffer);
    fd = open(ERROR, O_RDONLY);
    status = read(fd, buffer, 10);
    printf("| buffer => %c%s%c\n| status =>  %d\n", '\"', buffer, '\"', status);
    status = ft_read(fd, ft_buffer, 10);
    printf("| ft_read => %c%s%c\n| status =>  %d\n", '\"', ft_buffer, '\"', status);
    fill(10, buffer, '\0');
    fill(10, ft_buffer, '\0');

    /* third */

    buffer = alloc(64, buffer);
    ft_buffer = alloc(64, ft_buffer);
    fd = open(EMPT, O_RDONLY);
    if (fd < 0)    
        return ;
    status = read(fd, buffer, 64);
    if (status != -1)
        buffer[status] = '\0';
    printf("| read => %c%s%c\n| status =>  %d\n", '\"', buffer, '\"', status);
    status = ft_read(fd, ft_buffer, 64);
    if (status != -1)
        ft_buffer[status] = '\0';
    printf("| ft_read => %c%s%c\n| status =>  %d\n", '\"', ft_buffer, '\"', status);
    close(fd);
    fill(64, buffer, '\0');
    fill(64, ft_buffer, '\0');

    /* four */

    buffer = alloc(20, buffer);
    ft_buffer = alloc(20, ft_buffer);
    fd = open(NL_FILE, O_RDONLY);
    if (fd < 0)    
        return ;
    status = read(fd, buffer, 20);
    if (status != -1)
        buffer[status] = '\0';
    printf("| read => %c%s%c\n| status =>  %d\n", '\"', buffer, '\"', status);
    status = ft_read(fd, ft_buffer, 20);
    if (status != -1)
        ft_buffer[status] = '\0';
    printf("| ft_read => %c%s%c\n| status =>  %d\n", '\"', ft_buffer, '\"', status);
    close(fd);

    /* five */

    buffer = alloc(667, buffer);
    ft_buffer = alloc(667, ft_buffer);
    fd = open(LITTLE_LOREM, O_RDONLY);
    if (fd < 0)    
        return ;
    status = read(fd, buffer, 667);
    if (status != -1)
        buffer[status] = '\0';
    printf("| read => %c%s%c\n| status =>  %d\n", '\"', buffer, '\"', status);
    status = ft_read(fd, ft_buffer, 667);
    if (status != -1)
        ft_buffer[status] = '\0';
    printf("| ft_read => %c%s%c\n| status =>  %d\n", '\"', ft_buffer, '\"', status);
    close(fd);
    fill(667, buffer, '\0');
    fill(667, ft_buffer, '\0');

    /* six */

    char c = -1;

    free(buffer);
    free(ft_buffer);
    fd = open(LITTLE_LOREM, O_RDONLY);
    status = read(fd, &c, 1);
    printf("| c => %c%c%c\n| status =>  %d\n", '\'', c, '\'', status);
    status = ft_read(fd, &c, 1);
    printf("| c => %c%c%c\n| status =>  %d\n", '\'', c, '\'', status);

    /* error */

    /*status = read(fd, &c, 46);
    printf("| read => %c%c%c\n| status =>  %d\n", '\'', c, '\'', status);*/

    /*status = ft_read(fd, &c, 46);
    printf("| ft_read => %c%c%c\n| status =>  %d\n", '\'', c, '\'', status);*/

    close(fd);
}

/* strcmp */

static void strcmp_test(void)
{
    printf(" __[ strcmp ]__\n|\n");

    printf("| Hello_word vs Hello_word\n");
    if (!strcmp("Hello_word", "Hello_word"))
        printf("| strcmp == true == %d\n", strcmp("Hell_word", "Hello_word"));
    if (1)
        printf("| ft_strcmp == true == %d\n", ft_strcmp("Hello_word", "Hello_word"));
}

/* strdup */

void strdup_test(void)
{
    char *as_dup;
    char *dup;

    dup = NULL;
    as_dup = NULL;
    dup = strdup("test");
    printf("strdup => %s\n", dup);
    as_dup = ft_strdup("test");
    // printf("ft_strdup => %s\n", as_dup);
    free(dup);
    free(as_dup);
}

int main(void)
{
    // write_test();
    // read_test();
    // strlen_test();
    // strcmp_test();
    // strcpy_test();
    strdup_test();
}