/*
** separator3.c for separator in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sat Jun  4 18:12:49 2016 virgile junique
** Last update Sun Jun  5 15:37:08 2016 virgile junique
*/

#include "42sh.h"

static char    	*buff_entry()
{
 static char	buff[1024];
  int		size;

  write (1, "?", 1);
  if ((size = read(0, buff, 1023)) < 0)
    return (0);
  else if (size == 0)
    return (0);
  else
    {
      buff[size - 1] = '\0';
      return (buff);
    }
  return (0);
}

static int     	stand_entry(char *line)
{
  char		*buff;
  int		fd;

  buff = NULL;
  if ((fd = open("/tmp/.secret", O_WRONLY | O_CREAT
		| O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    return (-1);
  while (my_strcmp(buff, line) != 0)
    {
      buff = buff_entry();
      if (my_strcmp(buff, line) != 0)
	{
	  my_putstr(buff, fd, 0);
	  my_putchar('\n', fd);
	}
    }
  if (close(fd) == -1)
    return (-1);
  return (0);
}

int		sep_dubredirectl(t_node *tree, t_params *p, int last)
{
  t_node	*right;
  char		**file;
  int		fd;

  (void)last;
  right = tree->right;
  if (right->data)
    {
      if (!(file = my_str_to_wordtab(right->data)))
	return (my_putstr("Missing right operand after <<\n", 2, -1));
      stand_entry(file[0]);
      if ((fd = open("/tmp/.secret", O_RDONLY)) == -1)
	return (-1);
      tree->left->fd_in = fd;
      start_exec(tree, p, 1);
      close(fd);
    }
  else
    return (my_putstr("Missing right operand after <<\n", 2, -1));
  return (0);
}
