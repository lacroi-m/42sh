/*
** echo.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Fri May  6 12:43:00 2016 Mehdi Meridja
** Last update Tue May 24 14:07:01 2016 Lemeh
*/

#include "42sh.h"
#include "builtins.h"

static void	no_option(char **message)
{
  int		i;

  i = 1;
  while (message[i] != NULL)
    {
      if (message[i + 1] != NULL)
	printf("%s ", message[i]);
      else
	printf("%s", message[i]);
      i++;
    }
  printf("\n");
  return ;
}

static void	no_backslash_n(char **message)
{
  int		i;

  i = 2;
  while (message[i] != NULL)
    {
      if (message[i + 1] != NULL)
	printf("%s ", message[i]);
      else
	printf("%s", message[i]);
      fflush(stdout);
      i++;
    }
  return ;
}

int	my_echo(char **tab, char *str, t_params *p)
{
  (void)p;
  if ((strncmp(str, "-n", 2)) == 0)
    no_backslash_n(tab);
  else
    no_option(tab);
  return (0);
}
