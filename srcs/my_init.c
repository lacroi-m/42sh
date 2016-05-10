/*
** my_init.c for my_init in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
** 
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
** 
** Started on  Mon May  2 13:44:52 2016 theo da-silva
** Last update Tue May 10 15:57:53 2016 theo da-silva
*/

#include <signal.h>
#include <stdio.h>
#include "42.h"

void	my_catch(int i)
{
  (void)i;
  my_putstr("\n$>", 1);
  my_loop(void);
}

void	my_put_segv(int i)
{
  (void)i;
  my_putstr("Segmentation fault\n");
  my_putstr("\n$>", 1);
  my_loop(void);
}

void	my_init(t_params *p)
{
  if ((signal(SIGINT, my_catch) == SIG_ERR
       || (signal(SIGQUIT, my_catch) == SIG_ERR)
       || (signal(SIGSEGV, put_segv) == SIG_ERR)))
    {
      f_printf(stdout, "SIGNAL ERROR\n");
      exit(-1);
    }
  p->prompt = NULL;
  my_putstr("$>", 1);
}
