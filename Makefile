##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
##
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
##
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
## Last update Fri Apr 28 19:05:08 2017 Raphaël Goulmot
##

CC	=	gcc

SRC	=	src/utils/my_putstr_err.c	\
		src/utils/my_putchar.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/utils/my_getnbr.c		\
		src/utils/my_put_nbr.c		\
		src/utils/my_is.c		\
		src/utils/my_string.c		\
		src/utils/split.c		\
		src/utils/line.c		\
		src/utils/my_printf.c		\
		src/utils/my_base.c		\
		include/line.h			\
		include/utils.h

GEN	=	generator/src/main.c

OBJ_G	=	$(SRC:.c=.o)	\
		$(GEN:.c=.o)

TMP	=	$(OBJ_G:.h=.h~)

CFLAGS	=	-W -Wall -Wextra -Werror -Iinclude -g3 -pedantic

NAME_G	=	generator/generator

all:	$(NAME_G)

$(NAME_G):	$(OBJ_G)
	gcc $(OBJ_G) -o $(NAME_G) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME_G)

re:	fclean $(NAME_G)

run:
	./$(NAME_G)
