/*
** get_next_line.h for all in /home/meridjm/Rendu/PSU_2015_minishell2/include/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:59:13 2016 Mehdi Meridja
** Last update Tue Apr 12 11:04:45 2016 Mehdi Meridja
*/

# ifndef READ_SIZE
# define READ_SIZE (344)
# endif /* !READ_SIZE  */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char	get_to_ch(int fd);
char	*get_line(int fd);

typedef struct	s_get
{
  char		ch;
  char		*line;
  int		size;
}		t_get;

typedef struct	s_line
{
  char		buffer[READ_SIZE];
  char		*buff;
  int		size;
  char		ch;
}		t_line;

#endif /* GET_NEXT_LINE_H_ */
