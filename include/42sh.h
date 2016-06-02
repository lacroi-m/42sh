/*
** 42sh.h for 42sh in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 13:02:44 2016 virgile junique
** Last update Thu Jun  2 11:51:15 2016 Lemeh
*/

#ifndef _42SH_H_
# define _42SH_H_

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
# include "my.h"
# include "my_env.h"
# include "parser.h"

typedef struct s_params
{
  t_env		*env;
  int		*semi_colon;
  int		semi_len;
  char		*prompt;
  char		**path_tab;
  char		**env_tab;
  t_parser	**parser;
}		t_params;

void            multi_exec(t_params *p);

# include "builtins.h"

void		err_syntax(int state);
void		my_exec(t_params *p);
void		my_load_env(t_params *p, char **envp);
void		my_init(t_params *p);
int		check_syntax(t_params *p);

#endif /* !42SH_H_ */
