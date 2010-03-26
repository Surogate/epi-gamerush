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

void			test_map(char *path)
{
  t_map			*map;
  int			x;
  int			y;
  char			c;

  map = get_map("./map.map");
  y = 0;
  while (y < map->height)
    {
      x = 0;
      while (x < map->width)
	{
	  xwrite(1, &map->map[y][x], 1);
	  x++;
	}
      c = '\n';
      xwrite(1, &c, 1);
      y++;
    }
}
