/*
** my.h for my in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 12:21:16 2016 virgile junique
** Last update Sun Jun  5 21:19:27 2016 virgile junique
*/

#ifndef _MY_H_

# define _MY_H_

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

void	my_free_ctab(char **tab);
void	my_free_itab(int **tab);
void	my_putchar(char c, int fd);
void	xclose(int fd);
void	count_word(char *str, int *nb);
void	*xmemset(char *str);
void	*xmalloc(int size);
void    my_free_3tab(char ***tab);
int	xopen(const char *pathname, int flag);
int	len_word(char *str, int num);
int	my_nb_word(char *str);
int	my_putstr(char *str, int fd, int value);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*check_slash(char *str);
char	*my_strncat(char *dest, char *src, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strndup(char *src, int n);
char	*my_strdup(char *src);
char	**my_str_to_wordtab(char *str);
char	**xmalloc_tab(int size);

#endif /* !MY.H */
