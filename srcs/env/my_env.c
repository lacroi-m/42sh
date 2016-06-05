/*
** my_env.c for my_env in /home/juniqu_v/rendu/PSU_2015_42sh/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  9 15:42:37 2016 virgile junique
** Last update Sun Jun  5 11:34:09 2016 virgile junique
*/

#include "42sh.h"

int	count_list(t_env *list)
{
  int	n;
  t_env	*tmp;

  n = 0;
  tmp = list->next;
  while (tmp != list)
    {
      n++;
      tmp = tmp->next;
    }
  return (n);
}

char	**my_env_in_tab(t_env *env)
{
  int	len_env;
  int	i;
  char	**tab;
  t_env	*tmp;

  i = 0;
  len_env = count_list(env);
  tab = xmalloc(sizeof(char*) * (len_env + 1));
  tmp = env->next;
  while (tmp != env)
    {
      tab[i++] = my_strndup(tmp->line, my_strlen(tmp->line));
      tmp = tmp->next;
    }
  tab[i] = '\0';
  return (tab);
}

char	**my_path_in_tab(char *str)
{
  char  **tab;
  int   i;
  int   j;
  int   k;
  int   nb;
  int   len;

  i = 1;
  j = 4;
  count_word(str, &nb);
  tab = xmalloc(sizeof(char*) * (nb + 1));
  while (i <= nb)
    {
      len = len_word(str, i);
      tab[i - 1] = xmalloc(sizeof(char) * (len + 1));
      k = 0;
      j++;
      while (str[j] && str[j] != ':')
	tab[i - 1][k++] = str[j++];
      tab[i - 1][k] = '\0';
      tab[i - 1] = check_slash(tab[i - 1]);
      i++;
    }
  tab[i - 1] = '\0';
  return (tab);
}

char	**my_pathway(t_env *env)
{
  t_env	*tmp;
  char	**path;

  path = 0;
  tmp = env->next;
  while (tmp != env)
    {
      if (strncmp(tmp->line, "PATH=", 5) == 0)
	return (path = my_path_in_tab(tmp->line));
      tmp = tmp->next;
    }
  if ((path == NULL)
      || (path = xmalloc(sizeof(char *) *1)) != NULL)
    path[0] = NULL;
  return (path);
}

void	my_load_env(t_params *p, char **envp)
{
  int	i;

  i = -1;
  while (envp[++i] != '\0')
    my_add_elem(p->env, envp[i]);
  p->path_tab = 0;
  p->env_tab = my_env_in_tab(p->env);
}
