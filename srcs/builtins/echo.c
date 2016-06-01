/*
** echo.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Fri May  6 12:43:00 2016 Mehdi Meridja
** Last update Wed Jun  1 14:39:01 2016 Mehdi Meridja
*/

#include "42sh.h"
#include "builtins.h"

int	cpt_quote(char *str)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (str[++i])
    {
      if (str[i] == '"')
	nb++;
    }
  return (nb);
}

static char	*parsing_quote(char *str)
{
  char		*new;
  int		i;

  new = xmalloc(sizeof(char) * (my_strlen(str) - cpt_quote(str)));
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != '"')
	new[i] = str[i];
      i++;
    }
  free(str);
  return (new);
}

static void	with_bachslash_n(char **tab)
{
  int		i;

  i = 1;
  while (tab[++i] != NULL)
    {
      if (tab[i + 1] != NULL)
	printf("%s ", parsing_quote(tab[i]));
      else
	printf("%s", parsing_quote(tab[i]));
    }
  return ;
}

static void	no_option(char **tab)
{
  int		i;

  i = 0;
  while (tab[++i] != NULL)
    {
      if (tab[i + 1] != NULL)
	printf("%s ", parsing_quote(tab[i]));
      else
	printf("%s", parsing_quote(tab[i]));
    }
  printf("\n");
  return ;
}

int	my_echo(char *str, t_params *p)
{
  char	**tab;

  (void)str;
  tab = my_str_to_wordtab(p->prompt);
  printf(parsing_quote(tab[1]));
  if (tab[1])
    {
      if (strcmp("-n", tab[1]) == 0)
	with_bachslash_n(tab);
      else
	no_option(tab);
    }
  else
    printf("\n");
  my_free_ctab(tab);
  return (0);
}
