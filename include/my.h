/*
** my.h for my in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 12:21:16 2016 virgile junique
** Last update Mon May  9 15:58:55 2016 virgile junique
*/

#ifndef _MY_H_

# define _MY_H_

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

void	my_putchar(char c, int fd);
void	my_putstr(char *str, int fd);
void	*xmalloc(int size);
int	my_strlen(char *str);
char	*my_strncat(char *dest, char *src, int n);
char	*my_strndup(char *src, int n);
char	**wordtab_custom(char *str);

#endif /* !MY.H */
