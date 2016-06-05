/*
** 42sh.h for 42sh in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 13:02:44 2016 virgile junique
** Last update Sun Jun  5 23:25:44 2016 virgile junique
*/

#ifndef _42SH_H_
# define _42SH_H_

# include "my.h"
# include "my_env.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "get_next_line.h"

int		ret;

typedef struct s_params
{
  int		state;
  t_env		*env;
  char		**path_tab;
  char		**env_tab;
}		t_params;

# include "tree.h"
# include "builtins.h"

void		my_load_env(t_params *p, char **envp);
void		my_init(t_params *p);
int		check_input(char *input);
int		my_error(char *str);

#endif /* !42SH_H_ */
