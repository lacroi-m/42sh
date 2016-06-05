/*
** separator3.c for separator in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sat Jun  4 18:12:49 2016 virgile junique
** Last update Sun Jun  5 21:27:52 2016 virgile junique
*/

#include "42sh.h"

static int     	stand_entry(char *line)
{
  char		buff[1024];
  int		size;

  while (write(1, "?", 1) && ((size = read(0, buff, 1023)) > 0))
    {
      buff[size] = '\0';
      if (my_strncmp(buff, line, my_strlen(line)) == 0)
	return (0);
    }
  return (0);
}

int		sep_dubredirectl(t_node *tree, t_params *p, int last)
{
  t_node	*right;
  char		**file;

  (void)last;
  right = tree->right;
  if (right->data)
    {
      if (!(file = my_str_to_wordtab(right->data)))
	return (my_putstr("Missing right operand after <<\n", 2, -1));
      stand_entry(file[0]);
      tree->left->fd_in = 0;
      start_exec(tree->left, p, 1);
    }
  else
    return (my_putstr("Missing right operand after <<\n", 2, -1));
  return (0);
}
