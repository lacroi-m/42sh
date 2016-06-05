/*
** builtins.h for builtins in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 15:55:18 2016 virgile junique
** Last update Sun Jun  5 11:49:17 2016 virgile junique
*/

#ifndef _BUILTINS_H_
# define _BUILTINS_H_

int	my_env(char **cmd, t_params *p);
int	my_setenv(char **cmd, t_params *p);
int	my_echo(char **cmd, t_params *p);
int	my_unsetenv(char **cmd, t_params *p);
int	my_found_in_env(char *str, t_env *env);
int	my_builtins(char **built, t_params *p, int pos);
int	its_builtins(t_node *tree, t_params *p);
int	my_exit(char **cmd, t_params *p);
int	my_old(t_params *p, t_env *env);
int	go_home(t_params *p, t_env *env);
int	go_dir(char *str, t_params *p);

#endif /* !BUILTINS_H_ */
