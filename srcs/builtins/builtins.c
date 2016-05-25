/*
** builtins.c for my_builtins in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May 23 14:33:34 2016 theo da-silva
** Last update Wed May 25 15:51:07 2016 Lemeh
*/

#include "42sh.h"
#include "builtins.h"

static int	my_chdir(char *str, t_params *p)
{
  (void)str;
  (void)p;
  return (0);
}

static int	my_history(char *str, t_params *p)
{
  (void)str;
  (void)p;
  return (0);
}

int	my_builtins(char *str, t_params *p, int pos)
{
  int	(*f[7])(char *str, t_params *p);
  int	r;

  f[0] = &my_chdir;
  f[1] = &my_setenv;
  f[2] = &my_unsetenv;
  f[3] = &my_env;
  f[4] = &my_exit;
  f[5] = &my_echo;
  f[6] = &my_history;
  r = f[pos](str, p);
  return (r);
}

int	its_builtins(char *str)
{
  char  *tab[8];
  int	i;

  i = 0;
  tab[0] = "cd";
  tab[1] = "setenv";
  tab[2] = "unsetenv";
  tab[3] = "env";
  tab[4] = "exit";
  tab[5] = "echo";
  tab[6] = "history";
  tab[7] = NULL;
  while (tab[i])
    {
      if (my_strcmp(str, tab[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}
