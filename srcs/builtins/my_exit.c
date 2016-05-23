/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Mon May 23 15:51:24 2016 theo da-silva
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

int	my_exit(char *str, t_params *p)
{
  if (check_value(str) == -1)
    return (-1);
  my_free_tab(p->path_tab); /*free tab path */
  my_free_tab(p->env_tab);
  my_clear_list(&p->env); /* free_env */
  free(p->prompt);
  exit(my_getnbr(str) % 255);
  return (0);
}
