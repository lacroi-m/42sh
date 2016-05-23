/*
** main.c for all in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Mon May 23 15:17:08 2016 theo da-silva
*/

#include "42sh.h"
#include "my_env.h"

void	my_loop(t_params *p)
{
  while ((p->prompt = get_next_line(0)))
    {
      if (p->prompt[0] == 0)
	write(1, "$> ", 3);
      else
	{
	  /*  my_parser(p, str);*/
	  my_exec(p);
	  write(1, "$> ", 3);
	}
      free(p->prompt);
    }
  return ;
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
  my_exit("exit", &p, 1);
  return (0);
}
