NAME = libasm.a

RUN_NAME = libasm_test

SRCS =	srcs/ft_write.s \
		srcs/ft_read.s \
		srcs/ft_strlen.s \
		srcs/ft_strcpy.s \
		srcs/ft_strcmp.s \
		srcs/ft_strdup.s

T_FILE = main/main.c

LIB = lib/

OBJS = $(SRCS:.s=.o)

OBJS_C = $(T_FILE.c=.o)

all: $(NAME) run

$(NAME) : nasm $(OBJS) 
	@./bash/libasm_test.sh
	@ar -rcs $(LIB)$(NAME) $(OBJS)


nasm: 
	nasm -f elf64 srcs/ft_strlen.s
	nasm -f elf64 srcs/ft_strcpy.s
	nasm -f elf64 srcs/ft_write.s
	nasm -f elf64 srcs/ft_strcmp.s
	nasm -f elf64 srcs/ft_strdup.s
	nasm -f elf64 srcs/ft_read.s

run: $(OBJS_C) $(NAME)
	@gcc -o $(RUN_NAME) $(T_FILE) -L. $(LIB)$(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_C)

fclean: clean
	@rm -rf $(LIB)$(NAME)
	@rm -rf $(RUN_NAME)
	@rm -rf file lib

re: fclean all

