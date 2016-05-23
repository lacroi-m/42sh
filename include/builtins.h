/*
** builtins.h for builtins in /home/juniqu_v/rendu/PSU_2015_42sh/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 15:55:18 2016 virgile junique
** Last update Mon May 23 16:10:06 2016 virgile junique
*/

#ifndef _BUILTINS_H_
# define _BUILTINS_H_

void	my_fill_builtins_name(char tab[6]);
void	my_env(char *line, t_params *p, int value);
void	my_setenv(char *line, t_params *p, int value);
void	my_echo(char *str, t_params *p, int value);
int	my_unsetenv(char *line, t_params *p, int value);
int	my_found_in_env(char *str, t_env *env);
int	my_builtins(char *str, t_params *p, int pos);
int	its_builtins(char *str);
int	my_exit(char *str, t_params *p, int value);

#endif /* !BUILTINS_H_ */
