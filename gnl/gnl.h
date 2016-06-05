/*
** gnl.h for  in /home/oudin_c/rendu/gnl
**
** Made by coudin
** Login   <oudin_c@epitech.net>
**
** Started on  Tue May 31 11:42:59 2016 coudin
** Last update Wed Jun  1 12:34:58 2016 coudin
*/

#ifndef		GNL_H_
# define	GNL_H_

/*
**		!GNL PARAMS!
**
** FD:		NORMAL FILE DESCRIPTOR
** MODE:	0: NORMAL GNL
**		-1: RETURN ALL VALUE FROM START
**		-2: FREE MEMORY
*/

/*
**		DPRINTF
*/
#include <stdio.h>

# include	<unistd.h>
# include	<stdlib.h>

/*
**		MACROS
*/

# define        BUFF_SIZE (5)

/*
**		BUFFER'S STRUCTURES
*/

typedef struct	s_buf
{
  char		buff[BUFF_SIZE];
  int		c;
  struct s_buf	*next;
}		t_buf;

typedef struct	s_l
{
  t_buf		*start;
  t_buf		*end;
  t_buf		*curr;
  int		pos;
  int		n_line;
}		t_l;

/*
**		GNL_C_
*/

char            *gnl(int fd);

/*
**		GNL0_C_
*/

void            init(t_l *l);
void            init_buff(t_buf *buff);
void            fil_buff(t_l *l, int fd);
int             find_nl(t_buf *buff, int pos);
void		free_buff(t_l *l);

#endif		/* !GNL_H_ */
