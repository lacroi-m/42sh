/*x
** exec.c for exec in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sat Jun  4 14:07:32 2016 virgile junique
** Last update Sun Jun  5 22:44:37 2016 virgile junique
*/

#include "42sh.h"

void		free_tree(t_node *tree)
{
  if (tree->right != NULL)
    free_tree(tree->right);
  if (tree->left != NULL)
    free_tree(tree->left);
  free(tree);
}

static void	check_fd(t_node *tree)
{
  if (tree->fd_in != 0 && tree->left && tree->right)
    {
      tree->left->fd_in = tree->fd_in;
      tree->right->fd_in = tree->fd_in;
    }
  else if (tree->fd_out != 0 && tree->left && tree->right)
    {
      tree->left->fd_out = tree->fd_out;
      tree->right->fd_out = tree->fd_out;
    }
}

int		execute(t_node *tree, char **cmd, t_params *p)
{
  char		*path;

  if (p->env_tab == NULL)
    my_free_ctab(p->env_tab);
  p->env_tab = my_env_in_tab(p->env);
  if ((tree->fd_out != 1) && (dup2(tree->fd_out, 1) == -1))
    return (1);
  if ((tree->fd_in != 0) && (dup2(tree->fd_in, 0) == -1))
    return (1);
  if (my_strncmp(cmd[0], "./", 2) == 0)
    path = cmd[0];
  else if ((path = my_access(cmd, p)) == NULL)
    {
      my_error(cmd[0]);
      kill(getpid(), SIGKILL);
    }
  if (execve(path, cmd, p->env_tab) == -1)
    return (2);
  my_free_ctab(p->env_tab);
  return (0);
}

int		my_exec(t_node *tree, t_params *p, int last)
{
  pid_t		pid;
  int		state;
  char		**cmd;

  state = -1;
  if ((cmd = my_str_to_wordtab(tree->data)) == NULL)
    return (0);
  if ((pid = fork()) == -1)
    return (1);
  if ((pid == 0) && ((state = execute(tree, cmd, p)) != 0))
      return (state);
  else
    {
      if (last)
	waitpid(pid, &state, 0);
      else
	waitpid(pid, &state, WNOHANG);
      if (WIFEXITED(state))
	return (WEXITSTATUS(state));
      else
	return (1);
    }
  return (2);
}

int		start_exec(t_node *tree, t_params *p, int last)
{
  int		state;
  int		status;

  check_fd(tree);
  if ((status = its_separator(tree->data)) >= 0)
    my_separator(tree, p, status, last);
  else
    {
      state = its_builtins(tree, p);
      if (state == -1)
	state = my_exec(tree, p, last);
      ret = state;
      set_state(p, state);
    }
  return (-1);
}
