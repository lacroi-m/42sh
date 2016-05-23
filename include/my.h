/*
** my.h for my in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 12:21:16 2016 virgile junique
** Last update Mon May 23 10:10:46 2016 Lemeh
*/

#ifndef _MY_H_

# define _MY_H_

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

void	count_word(char *str, int *nb);
void	my_putchar(char c, int fd);
void	my_putstr(char *str, int fd);
void	*xmalloc(int size);
int	my_strlen(char *str);
int	len_word(char *str, int num);
char	*check_slash(char *str);
char	*my_strncat(char *dest, char *src, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strndup(char *src, int n);
char	**wordtab_custom(char *str);
char	**my_str_to_wordtab(char *str);

#endif /* !MY.H */
