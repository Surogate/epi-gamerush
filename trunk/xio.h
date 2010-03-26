#ifndef		__XIO_H__
# define	__XIO_H__

int		xwrite(int fd, char *str, int len);
int		xread(int fd, char *str, int len);
void		*xmalloc(int s);
void		*xrealloc(void *ptr, int s);
char		*get_file_content(char *path);

#endif		/* __XIO_H__ */
