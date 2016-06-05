/*
** echo.c for echo in /home/juniqu_v/rendu/PSU_2015_42sh/srcs/builtins
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sun Jun  5 11:54:09 2016 virgile junique
** Last update Sun Jun  5 21:38:33 2016 virgile junique
*/

#include "42sh.h"

static int     print_var_env(char *str, int nul, int b)
{
  int		i;

  i = -1;
  while (str[++i] != '=');
  if (nul == 0)
    {
      my_putstr(&str[i], 1, 0);
      my_putchar(' ', 1);
    }
  else
    my_putstr(&str[i], 1, 0);
  if (b == 0)
    my_putchar('\n', 1);
  return (0);
}

static int     print_ret_env(char *str, int nul, int b)
{
  int		i;

  i = 2;
  if (nul == 0)
    {
      my_putstr(&str[i], 1, 0);
      my_putchar(' ', 1);
    }
  else
    my_putstr(&str[i], 1, 0);
  if (b == 0)
    my_putchar('\n', 1);
  return (0);
}

static void    print_str(char *str, int nul, int b)
{
  (void)b;
  if (nul == 0)
    {
      my_putstr(str, 1, 0);
      my_putchar(' ', 1);
    }
  else
    {
      my_putstr(str, 1, 0);
      my_putchar('\n', 1);
    }
  return ;
}

static int     check_env(char *str, t_env *env, int nul, int b)
{
  t_env		*tmp;

  if (str[1] == '?')
    {
      tmp = env->next;
      while (tmp != env)
	{
      if (my_strncmp(tmp->line, "?=", 2) == 0)
	return (print_ret_env(tmp->line, nul, b));
      tmp = tmp->next;
	}
    }
 else
   {
      while (tmp != env)
        {
          if (my_strncmp(tmp->line, &str[1], my_strlen(str)) == 0)
            return (print_var_env(tmp->line, nul, b));
          tmp = tmp->next;
        }
   }
  return (my_putstr("Not found in environement, sorry.\n", 2, 0));
}

int		my_echo(char **tab, t_params *p)
{
  int		i;
  int		nul;
  int		b;

  nul = 0;
  b = 0;
  i = 0;
  if (!tab[1])
    my_putstr("\n", 1, -1);
  else
    {
      if ((my_strncmp(tab[1], "-n", 2)) == 0)
        b = 1;
      while (tab[++i] != NULL)
        {
          if (tab[i + 1] == NULL)
            nul = 1;
          if (tab[i][0] == '$' && tab[i][1] == '?')
            check_env(tab[i], p->env, nul, b);
          else
            print_str(tab[i], nul, b);
        }
    }
  return (0);
}
