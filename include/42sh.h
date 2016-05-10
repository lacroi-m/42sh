/*
** 42sh.h for 42sh in /home/juniqu_v/rendu/PSU_2015_42sh/include
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  2 13:02:44 2016 virgile junique
** Last update Tue May 10 15:44:31 2016 virgile junique
*/

#ifndef _42SH_H_

# define _42SH_H_

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include "get_next_line.h"
# include "my.h"
# include "my_env.h"

typedef struct s_params
{
  t_env		*env;
  char		*prompt;
  /* struct parametre a faire bouge */
}		t_params;

void	my_loop(t_params *p);
void	my_exit(t_params *p, int value);

#endif /* !42SH_H_ */
