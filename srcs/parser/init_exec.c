/*
** tree.c for tree in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Fri Jun  3 13:51:18 2016 virgile junique
** Last update Sun Jun  5 23:26:30 2016 virgile junique
*/

#include "42sh.h"

t_node   *new_node(t_node *left, char *data, t_node *right)
{
  t_node *node;

  node = xmalloc(sizeof(t_node));
  node->data = data;
  node->fd_in = 0;
  node->fd_out = 1;
  node->right = right;
  node->left = left;
  return (node);
}

t_node   *my_parse(char *prompt, char ***prio)
{
  t_node *new;
  char  **tab;

  if ((tab = sep_in_tab(prompt, prio)))
    return (new = new_node(my_parse(tab[0], prio), tab[1],
			   my_parse(tab[2], prio)));
  return ((new = new_node(NULL, my_strdup(prompt), NULL)));
}

static char    ***init_prio()
{
  char		***prio;

  prio = xmalloc(sizeof(char **) * 6);
  prio[0] = my_str_to_wordtab(COLON);
  prio[1] = my_str_to_wordtab(SEP);
  prio[2] = my_str_to_wordtab(REDI);
  prio[3] = my_str_to_wordtab(REDI2);
  prio[4] = my_str_to_wordtab(PIPE);
  prio[5] = NULL;
  return (prio);
}

void		end_process(t_node *tree)
{
  int		status;

  if (tree->left)
    end_process(tree->left);
  if (tree->right)
    end_process(tree->right);
  wait(&status);
}

int		my_loop(t_params *p)
{
  char		*input;
  int		state;
  char		***prio;
  t_node	*tree;

  prio = NULL;
  prio = init_prio();
  while (write(1, "$> ", 3) != -1 && ((input = get_next_line(0))))
    {
      if (check_input(input) == 0)
	continue ;
      else
	{
	  tree = my_parse(input, prio);
	  if ((state = start_exec(tree, p, 1)) >= 0)
	    return (state);
	}
      end_process(tree);
      free_tree(tree);
      free(input);
    }
  return (-1);
}
