/*
** built_env.c for built_env in /home/juniqu_v/rendu/PSU_2015_42sh/srcs/builtins
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 15:27:52 2016 virgile junique
** Last update Mon May 23 16:05:07 2016 virgile junique
*/

#include "42sh.h"
#include "builtins.h"
#include "my.h"

void	my_env(t_env *env)
{
  my_aff_list(env);
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

void	my_setenv(char *line, t_params *p, int value)
{
  char	**elem;
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  (void)value;
  elem = my_str_to_wordtab(line);
  if (elem[i] == NULL)
    my_aff_list(p->env);
  else if (elem[2] != NULL)
    {
      str = xmalloc(sizeof(char * (my_strlen(eleme[1]) + my_strlen(elem[2]) + 2)));
      while (elem[1][i])
	str[i] = elem[1][i++];
      str[i++] = '=';
      while (elem[2][j])
	str[i++] = elem[2][j++];
      str[i] = '\0';
      my_add_elem(p->env, str);
    }
  my_free_tab(elem);
}

int	my_unsetenv(t_params *p, char *line)
{
  char	**elem;
  int	pos;

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
  my_free_tab(elem);
  return (0);
}