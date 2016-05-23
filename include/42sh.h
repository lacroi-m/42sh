/*
** 42sh.h for 42sh in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 13:02:44 2016 virgile junique
** Last update Mon May 23 16:07:26 2016 virgile junique
*/

#ifndef _42SH_H_

# define _42SH_H_

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "get_next_line.h"
# include "my.h"
# include "my_env.h"
# include "builtins.h"

typedef struct s_params
{
  t_env		*env;
  char		*prompt;
  char		**path_tab;
  char		**env_tab;
}		t_params;


void	my_exec(t_params *p);
void	my_load_env(t_params *p, char **envp);
void	my_loop(t_params *p);
int	my_exit(char *str, t_params *p, int value);
void	my_init(t_params *p);
void	my_free_tab(char **tab);

#endif /* !42SH_H_ */
