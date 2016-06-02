##
## Makefile for Makefile in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
##
## Made by virgile junique
## Login   <juniqu_v@epitech.net>
##
## Started on  Mon May  2 11:30:05 2016 virgile junique
## Last update Thu Jun  2 11:38:57 2016 Lemeh
##

CC	= cc

RM	= rm -f

NAME	= libmy.a

SRCS	= my_putchar.c \
	  my_strlen.c \
	  my_putstr.c \
	  my_str_to_wordtab.c \
	  my_strcat.c \
	  my_strncat.c \
	  my_strcmp.c \
	  my_strncmp.c \
	  my_strndup.c \
	  my_strdup.c \
	  my_strcpy.c \
	  my_strncpy.c \
	  get_next_line.c \
	  path.c \
	  test_system.c \
	  test_system2.c \
	  my_free.c \

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
