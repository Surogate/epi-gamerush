/*
** xio.c for epikong
**
** Made by quentin muller
** Login   <muller_b@epitech.net>
**
** Started on  Wed Mar  3 11:45:11 2010 quentin muller
** Last update Sun Mar 14 18:30:19 2010 quentin muller
*/

#ifndef		__XIO_H__
# define	__XIO_H__

int		xwrite(int fd, char *str, int len);
int		xread(int fd, char *str, int len);
void		*xmalloc(int s);
void		*xrealloc(void *ptr, int s);
char		*get_file_content(char *path);

#endif		/* __XIO_H__ */
