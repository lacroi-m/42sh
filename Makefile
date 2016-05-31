##
## Makefile for Makefile in /home/juniqu_v/rendu/PSU_2015_42sh
## 
## Made by virgile junique
## Login   <juniqu_v@epitech.net>
## 
## Started on  Mon May  2 12:27:35 2016 virgile junique
## Last update Tue May 31 10:45:18 2016 virgile junique
##

CC	= cc

RM	= rm -f

NAME	= 42sh

CFLAGS	+= -W -Wall -Werror -Wextra \
	   -I./include/

LIB     = -lmy -L./lib/

SRC	= $(addprefix srcs/, \
	    main.c \
	    my_env.c \
	    my_list.c \
	    my_init.c \
	    my_exec.c \
	    syntaxe.c \
	    builtins/builtins.c \
	    builtins/built_env.c \
	    builtins/my_exit.c \
	    builtins/my_cd.c \
	    builtins/echo.c)

OBJ	= $(SRC:.c=.o)

M_LIB	= make -C lib/my

ECHO	= /bin/echo -e
DEFAULT	= "\033[00m"
GREEN	= "\033[0;32m"
TEAL	= "\033[1;36m"
RED	= "\033[1;31m"

all:	 $(NAME)

$(NAME): $(OBJ)
	 @$(M_LIB)
	 @$(ECHO) $(GREEN) "[OK]" $(TEAL) "Library" $(DEFAULT) 
	 @$(CC) -o $(NAME) $(OBJ) $(LIB)
	 @$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT)

clean:
	 @$(M_LIB) clean
	 @$(ECHO) $(RED) "[DELETED]" $(TEAL) "Library" $(DEFAULT)
	 @$(RM) $(OBJ)
	 @$(ECHO) $(RED) "[DELETED]" $(TEAL) $(OBJ) $(DEFAULT)

fclean:	 clean
	 @$(M_LIB) fclean
	 @$(ECHO) $(RED) "[DELETED]" $(TEAL) "Libmy.a" $(DEFAULT)
	 @$(RM) $(NAME)
	 @$(ECHO) $(RED) "[DELETED]" $(TEAL) $(NAME) $(DEFAULT)

re: fclean all

.PHONY:	all clean fclean re
