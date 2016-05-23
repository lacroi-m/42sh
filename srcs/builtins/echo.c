/*
** echo.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Fri May  6 12:43:00 2016 Mehdi Meridja
** Last update Mon May 23 22:34:00 2016 virgile junique
*/

#include "42sh.h"
#include "builtins.h"

static int	check_option(char **option)
{
  int		i;

  i = 0;
  while (option[++i] != NULL)
    {
      if ((strncmp(option[i], "-n", 2)) == 0)
	return (1);
    }
  return (0);
}

static void	no_option(char **message)
{
  int		i;

  i = 0;
  while (message[++i] != NULL)
    {
      if (message[i + 1] != NULL)
	printf("%s ", message[i]);
      else
	printf("%s", message[i]);
    }
  printf("\n");
  return ;
}

static void	no_backslash_n(char **message)
{
  int		i;

  i = 1;
  while (message[++i] != NULL)
    {
      if (message[i + 1] != NULL)
	printf("%s ", message[i]);
      else
	printf("%s", message[i]);
    }
  return ;
}

int	my_echo(char *str, t_params *p)
{
  char	**message;

  (void)p;
  message = wordtab_custom(str);
  if ((check_option(message)) == 1)
    no_backslash_n(message);
  else
    no_option(message);
  my_free_ctab(message);
  return (0);
}
