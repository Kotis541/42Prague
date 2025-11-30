NAME = libftprintf.a
CC = gcc -Wall -Werror -Wextra
SRCS = printft.c print_unsigned.c printchar.c printdecimal.c printptr.c printstr.c tohex.c
OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
