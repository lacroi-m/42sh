/*
** multi_exec.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs/multi_exec/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue May 31 15:03:40 2016 Mehdi Meridja
** Last update Thu Jun  2 11:30:24 2016 Lemeh
*/

#include <stdlib.h>

#include "42sh.h"

static void	my_free_t_parser(t_parser **parser)
{
  int		i;
  int		j;

  i = 0;
  while (parser[i]->cmd != NULL)
    {
      j = 0;
      while (parser[i]->cmd[j])
	free(parser[i]->cmd[j++]);
      free(parser[i++]->cmd);
    }
  i = 0;
  while (parser[i] != NULL)
    free(parser[i++]);
  free(parser);
  return ;
}

static int	len_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL);
  return (i);
}

static int		len_str(int *semi, int index)
{
  static int		nb = 0;

  while (nb < semi[index])
    nb++;
  return (nb);
}

static char    **wordtab_custom(t_params *p)
{
  int		j;
  int		i;
  int		k;
  int		index;
  char		**tab;
  int		nb;

  j = 0;
  i = -1;
  index = 0;
  tab = xmalloc_tab(p->semi_len * sizeof(char *));
  nb = p->semi_len + 1;
  while (--nb >= 1)
    {
      k = 0;
      tab[j] = xmalloc(sizeof(char) * (len_str(p->semi_colon, index)));
      while (i < p->semi_colon[index])
	if (p->prompt[++i] != ';')
	  tab[j][k++] = p->prompt[i];
      j++;
      index++;
    }
  tab[j] = NULL;
  return (tab);
}

int	multi_exec(t_params *p)
{
  int	i;
  char	**tab;

  i = -1;
  tab = wordtab_custom(p);
  p->parser = xmalloc(sizeof(t_parser *) * (len_tab(tab) + 1));
  free(p->prompt);
  while (tab[++i] != NULL)
    {
      p->parser[i] = xmalloc(sizeof(t_parser));
      p->parser[i]->cmd = my_str_to_wordtab(tab[i]);
    }
  my_free_ctab(tab);
  while (p->parser[++i] != NULL)
    if ((my_exec(p)) == -1)
      return (-1);
  my_free_t_parser(p->parser);
  return ;
}
