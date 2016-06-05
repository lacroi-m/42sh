##
## Makefile for  in /home/oudin_c/rendu/S2/CPE/lem-in
## 
## Made by coudin
## Login   <oudin_c@epitech.net>
## 
## Started on  Fri Apr 22 00:47:18 2016 coudin
## Last update Tue May 31 23:59:11 2016 coudin

NAME	= gnl

RM	= rm -f

CFLAGS	= -Wall -Wextra

CC	= gcc -g3

SRCS	= gnl.c \
	  gnl0.c \
	  main.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
