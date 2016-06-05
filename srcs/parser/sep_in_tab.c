/*
** my_revstrcmp.c for my_revstrcmp in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Fri Jun  3 16:13:14 2016 virgile junique
** Last update Sun Jun  5 15:53:13 2016 virgile junique
*/

#include "42sh.h"

static int     checkpos(char *cmd, char *op)
{
  int		i;

  i = my_strlen(cmd) - 1;
  while (i >= 0)
    {
      if (my_strlen(op) == 1)
        {
          if (cmd[i] == op[0] && cmd[i + 1] != op[0]
              && cmd[i - 1] != op[0])
            return (i);
        }
      else if (my_strlen(op) == 2)
        {
          if (cmd[i] == op[0] && cmd[i + 1] == op[0]
              && cmd[i + 2] != op[0] && cmd[i - 1] != op[0])
            return (i);
        }
      --i;
    }
  return (-1);
}

static char    *my_getcmd(char *cmd, int start, int end)
{
  char		*tab;
  int		i;

  i = 0;
  (end == -1) ? (end = my_strlen(cmd)) : (0);
  tab = xmalloc(sizeof(char) * (end + 1 - start));
  while (start < end)
    tab[i++] = cmd[start++];
  tab[i] = '\0';
  return (tab);
}

static char    **set_tab(char *cmd, int pos, char *op)
{
  char		**tab;

  if (op)
    {
      if (pos >= 0)
        {
          tab = xmalloc(sizeof(char *) * 3);
          tab[0] = my_getcmd(cmd, 0, pos);
          tab[1] = op;
          tab[2] = my_getcmd(cmd, pos + my_strlen(op), -1);
          return (tab);
        }
      else if (pos == -1)
        {
          tab = malloc(sizeof(char *) * 3);
          tab[0] = " ";
          tab[1] = op;
          tab[2] = my_getcmd(cmd, my_strlen(op), -1);
          return (tab);
        }
    }
  return (NULL);
}

char		**sep_in_tab(char *cmd, char ***prio)
{
  t_rev		arg;

  arg.i = 0;
  arg.j = 0;
  arg.pos = 0;
  arg.op = NULL;
  while (prio[arg.i])
    {
      while (prio[arg.i][arg.j])
        {
          arg.op_stock = prio[arg.i][arg.j];
          if ((arg.pos_stock = checkpos(cmd, arg.op_stock)) > arg.pos)
            {
              arg.pos = arg.pos_stock;
              arg.op = arg.op_stock;
            }
          if (arg.op)
            return (set_tab(cmd, arg.pos, arg.op));
          else
            ++arg.j;
        }
      arg.j = 0;
      ++arg.i;
    }
  return (set_tab(cmd, arg.pos, arg.op));
}
