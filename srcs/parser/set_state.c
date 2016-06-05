/*
** fonction.c for  in /home/lacroi_m/PSU_2015_42sh
**
** Made by Lacroix Maxime
** Login   <lacroi_m@epitech.net>
**
** Started on  Sat Jun  4 15:36:13 2016 Lacroix Maxime
** Last update Sun Jun  5 23:23:33 2016 virgile junique
*/

#include "42sh.h"

static char	*nbr_to_str(int	i)
{
  int		tmp;
  char		*nbr;

  nbr = NULL;
  if ((i / 10) == 0)
    {
      nbr = xmalloc(sizeof(char) * 2);
      nbr[0] = (i + 48);
      nbr[1] = '\0';
      return (nbr);
    }
  else if ((i / 10) < 10)
    {
      nbr = xmalloc(sizeof(char) * 3);
      tmp = i / 10;
      nbr[0] = (tmp + 48);
      tmp = i % 10;
      nbr[1] = (tmp + 48);
      nbr[2] = '\0';
      return (nbr);
    }
  return (nbr);
}

void	set_state(t_params *p, int state)
{
  char	*nbr;
  char	**tab;

  nbr = nbr_to_str(state);
  tab = xmalloc(sizeof(char *) * 4);
  tab[0] = my_strdup("state");
  tab[1] = my_strdup("?");
  tab[2] = nbr;
  tab[3] = NULL;
  my_setenv(tab, p);
  my_free_ctab(tab);
}

char		*my_access(char **cmd, t_params *p)
{
  int		i;
  char		*command;

  i = -1;
  if (p->path_tab != NULL)
    my_free_ctab(p->path_tab);
  p->path_tab = my_pathway(p->env);
  while (p->path_tab[++i])
    {
      command = my_strcat(p->path_tab[i], cmd[0]);
      if ((access(command, X_OK)) == 0)
	{
	  my_free_ctab(p->path_tab);
	  return (command);
	}
      free(command);
    }
  return (NULL);
}
