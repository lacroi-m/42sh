/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Tue May 24 13:38:33 2016 Lemeh
*/

#include "42sh.h"

static int	check_value(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (my_putstr("exit: Expression Syntax.", 2, -1));
      i++;
    }
  return (0);
}

int		my_exit(char **tab, char *str, t_params *p)
{
  int		r;

  (void)tab;
  r = -1;
  if (str != NULL && check_value(str) == -1)
    return (-1);
  if (p->path_tab != NULL)
    my_free_ctab(p->path_tab);
  if (p->env_tab != NULL)
    my_free_ctab(p->env_tab);
  my_clear_list(&p->env);
  free(p->prompt);
  if (str != NULL)
    r = atoi(str);
  exit(r % 255);
  return (0);
}
