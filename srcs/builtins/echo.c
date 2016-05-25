/*
** echo.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Fri May  6 12:43:00 2016 Mehdi Meridja
** Last update Wed May 25 16:25:28 2016 Lemeh
*/

#include "42sh.h"
#include "builtins.h"

static char	*parsing_quote(char *str)
{
  int		i;

  i = -1;
  if (str[0] == '"')
    {
      while (str[++i] != 0)
	str[i] = str[i + 1];
      i = strlen(str) - 1;
      if (str[i] == '"' || str[i + 1] == '"')
	str[i] = 0;
    }
  return (str);
}

static void	with_bachslash_n(char **tab)
{
  int		i;

  i = 1;
  while (tab[++i] != NULL)
    if (tab[i + 1] != NULL)
      printf("%s ", parsing_quote(tab[i]));
    else
      printf("%s", parsing_quote(tab[i]));
  return ;
}

static void	no_option(char **tab)
{
  int		i;

  i = 0;
  while (tab[++i] != NULL)
    if (tab[i + 1] != NULL)
      printf("%s ", parsing_quote(tab[i]));
    else
      printf("%s", parsing_quote(tab[i]));
  printf("\n");
  return ;
}

int	my_echo(char *str, t_params *p)
{
  char	**tab;

  (void)str;
  tab = my_str_to_wordtab(p->prompt);
  if (tab[1])
    if (strcmp("-n", tab[1]) == 0)
      with_bachslash_n(tab);
    else
      no_option(tab);
  else
    printf("\n");
  my_free_ctab(tab);
  return (0);
}
