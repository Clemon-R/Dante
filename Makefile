##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
##
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
##
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
## Last update Sun May  7 16:18:26 2017 Raphaël Goulmot
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
		src/utils/my_put_tab.c		\
		include/line.h			\
		include/utils.h			\
		include/gen.h			\
		include/astar.h

GEN	=	generator/src/main_gene.c	\
		generator/src/gen.c		\
		generator/src/check.c		\
		generator/src/move.c

GEN_B	=	generator/bonus/src/main_gene.c	\
		generator/bonus/src/gen.c		\
		generator/bonus/src/check.c		\
		generator/bonus/src/move.c

ASTAR	=	astar/src/main.c		\
		astar/src/solve.c		\
		astar/src/resolve.c

DEPTH	=	depth/src/main.c		\
		depth/src/solve.c		\
		depth/src/resolve.c

BREADTH	=	breadth/src/main.c		\
		breadth/src/solve.c		\
		breadth/src/resolve.c		\
		breadth/src/get_room.c

TOURNAMENT	=	tournament/src/main.c	\
			tournament/src/solve.c	\
			tournament/src/resolve.c

OBJ_G	=	$(SRC:.c=.o)	\
		$(GEN:.c=.o)

OBJ_GB	=	$(SRC:.c=.o)	\
		$(GEN_B:.c=.o)

OBJ_A	=	$(SRC:.c=.o)	\
		$(ASTAR:.c=.o)

OBJ_D	=	$(SRC:.c=.o)	\
		$(DEPTH:.c=.o)

OBJ_B	=	$(SRC:.c=.o)	\
		$(BREADTH:.c=.o)

OBJ_T	=	$(SRC:.c=.o)	\
		$(TOURNAMENT:.c=.o)

TMP	=	$(OBJ_G:.h=.h~)	\
		$(OBJ_A:.h=.h~)	\
		$(OBJ_D:.h=.h~)	\
		$(OBJ_B:.h=.h~)	\
		$(OBJ_T:.h=.h~)	\
		$(OBJ_GB:.h=.h~)

CFLAGS	=	-W -Wextra -Werror -Iinclude -g3 -pedantic

NAME_G	=	generator/generator

NAME_GB	=	generator/bonus/generator

NAME_A	=	astar/solver

NAME_D	=	depth/solver

NAME_B	=	breadth/solver

NAME_T	=	tournament/solver

all:	$(NAME_G) $(NAME_A) $(NAME_D) $(NAME_B) $(NAME_T) $(NAME_GB)

$(NAME_G):	$(OBJ_G)
	gcc $(OBJ_G) -o $(NAME_G) $(CFLAGS)

$(NAME_A):	$(OBJ_A)
	gcc $(OBJ_A) -o $(NAME_A) $(CFLAGS)

$(NAME_D):	$(OBJ_D)
	gcc $(OBJ_D) -o $(NAME_D) $(CFLAGS)

$(NAME_B):	$(OBJ_B)
	gcc $(OBJ_B) -o $(NAME_B) $(CFLAGS)

$(NAME_T):	$(OBJ_T)
	gcc $(OBJ_T) -o $(NAME_T) $(CFLAGS)

$(NAME_GB):	$(OBJ_GB)
	gcc $(OBJ_GB) -o $(NAME_GB) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME_G)
	rm -f $(NAME_A)
	rm -f $(NAME_D)
	rm -f $(NAME_B)
	rm -f $(NAME_T)
	rm -f $(NAME_GB)

re:	fclean all

