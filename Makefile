NAME = libasm.a

RUN_NAME = a.out

SRCS =	srcs/ft_write.s \
		srcs/ft_read.s \
		srcs/ft_strlen.s \
		srcs/ft_strcpy.s \
		srcs/ft_strcmp.s \
		srcs/ft_strdup.s

T_FILE = main/main.c

OBJS = $(SRCS:.s=.o)

LIB = lib/

%.o: %.s
	nasm -f elf64 $< -o $@

all: $(LIB)$(NAME)

$(LIB)$(NAME) : $(OBJS)
	@./bash/libasm_test.sh
	@ar -rcs $(LIB)$(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB)$(NAME)
	rm -rf file lib

run: fclean all
	@gcc $(T_FILE) $(LIB)$(NAME)
	@clear
	@./$(RUN_NAME)
	@rm -rf $(RUN_NAME)


re: fclean all