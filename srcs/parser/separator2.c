/*
** separator2.c for separator2 in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sat Jun  4 16:07:07 2016 virgile junique
** Last update Sun Jun  5 21:21:50 2016 virgile junique
*/

#include "42sh.h"

int		sep_redirectr(t_node *tree, t_params *p, int last)
{
  t_node	*right;
  char		**file;
  int		fd;

  (void)last;
  right = tree->right;
  if (right)
    {
      if (!(file = my_str_to_wordtab(right->data)))
	return (my_putstr("Missing right operand after >\n", 2, -1));
      if ((fd = open(file[0], O_WRONLY | O_TRUNC
		     | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
	return (-1);
      tree->left->fd_out = fd;
      start_exec(tree->left, p, 1);
      close(fd);
    }
  else
    return (my_putstr("Missing right operand after >\n", 2, -1));
  return (0);
}

int		sep_dubredirectr(t_node *tree, t_params *p, int last)
{
  t_node	*right;
  char		**file;
  int		fd;

  (void)last;
  right = tree->right;
  if (right->data)
    {
      if (!(file = my_str_to_wordtab(right->data)))
	return (my_putstr("Missing right operand after >>\n", 2, -1));
      if ((fd = open(file[0], O_WRONLY | O_APPEND
		     | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
	return (-1);
      tree->left->fd_out = fd;
      start_exec(tree->left, p, 1);
      close(fd);
    }
  else
    return (my_putstr("Missing right operand after >>\n", 2, -1));
  return (0);
}

int		sep_redirectl(t_node *tree, t_params *p, int last)
{
  t_node	*right;
  char		**file;
  int		fd;

  (void)last;
  right = tree->right;
  if (right->data)
    {
      if (!(file = my_str_to_wordtab(right->data)))
	return (my_putstr("Missing right operand after <\n", 2, -1));
      if ((fd = open(file[0], O_RDONLY)) == -1)
	return (-1);
      tree->left->fd_in = fd;
      start_exec(tree->left, p, 1);
      close(fd);
    }
  else
    return (my_putstr("Missing right operand after <\n", 2, -1));
  return (0);
}

int		sep_pipe(t_node *tree, t_params *p, int last)
{
  int		fd_pipe[2];

  if (tree->left->data == NULL || tree->right->data == NULL)
    return (-1);
  if ((pipe(fd_pipe)) == -1)
    return (-1);
  if (tree->left)
    tree->left->fd_out = fd_pipe[1];
  if (tree->right)
    tree->right->fd_in = fd_pipe[0];
  if (last)
    {
      start_exec(tree->left, p, 0);
      close(fd_pipe[1]);
      start_exec(tree->right, p, 1);
      close(fd_pipe[0]);
    }
  else
    {
      start_exec(tree->left, p, 0);
      close(fd_pipe[1]);
      start_exec(tree->right, p, 1);
      close(fd_pipe[0]);
    }
  return (0);
}
