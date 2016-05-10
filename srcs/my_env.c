/*
** my_env.c for my_env in /home/juniqu_v/rendu/PSU_2015_42sh/srcs
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  9 15:42:37 2016 virgile junique
** Last update Tue May 10 13:30:51 2016 virgile junique
*/

#include "42sh.h"
#include "my_env.h"

void	my_load_env(t_env *env, char **envp)
{
  int	i;

  i = -1;
  while(envp[++i] != '\0')
    my_add_elem(env, envp[i]);
}
