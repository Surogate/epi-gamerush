#include		<errno.h>
#include		<fcntl.h>
#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>

#include		"err.h"

int			get_file_size(int fd)
{
  int			size;

  size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  return (size);
}

int			**get_map(char *path)
{
  int			fd;
  int			size;
  int			**map;

  if ((fd = open(path, O_RDONLY)) == -1)
    err("Can't open file", 1);
  if ((size = get_file_size(fd)) == -1)
    err("Lseek failed", 1);
  



}
