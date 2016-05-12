/*
** main.c for all in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Thu May 12 18:17:40 2016 virgile junique
*/

#include "42sh.h"
#include "my_env.h"

void	my_loop(t_params *p)
{
  while ((p->prompt = get_next_line(0)))
    {
      /*  my_parser(p, str);
	  my_exec(p);*/
      free(p->prompt);
      write(1, "$>", 2);
    }
}

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
  my_exit(&p, 1);
  return (0);
}
