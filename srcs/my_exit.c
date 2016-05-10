/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
** 
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
** 
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Tue May 10 15:32:14 2016 virgile junique
*/

#include "42sh.h"

void	my_exit(t_params *p, int value)
{
  /*my_free_2d(p->cmd);*/
  my_clear_list(&p->env); /* free_env */
  free(p->prompt);
  exit(value % 255);
}
