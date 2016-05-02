##
## Makefile for Makefile in /home/juniqu_v/rendu/PSU_2015_42sh
## 
## Made by virgile junique
## Login   <juniqu_v@epitech.net>
## 
## Started on  Mon May  2 12:27:35 2016 virgile junique
## Last update Mon May  2 12:35:11 2016 virgile junique
##

CC	= cc

RM	= rm -f

NAME	= 42sh

CFLAGS	+= -W -Wall -Werror -Wextra -I./include/

LIB     = -lmy -L./lib/

SRC	= $(addprefix srcs/, \
	    main.c)

OBJ	= $(SRC:.c=.o)

M_LIB	= make -C lib/my

all:	 $(NAME)

$(NAME): $(OBJ)
	 $(M_LIB)
	 $(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
	 $(M_LIB) clean
	 $(RM) $(OBJ)

fclean:	 clean
	 $(M_LIB) fclean
	 $(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
