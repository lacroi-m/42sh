/*
** my_init.c for my_init in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh/srcs
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May  2 13:44:52 2016 theo da-silva
** Last update Wed Jun  8 15:40:03 2016 Lacroix Maxime
*/

#include "42sh.h"

int		check_input(char *input)
{
  int		i;

  i = - 1;
  if (input == NULL)
    return (0);
  while (input[++i])
    {
      if (input[i] > ' ')
	return (1);
    }
  return (0);
}

static void	my_catch(int i)
{
  (void)i;
  my_putstr("\n$> ", 1, 0);
}

static void	my_put_segv(int i)
{
  (void)i;
  my_putstr("Segmentation fault\n", 1, 0);
  exit(ret);
}

void		my_init(t_params *p)
{
  if ((signal(SIGINT, my_catch) == SIG_ERR
       || (signal(SIGTSTP, my_catch) == SIG_ERR)
       || (signal(SIGSEGV, my_put_segv)) == SIG_ERR))
    {
      fprintf(stdout, "SIGNAL ERROR\n");
      exit(-1);
    }
  p->path_tab = NULL;
  p->state = 0;
  p->env_tab = NULL;
  ret = 0;
}
