#include		<errno.h>
#include		<fcntl.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>

#include		"err.h"
#include		"map.h"
#include		"xio.h"

void			get_map_dim(char *buffer, int *width, int *height)
{
  int			cur_width;
  int			i;

  i = 0;
  *height = 0;
  *width = 0;
  cur_width = -1;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  (*height)++;
	  if (cur_width > *width)
	    *width = cur_width;
	  cur_width = 0;
	}
      cur_width++;
      i++;
    }
  write(1, &buffer, 0);
  if (buffer[i - 1] != '\n')
    (*height)++;
}

t_map			*get_map(char *path)
{
  t_map			*map;
  char			*buffer;
  int			i;
  int			j;

  map = xmalloc(sizeof(*map));
  buffer = get_file_content(path);
  get_map_dim(buffer, &map->width, &map->height);
  map->map = xmalloc((map->height + 1) * sizeof(*map->map));
  i = 0;
  while (i < map->height)
    {
      map->map[i] = xmalloc((map->width) * sizeof(**map->map));
      j = 0;
      while (j < map->width)
	{
	  map->map[i][j] = buffer[j + i * map->width];
	  j++;
	}
      i++;
    }
  map->width--;
  free(buffer);
  return (map);
}
