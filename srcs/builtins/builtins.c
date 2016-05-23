/*
** builtins.c for my_builtins in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May 23 14:33:34 2016 theo da-silva
** Last update Mon May 23 16:25:27 2016 theo da-silva
*/

#include "42sh.h"
#include "builtins.h"

void	my_fill_builtins_name(char tab[6])
{
  tab[0] = my_strcpy("cd");
  tab[1] = my_strcpy("setenv");
  tab[2] = my_strcpy("unsetenv");
  tab[3] = my_strcpy("unsetenv");
  tab[4] = my_strcpy("env");
  tab[5] = my_strcpy("echo");
}

int	my_builtins(char *str, t_params *p, int pos)
{
  int	(*f[6])(char *str, t_params *p);

  f[0] = &my_chdir;
  f[1] = &my_setenv;
  f[2] = &my_unsetenv;
  f[3] = &my_env;
  f[4] = &my_exit;
  f[5] = &my_echo;
  r = f[pos](command, env);
  return (r);
}

int	its_builtins(char *str)
{
  char  builtins_name[6];
  int	i;

  i = 0;
  my_fill_builtins_name(builtins_name);
  while (i != 6)
    {
      if (my_strcmp(str, builtins_name) == 0)
	return (i);
      i++;
    }
  return (-1);
}
