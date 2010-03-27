/*
** map.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:16:19 2010 francois1 ancel
** Last update Fri Mar 26 22:16:19 2010 francois1 ancel
*/

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
  cur_width = 1;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  (*height)++;
	  if (cur_width > *width && *width == 0)
	    *width = cur_width;
	  else if (cur_width != *width)
	    err_inside("Bad dimensions for map.", 1);
	  cur_width = 0;
	}
      cur_width++;
      i++;
    }
  cur_width = write(1, &buffer, 0);
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

t_map			*check_map(t_map *map)
{
  int			x;
  int			y;

  y = 0;
  while (y < map->height)
    {
      x = 0;
      while (x < map->width)
	{
	  if (map->map[y][x] != WALL_CHAR &&
	      (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1))
	    err_inside("Invalid map, holes exist on the edges.", 1);
	  x++;
	}
      y++;
    }
  return (map);
}
