/*
** syntaxe.c for syntaxe in /home/juniqu_v/rendu/PSU_2015_42sh/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 30 15:24:00 2016 virgile junique
** Last update Tue May 31 11:00:54 2016 virgile junique
*/

#include "42sh.h"
#include "my.h"

void		err_syntax(int state)
{
  if (state == -1)
    my_putstr("Error with brackets.\n", 2, -1);
  else if (state == -2)
    my_putstr("Error with quotes.\n", 2, -1);
  else
    return ;
  return ;
}

static int      check_quote(char *str)
{
  int           i;
  int           j;
  int           save;

  i = -1;
  j = 0;
  while (str[++i])
    {
      if (str[i] == '"' && j == 0)
        {
          ++j;
          save = i;
        }
      if (str[i] == '"' && save != i)
        --j;
      if (j < 0)
        return (-1);
    }
  if (j == 0)
    return (0);
  return (-1);
}

static int      check_brackets(char *str)
{
  int           i;
  int           j;

  i = -1;
  j = 0;
  while (str[++i])
    {
      if (str[i] == '(')
        ++j;
      if (str[i] == ')')
        --j;
      if (j < 0)
        return (-1);
    }
  if (j == 0)
    return (0);
  return (-1);
}

static void     fill_pos(t_params *p, int nb)
{
  int           i;
  int		j;

  i = 0;
  j = 0;
  p->semi_colon = xmalloc(sizeof(int) * (nb + 1));
  while (p->prompt[i])
    {
      if (p->prompt[i] == '('
          || p->prompt[i] == '"')
        {
	  while (p->prompt[i] &&
                 (p->prompt[i] != ')' || p->prompt[i] != '"'))
	    i++;
        }
      if (p->prompt[i] == ';')
        p->semi_colon[j++] = i;
      i++;
    }
  p->semi_colon[j] = 0;
}

int		check_syntax(t_params *p)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  if (check_brackets(p->prompt) == -1)
    return (-1);
  if (check_quote(p->prompt) == -1)
    return (-2);
  while (p->prompt[i] != '\0')
    {
      if (p->prompt[i] == '('
          || p->prompt[i] == '"')
        {
          while (p->prompt[i] &&
                 (p->prompt[i] != ')' || p->prompt[i] != '"'))
            i++;
        }
      if (p->prompt[i] == ';')
        nb++;
      i++;
    }
  if (nb > 0)
    fill_pos(p, nb);
  return (nb);
}
