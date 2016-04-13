/*
** copy_env.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Mon Apr 11 10:41:16 2016 Mehdi Meridja
** Last update Wed Apr 13 09:51:43 2016 Mehdi
*/

#include <stdlib.h>

#include "my.h"

char	**strdup_tab(char **env)
{
  char	**envp;
  int	i;
  int	j;

  i = 0;
  if ((envp = malloc(sizeof(char *) * (my_strlen_tab(env) + 1))) == NULL)
    return (NULL);
  while (env[i])
    {
      j = 0;
      if ((envp[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	return (NULL);
      while (env[i][j])
	{
	  envp[i][j] = env[i][j];
	  j++;
	}
      envp[i][j] = 0;
      i++;
    }
  envp[i] = NULL;
  my_free_tab(env);
  return (envp);
}
