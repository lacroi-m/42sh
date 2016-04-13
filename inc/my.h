/*
** my.h for all in /home/meridjm/Rendu/PSU_2015_minishell2/include/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:58:17 2016 Mehdi Meridja
** Last update Wed Apr 13 09:54:31 2016 Mehdi
*/

#ifndef MY_H_
# define MY_H_

#include "minishell2.h"

/* _ALL_ */
int	my_getnbr(char *str);
int	my_strlen(char *str);
int	my_strlen_tab(char **tab);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_memset(char *str, int c, int n);
char	*my_strcat(char *dest, char *src);
char	*malloc_x(int size);
char	*my_strdup(char *str);
char	*my_strndup(char *str, int n);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	**my_str_to_wordtab(char *str);
char	**strdup_tab(char **env);
char	*my_realloc(char *str, int n);
void	my_putstr(char *str);
void	my_putchar(char c);
void	my_putnbr(int nb);
void	my_put_error(char *str);
void	my_free_tab(char **tab);


/* _MY_PRINTF_ */
#include <stdarg.h>

typedef void (*ptr_func)(va_list ap);

ptr_func        *tab_func();
int		my_printf(char *format, ...);
int             check_flag(char c, va_list ap);
void            my_put_error(char *str);
void            my_put_nbr_base(long nb, char *base);
void            flag_d_i(va_list ap);
void            flag_c(va_list ap);
void            flag_s(va_list ap);
void            flag_modulo(va_list ap);

#endif /* MY_H_ */
