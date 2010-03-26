/*
** xio.c for ftp in /u/all/muller_b/cu/rendu/c/my_ftp
**
** Made by quentin muller
** Login   <muller_b@epitech.net>
**
** Started on  Wed Mar  3 11:45:11 2010 quentin muller
** Last update Sun Mar 14 18:30:19 2010 quentin muller
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>

#include		"err.h"

int			xwrite(int fd, char *str, int len)
{
  int			written;

  if ((written = write(fd, str, len)) == -1)
    err("write error.", 1);
  return (written);
}

int			xread(int fd, char *str, int len)
{
  int			readed;

  if ((readed = read(fd, str, len)) == -1)
    err("read error.", 1);
  return (readed);
}

void			*xmalloc(int s)
{
  void			*ptr;

  if ((ptr = malloc(s)) == NULL)
    err("Can't perform malloc.", 1);
  return (ptr);
}

void			*xrealloc(void *ptr, int s)
{
  if (ptr == NULL)
    return (NULL);
  if ((ptr = realloc(ptr, s)) == NULL)
    err("Can't perform realloc.", 1);
  return (ptr);
}
