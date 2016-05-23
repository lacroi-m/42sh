/*
** get_next_line.h for get_next_line in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 11:50:39 2016 virgile junique
** Last update Mon May 23 20:58:02 2016 virgile junique
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1024)

# endif /* READ_SIZE */

char	*my_reader(const int fd, char **save);
char	*get_next_line(const int fd);

#endif /* GET_NEXT_LINE_H_ */
