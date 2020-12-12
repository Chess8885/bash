##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

NAME		= mysh

CC		= cc

RM		= rm -f

SRC		= src/main.c			\
		src/lib/print.c			\
		src/env.c			\
		src/setenv.c			\
		src/loop.c			\
		src/lib/my_strstr.c		\
		src/lib/replace_str.c		\
		src/lib/mystr_copy.c		\
		src/lib/mystr_cut.c		\
		src/lib/mystr_trim.c		\
		src/lib/trim.c			\
		src/lib/new_triplet.c		\
		src/lib/error_message.c		\
		src/lib/copy_trim.c		\
		src/lib/free_shell.c		\
		src/lib/darray_free.c		\
		src/lib/darray_copy.c		\
		src/lib/str_copy.c		\
		src/lib/darray_length.c		\
		src/lib/darray_empty.c		\
		src/internal.c			\
		src/exec.c			\
		src/lib/my_str_to_word_array.c

OBJ	=	$(SRC:.c=.o)


CFLAGS	=	-Wall -I ./include

NAME	=	mysh

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
