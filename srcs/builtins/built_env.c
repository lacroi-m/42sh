/*
** built_env.c for built_env in /home/juniqu_v/rendu/PSU_2015_42sh/srcs/builtins
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 15:27:52 2016 virgile junique
** Last update Tue May 24 13:33:28 2016 Lemeh
*/

#include "42sh.h"
#include "my_env.h"
#include "builtins.h"
#include "my.h"

int	my_env(char **tab, char *str, t_params *p)
{
  (void)tab;
  (void)str;
  my_aff_list(p->env);
  write (1, "$> ", 3);
  return (0);
}

int	my_found_in_env(char *str, t_env *env)
{
  t_env	*tmp;
  int	len;
  int	pos;

  pos = -1;
  tmp = env->next;
  len = my_strlen(str);
  while (tmp != env)
    {
      if (my_strncmp(tmp->line, str, len) == 0)
	return (pos);
      tmp = tmp->next;
      pos++;
    }
  return (-1);
}

int	my_setenv(char **tab, char *line, t_params *p)
{
  char	**elem;
  char	*str;
  int	i;
  int	j;

  (void)tab;
  i = 0;
  j = 0;
  elem = my_str_to_wordtab(line);
  if (elem[i] == NULL)
    my_aff_list(p->env);
  else if (elem[2] != NULL)
    {
      str = xmalloc(sizeof(char) * (my_strlen(elem[1]) + my_strlen(elem[2]) + 2));
      while (elem[1][i++])
	str[i] = elem[1][i];
      str[i++] = '=';
      while (elem[2][j])
	str[i++] = elem[2][j++];
      str[i] = '\0';
      my_add_elem(p->env, str);
    }
  my_free_ctab(elem);
  return (0);
}

int	my_unsetenv(char **tab, char *line, t_params *p)
{
  char	**elem;
  int	pos;

  (void)tab;
  elem = my_str_to_wordtab(line);
  if (elem[1] != NULL)
    {
      pos = my_found_in_env(elem[1], p->env);
      if (pos == -2)
	return (my_putstr("Element not found.\n", -1, 2));
      else
	my_remove_elem(p->env, pos);
    }
  else
    return (my_putstr("Unsetenv: Too few arguments.\n", -1, 2));
  my_free_ctab(elem);
  return (0);
}
