/*
** builtins.c for my_builtins in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May 23 14:33:34 2016 theo da-silva
** Last update Sun Jun  5 23:11:48 2016 virgile junique
*/

#include "42sh.h"

static int	my_chdir(char **cmd, t_params *p)
{
  chdir(cmd[1]);
  return (0);
  if ((my_strncmp(cmd[1], "-", 1)) == 0)
    return (my_old(p, p->env));
  else if (cmd[1] == NULL)
    return (go_home(p, p->env));
  else
    return (go_dir(cmd[1], p));
  return (0);
}

static int	my_history(char **str, t_params *p)
{
  (void)str;
  (void)p;
  return (0);
}

int	my_builtins(char **built, t_params *p, int pos)
{
  int	(*f[7])(char **built, t_params *p);
  int	r;

  f[0] = &my_chdir;
  f[1] = &my_setenv;
  f[2] = &my_unsetenv;
  f[3] = &my_env;
  f[4] = &my_exit;
  f[5] = &my_echo;
  f[6] = &my_history;
  r = f[pos](built, p);
  my_free_ctab(built);
  return (r);
}

int	its_builtins(t_node *tree, t_params *p)
{
  char  *tab[8];
  int	i;
  char	**built;

  i = -1;
  if (!(built = my_str_to_wordtab(tree->data)))
    return (2);
  tab[0] = "cd";
  tab[1] = "setenv";
  tab[2] = "unsetenv";
  tab[3] = "env";
  tab[4] = "exit";
  tab[5] = "echo";
  tab[6] = "history";
  tab[7] = NULL;
  while (tab[++i])
    {
      if (my_strcmp(built[0], tab[i]) == 0)
	return (my_builtins(built, p, i));
    }
  return (-1);
}
