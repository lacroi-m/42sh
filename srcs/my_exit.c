/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Mon May 23 15:10:57 2016 theo da-silva
*/

#include "42sh.h"

int	my_exit(char *str, t_params *p, int value)
{
  (void)str;
  my_free_tab(p->path_tab); /*free tab path */
  my_free_tab(p->env_tab);
  my_clear_list(&p->env); /* free_env */
  free(p->prompt);
  exit(value % 255);
  return (0);
}
