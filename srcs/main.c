/*
** main.c for all in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Tue May 31 10:51:03 2016 virgile junique
*/

#include "42sh.h"
#include "my_env.h"
#include "builtins.h"

static void    	my_loop(t_params *p)
{
  int		syntaxe;

  syntaxe = 0;
  while (write(1, "$> ", 3) != -1 && (p->prompt = get_next_line(0)))
    {
      if (p->prompt[0] == 0)
	{
	  free(p->prompt);  /* et la pas le choix */
	  continue;
	}
      else if ((syntaxe = check_syntax(p)) > 0)
	my_exec(p); /* pensez a free le prompt dedans */
      else
	{
	  if (syntaxe <= -1)
	    {
	      err_syntax(syntaxe);
	      free(p->prompt);
	      continue;
	    }
	  my_exec(p); /* pareil ici */
	}
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
