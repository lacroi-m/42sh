##
## Makefile for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
##
## Made by Mehdi Meridja
## Login   <meridj_m@meridj_m@epitech.eu>
##
## Started on  Tue Mar 29 13:39:12 2016 Mehdi Meridja
## Last update Wed Apr 13 09:54:42 2016 Mehdi
##

NAME	= libmy.a

CFLAGS	= -Wall -W -Wextra -I../inc/

SRCS	= my_printf.c		\
	  my_strlen.c		\
	  aff_all2.c		\
	  malloc.c		\
	  aff_all.c		\
	  flag_printf.c		\
	  get_next_line.c	\
	  my_getnbr.c		\
	  my_strcat.c		\
	  my_strcpy.c		\
	  my_strdup.c		\
	  my_strcmp.c		\
	  my_strncpy.c		\
	  my_strndup.c		\
	  my_str_to_wordtab.c	\
	  my_memset.c		\
	  my_realloc.c		\
	  strdup_tab.c		\
	  my_free_tab.c		\

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) my/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
