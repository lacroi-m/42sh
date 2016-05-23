/*
** my_env.h for my_env in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  9 14:48:59 2016 virgile junique
** Last update Mon May 23 22:57:09 2016 virgile junique
*/

#ifndef _MY_ENV_H_
# define _MY_ENV_H_

typedef struct	s_env
{
  char		*line;
  int		pos;
  struct s_env	*next;
  struct s_env	*prev;
}		t_env;

void		my_add_elem(t_env *elem, char *str);
void		my_aff_list(t_env *list);
void		my_remove_elem(t_env *list, int pos);
void		my_clear_list(t_env **env);
int		count_list(t_env *list);
char		**my_pathway(t_env *env);
char		**my_env_in_tab(t_env *env);
char		**my_path_in_tab(char *str);
t_env		*my_init_list();

#endif /* !MY_ENV_H_ */
