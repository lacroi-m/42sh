/*
** my_init.c for my_init in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
** 
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
** 
** Started on  Mon May  2 13:44:52 2016 theo da-silva
** Last update Tue May 10 17:53:23 2016 virgile junique
*/

#include "42sh.h"

static void	my_catch(int i)
{
  (void)i;
  my_putstr("\n$>", 1);
}

static void	my_put_segv(int i)
{
  (void)i;
  my_putstr("Segmentation fault\n", 1);
  my_putstr("\n$>", 1);
}

void		my_init(t_params *p)
{
  if ((signal(SIGINT, my_catch) == SIG_ERR
       || (signal(SIGQUIT, my_catch) == SIG_ERR)
       || (signal(SIGSEGV, my_put_segv) == SIG_ERR)))
    {
      fprintf(stdout, "SIGNAL ERROR\n");
      exit(-1);
    }
  p->prompt = NULL;
  p->path_tab = NULL;
  my_putstr("$>", 1);
}
