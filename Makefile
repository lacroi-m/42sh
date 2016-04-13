##
## Makefile for all in /home/meridj/Rendu/minishell1/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Sun Apr 10 15:24:10 2016 John Doe
## Last update Wed Apr 13 17:37:00 2016 Mehdi
##

NAME	= 42sh

CFLAGS	= -Wall -Wextra -W -I./inc/

LIB     = -L./lib/ -lmy

SRC	= srcs/main.c \

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
