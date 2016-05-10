/*
** my_env.h for my_env in /home/juniqu_v/rendu/PSU_2015_42sh/include
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  9 14:48:59 2016 virgile junique
** Last update Mon May  9 15:48:32 2016 virgile junique
*/

#ifndef _MY_ENV_H_

#define _MY_ENV_H_

typedef struct	s_env
{
  char		*line;
  int		pos;
  struct s_env	*next;
  struct s_env	*prev;
}		t_env;

void		my_load_env(t_env *env, char **envp);
void		my_add_elem(t_env *elem, char *str);
void		my_aff_list(t_env *list);
void		my_revome_elem(t_env *list, int pos);
void		my_clear_list(t_env **env);
t_env		*my_init_list();

#endif /* !MY_ENV_H_ */
