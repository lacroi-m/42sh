/*
** main.c for all in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Mon May 23 23:21:01 2016 virgile junique
*/

#include "42sh.h"
#include "my_env.h"
#include "builtins.h"

void	my_loop(t_params *p)
{
  char	**tab;
  int	pos;

  while ((p->prompt = get_next_line(0)))
    {
      tab = my_str_to_wordtab(p->prompt);
      if (p->prompt[0] == 0)
	write(1, "$> ", 3);
      else if ((pos = its_builtins(tab[0])) > 0)
	my_builtins(tab[1], p, pos);
      else
	{
	  /*  my_parser(p, str);*/
	  my_exec(p);
	  write(1, "$> ", 3);
	}
      my_free_ctab(tab);
      free(p->prompt);
      pos = -1;
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
  my_exit("10", &p);
  return (0);
}
