/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Sun Jun  5 11:53:11 2016 virgile junique
*/

#include "42sh.h"

static int	check_value(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (my_putstr("exit: Expression Syntax.\n", 2, -1));
      i++;
    }
  return (0);
}

int		my_exit(char **cmd, t_params *p)
{
  int		r;

  r = -1;
  if (cmd[1] != NULL && check_value(cmd[1]) == -1)
    return (2);
  else
    r = my_getnbr(cmd[1]);
  if (p->path_tab != NULL)
    my_free_ctab(p->path_tab);
  if (p->env_tab != NULL)
    my_free_ctab(p->env_tab);
  my_clear_list(&p->env);
  exit(r % 255);
  return (2);
}
