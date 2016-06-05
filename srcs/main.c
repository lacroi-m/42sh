/*
** main.c for all in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Sun Jun  5 11:51:30 2016 virgile junique
*/

#include "42sh.h"

int		main(int ac, char **av, char **envp)
{
  t_params	p;

  (void)ac;
  (void)av;
  my_init(&p);
  if (envp != NULL)
    {
      p.env = my_init_list();
      my_load_env(&p, envp);
    }
  else
    p.env = my_init_list();
  my_loop(&p);
  my_exit((char**)"10", &p);
  return (0);
}
