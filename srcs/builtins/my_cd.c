/*
** my_cd.c for my_cd in /home/juniqu_v/rendu/PSU_2015_42sh/srcs/builtins
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Tue May 31 10:36:55 2016 virgile junique
** Last update Sun Jun  5 23:10:30 2016 virgile junique
*/

#include "42sh.h"

static int      refresh_old(char *old, t_env *env, t_params *p)
{
  t_env         *tmp;

  tmp = env->next;
  while (tmp != env)
    {
      if (my_strncmp(tmp->line, "OLDPWD=", 7) == 0)
        {
          tmp->line = my_strdup(old);
          return (0);
        }
      tmp = tmp->next;
    }
  my_add_elem(env, old);
  my_free_ctab(p->env_tab);
  p->env_tab = my_env_in_tab(env);
  return (0);
}

static int      refresh_pwd(t_params *p, t_env *env, char *pwd)
{
  t_env         *tmp;
  char          *old;

  tmp = env->next;
  while (tmp != env)
    {
      if (strncmp("PWD=", tmp->line, 4) == 0)
        {
          old = strcat("OLD", tmp->line);
          free(tmp->line);
          tmp->line = my_strdup(pwd);
        }
      tmp = tmp->next;
    }
  return (refresh_old(old, env, p));
}

int		go_dir(char *str, t_params *p)
{
  if (access(str, F_OK || R_OK) != 0)
    {
      my_putstr(str, 2, -1);
      return (my_putstr(": Not a directory.\n", 2, 1));
    }
  if (chdir(str) == -1)
    {
      my_putstr(str, 2, -1);
      return (my_putstr(": No such file or directory.\n", 2, 1));
    }
  return (refresh_pwd(p, p->env, str));
}

int		go_home(t_params *p, t_env *env)
{
  char          *str;
  t_env         *tmp;

  tmp = env->next;
  while (tmp != env)
    {
      if (my_strncmp(tmp->line, "HOME=", 5) == 0)
        str = my_strdup(&tmp->line[5]);
      tmp = tmp->next;
    }
  if (str == NULL)
    return (my_putstr("cd: No home directory\n", 2, 1));
  if (chdir(str) == -1)
    {
      free(str);
      return (my_putstr("Error on cd.\n", 2, 1));
    }
  return (refresh_pwd(p, env, str));
}

int		my_old(t_params *p, t_env *env)
{
  t_env         *tmp;
  char          *str;

  tmp = env->next;
  while (tmp != env)
    {
      if (my_strncmp(tmp->line, "OLDPWD=", 7) == 0)
        str = my_strdup(&tmp->line[7]);
      tmp = tmp->next;
    }
  if (str == NULL)
    return (my_putstr(": No such file or directory.\n", 2, 1));
  else
    {
      chdir(str);
      free(str);
    }
  return (refresh_pwd(p, env, str));
}
