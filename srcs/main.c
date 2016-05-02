/*
** main.c for all in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Mon May  2 13:02:27 2016 virgile junique
*/

#include "42sh.h"

void	my_loop(t_env *p)
{
  char	*str;

  str = NULL;
  while ((str = get_next_line(0)))
    {
      my_parser(p, str);
      my_exec(p);
      free(str);
      write(1, "$>", 2);
    }
}

int	main(int ac, char **av, char **env)
{
  t_env	p;

  (void)ac;
  (void)av;
  my_init();
  my_env();
  my_loop(&p);
  return (0);
}
