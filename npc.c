#include		<SDL/SDL.h>
#include		<stdio.h>
#include		<unistd.h>

#include		"map.h"
#include		"npc.h"
#include		"xio.h"

void			add_npc(t_npc **list, int x, int y, SDL_Surface *img)
{
  t_npc			*new;

  new = xmalloc(sizeof(*new));
  new->x = x;
  new->y = y;
  new->vx = 1;
  new->img = img;
  new->next = *list;
  *list = new;
}

void			disp_monsters(t_npc *list)
{
  printf("New monster : %i %i\n", list->x, list->y);
  if (list->next != NULL)
    disp_monsters(list->next);
}

t_npc			*get_npc_monsters(t_map *map, SDL_Surface *img)
{
  t_npc			*npc_list;
  int			x;
  int			y;

  y = 0;
  npc_list = 0;
  while (y < map->height)
    {
      x = 0;
      while (x < map->width)
	{
	  if (map->map[y][x] == MONSTER_CHAR)
	    {
	      add_npc(&npc_list, x, y, img);
	      map->map[y][x] = EMPTY_CHAR;
	    }
	  x++;
	}
      y++;
    }
  return (npc_list);
}