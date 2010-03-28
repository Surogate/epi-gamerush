/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:16:19 2010 francois1 ancel
** Last update Fri Mar 26 22:16:19 2010 francois1 ancel
*/

#include		<SDL/SDL.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"t_image.h"
#include		"map.h"
#include		"npc.h"
#include		"xio.h"

void			add_npc(t_npc **list, int x, int y, t_image *img)
{
  static int		nb = 0;
  t_npc			*new;

  nb++;
  if (nb == 3)
    nb = 0;
  new = xmalloc(sizeof(*new));
  new->x = x;
  new->y = y;
  new->move = 0;
  new->vx = -1;
  new->frame = nb;
  new->img1 = img->monster1;
  new->img2 = img->monster2;
  new->img3 = img->monster3;
  new->img4 = img->monster4;
  new->img5 = img->monster5;
  new->img6 = img->monster6;
  new->next = *list;
  *list = new;
}

void			disp_monsters(t_npc *list)
{
  printf("New monster : %i %i\n", list->x, list->y);
  if (list->next != NULL)
    disp_monsters(list->next);
}

t_npc			*get_npc_monsters(t_map *map, t_image *img)
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
