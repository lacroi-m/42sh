##
## Makefile for Makefile in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
## 
## Made by virgile junique
## Login   <juniqu_v@epitech.net>
## 
## Started on  Mon May  2 11:30:05 2016 virgile junique
## Last update Mon May  9 10:24:32 2016 Mehdi
##

CC	= cc

RM	= rm -f

NAME	= libmy.a

SRCS	= my_putchar.c \
	  my_strlen.c \
	  my_putstr.c \
	  my_strndup.c \
	  my_strncat.c \
	  get_next_line.c \
	  wordtab_custom.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME) $(OBJS) move

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)
	 ranlib $(NAME)

move:
	 cp $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all move clean fclean re
