/*
** built_env.c for built_env in /home/juniqu_v/rendu/PSU_2015_42sh/srcs/builtins
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 15:27:52 2016 virgile junique
** Last update Sun Jun  5 23:16:07 2016 virgile junique
*/

#include "42sh.h"

int	my_env(char **cmd, t_params *p)
{
  (void)cmd;
  my_aff_list(p->env);
  return (0);
}

int	my_found_in_env(char *str, t_env *env)
{
  t_env	*tmp;
  int	len;
  int	pos;

  pos = 0;
  tmp = env->next;
  len = my_strlen(str);
  while (tmp != env)
    {
      if (strncmp(tmp->line, str, len) == 0)
	return (pos);
      tmp = tmp->next;
      pos++;
    }
  return (-1);
}

int	my_setenv(char **cmd, t_params *p)
{
  char	*str;
  int	i;
  int	j;
  int	state;

  i = -1;
  j = 0;
  if ((state = my_found_in_env("?=", p->env)) >= 0)
    my_remove_elem(p->env, state);
  if (cmd[1] == NULL)
    my_aff_list(p->env);
  else if (cmd[2] != NULL)
    {
      str = xmalloc(sizeof(char)
		    * (my_strlen(cmd[1]) + my_strlen(cmd[2]) + 3));
      while (cmd[1][++i])
	str[i] = cmd[1][i];
      str[i++] = '=';
      while (cmd[2][j])
	str[i++] = cmd[2][j++];
      str[i] = '\0';
      my_add_elem(p->env, str);
    }
  return (0);
}

int	my_unsetenv(char **cmd, t_params *p)
{
  int	pos;

  if (cmd[1] != NULL)
    {
      pos = my_found_in_env(cmd[1], p->env);
      if (pos == -2)
	return (my_putstr("Element not found.\n", 2, 2));
      else
	my_remove_elem(p->env, pos);
    }
  else
    return (my_putstr("Unsetenv: Too few arguments.\n", 2, 2));
  return (0);
}
