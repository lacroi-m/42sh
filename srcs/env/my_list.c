/*
** my_list.c for my_list in /home/juniqu_v/rendu/PSU_2015_42sh/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  9 14:59:47 2016 virgile junique
** Last update Sun Jun  5 19:45:24 2016 virgile junique
*/

#include "42sh.h"

t_env	*my_init_list(void)
{
  t_env	*env;

  if ((env = xmalloc(sizeof(*env))) != NULL)
    {
      env->next = env;
      env->prev = env;
      env->pos = 0;
    }
  return (env);
}

void	my_add_elem(t_env *elem, char *str)
{
  t_env *new;

  if ((new = xmalloc(sizeof(*new))) != NULL)
    {
      new->line = str;
      new->pos = new->pos + 1;
      new->prev = elem->prev;
      new->next = elem;
      elem->prev->next = new;
      elem->prev = new;
    }
  return ;
}

void	my_aff_list(t_env *list)
{
  t_env	*aff;

  aff = list->next;
  while (aff != list)
    {
      my_putstr(aff->line, 1, 0);
      my_putchar('\n', 1);
      aff = aff->next;
    }
  return ;
}

void	my_remove_elem(t_env *list, int pos)
{
  int	i;
  t_env	*elem;

  elem = list->next;
  i = -1;
  while (++i < pos)
    elem = elem->next;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
  return ;
}

void	my_clear_list(t_env **env)
{
  t_env	*nxt;
  t_env	*list;

  list = (*env)->next;
  while (list != *env)
    {
      nxt = list->next;
      free(list);
      list = nxt;
    }
  free(*env);
  *env = NULL;
  return ;
}
