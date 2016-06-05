/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Sun Jun  5 23:40:51 2016 virgile junique
*/

#include "42sh.h"

int		my_exit(char **cmd, t_params *p)
{
  int		r;

  r = 0;
  if (cmd == NULL)
  if (p->path_tab != NULL)
    my_free_ctab(p->path_tab);
  if (p->env_tab != NULL)
    my_free_ctab(p->env_tab);
  my_clear_list(&p->env);
  my_putchar('\n', 1);
  if (cmd == NULL)
    exit(ret);
  if (cmd[1] != NULL && ((r = my_getnbr(cmd[1])) <= 0))
    return (my_putstr("Badly number\n", 2, 1));
  exit(r);
  return (2);
}
