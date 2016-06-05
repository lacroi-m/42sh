/*
** separator.c for separator in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sat Jun  4 15:27:49 2016 virgile junique
** Last update Sun Jun  5 23:17:19 2016 virgile junique
*/

#include "42sh.h"

static int	sep_or(t_node *tree, t_params *p, int last)
{
  (void)last;
  if (start_exec(tree->left, p, 1) == -1)
    return (1);
  else
    start_exec(tree->right, p, 1);
  return (0);
}

static int	sep_and(t_node *tree, t_params *p, int last)
{
  (void)last;
  if (start_exec(tree->left, p, 1) == -1)
    start_exec(tree->right, p, 1);
  return (0);
}

static int	sep_semicolon(t_node *tree, t_params *p, int last)
{

  (void)last;
  if (tree->left->data)
    start_exec(tree->left, p, 1);
  if (tree->right->data)
    start_exec(tree->right, p, 1);
  return (0);
}

int     my_separator(t_node *tree, t_params *p, int pos, int last)
{
  int   (*tab[8])(t_node *tree, t_params *p, int last);
  int   r;

  tab[0] = &sep_and;
  tab[1] = &sep_or;
  tab[2] = &sep_semicolon;
  tab[3] = &sep_redirectr;
  tab[4] = &sep_dubredirectr;
  tab[5] = &sep_redirectl;
  tab[6] = &sep_dubredirectl;
  tab[7] = &sep_pipe;
  r = tab[pos](tree, p, last);
  return (r);
}

int     its_separator(char *str)
{
  char  *tab[9];
  int   i;

  i = -1;
  tab[0] = "&&";
  tab[1] = "||";
  tab[2] = ";";
  tab[3] = ">";
  tab[4] = ">>";
  tab[5] = "<";
  tab[6] = "<<";
  tab[7] = "|";
  tab[8] = NULL;
  while (tab[++i])
    {
      if (my_strcmp(str, tab[i]) == 0)
        return (i);
    }
  return (-1);
}
