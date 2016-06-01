/*
** multi_exec.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs/multi_exec/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue May 31 15:03:40 2016 Mehdi Meridja
** Last update Wed Jun  1 14:42:13 2016 Mehdi Meridja
*/

#include "parser.h"

static int     cpt_words(char *str)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if (str[i] != 0 && str[i] != ';')
	{
          cpt++;
          while (str[i] != 0 && str[i] != ';')
            i++;
	}
      if (str[i] != 0)
        i++;
    }
  return (cpt);
}

static char    **wordtab_custom(char *str)
{
  int   	i;
  int   	j;
  int   	deb;
  char  	**tab;

  j = 0;
  i = 0;
  deb = 0;
  if ((tab = malloc(sizeof(char *) * (cpt_words(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      if (str[i] != 0 && str[i] != ';')
        {
          deb = i;
          while (str[i] != 0 && str[i] != ';')
            i++;
          tab[j++] = my_strndup(&str[deb], i - deb);
        }
      else
        i++;
    }
  tab[j] = NULL;
  return (tab);
}

void	my_free_t_parser(t_parser **parser)
{
  int	i;

  i = 0;
  while (parser[i] != NULL)
    free(parser[i++]);
  free(parser);
  return ;
}

void		multi_exec(t_params *p)
{
  int		i;
  char		**tab;
  t_parser	**parser;

  i = -1;
  parser = xmalloc(sizeof(t_parser *) * (p->len_tab));
  tab = wordtab_custom(p->prompt);
  free(p->prompt);
  while (tab[++i] != NULL)
    {
      parser[i] = xmalloc(sizeof(t_parser));
      parser[i]->cmd = my_str_to_wordtab(tab[i]);
    }
  my_free_ctab(tab);
  i = -1;
  while (parser[++i] != NULL)
    my_exec(p, parser[i]);
  my_free_t_parser(parser);
  return ;
}
