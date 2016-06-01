/*
** parser.h for 42sh in /home/meridj/Rendu/PSU_2015_42sh/include/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue May 31 14:34:51 2016 Mehdi Meridja
** Last update Tue May 31 17:02:55 2016 Mehdi Meridja
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "42sh.h"

typedef struct	s_parser
{
  char		**cmd;
}		t_parser;

void	multi_exec(t_params *p);

#endif /* !PARSER_H_ */
