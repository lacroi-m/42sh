/*
** my_exit.c for my_exit in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
** 
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
** 
** Started on  Mon May  2 16:39:13 2016 theo da-silva
** Last update Mon May  9 13:14:52 2016 theo da-silva
*/

#include "42sh.h"
#include <unistd.h>

void	my_exit(t_env *p, int value)
{
  my_free_2d(p->cmd);
  my_free_env(???);
  exit(value % 255);
}
