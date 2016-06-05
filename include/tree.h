/*
** tree.h for tree in /home/juniqu_v/rendu/tree
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Fri Jun  3 13:51:41 2016 virgile junique
** Last update Sun Jun  5 15:29:21 2016 virgile junique
*/

#ifndef _TREE_H_
# define _TREE_H_

# include "42sh.h"

# define PIPE "|"
# define COLON ";"
# define SEP "|| &&"
# define REDI ">> < >"
# define REDI2 "<<"

typedef struct	s_node
{
  char		*data;
  int		fd_in;
  int		fd_out;
  struct s_node	*right;
  struct s_node	*left;
}		t_node;

typedef struct	s_rev
{
  char		*op;
  char		*op_stock;
  int		i;
  int		j;
  int		pos;
  int		pos_stock;
}		t_rev;

int		sep_dubredirectl(t_node *tree, t_params *p, int last);
int		sep_redirectr(t_node *tree, t_params *p, int last);
int		sep_dubredirectr(t_node *tree, t_params *p, int last);
int		sep_redirectl(t_node *tree, t_params *p, int last);
int		sep_pipe(t_node *tree, t_params *p, int last);
int		my_separator(t_node *tree, t_params *p, int pos, int last);
int		its_separator(char *str);
int		my_exec(t_node *tree, t_params *p, int last);
int		execute(t_node *tree, char **cmd, t_params *p);
int		my_loop(t_params *p);
int		start_exec(t_node *tree, t_params *p, int last);
char		*my_access(char **cmd, t_params *p);
char		**sep_in_tab(char *cmd, char ***prio);
void		set_state(t_params *p, int state);
void		end_process(t_node *tree);
void		free_tree(t_node *tree);
t_node		*my_parse(char *prompt, char ***prio);
t_node		*new_node(t_node *left, char *data, t_node *right);

#endif /* !TREE_H_ */
