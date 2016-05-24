/*
** builtins.h for builtins in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 15:55:18 2016 virgile junique
** Last update Tue May 24 13:36:48 2016 Lemeh
*/

#ifndef _BUILTINS_H_
# define _BUILTINS_H_

int	my_env(char **tab, char *line, t_params *p);
int	my_setenv(char **tab, char *line, t_params *p);
int	my_echo(char **tab, char *str, t_params *p);
int	my_unsetenv(char **tab, char *line, t_params *p);
int	my_found_in_env(char *str, t_env *env);
int	my_builtins(char **tab, char *str, t_params *p, int pos);
int	its_builtins(char *str);
int	my_exit(char **tab, char *str, t_params *p);

#endif /* !BUILTINS_H_ */
