/*
** image_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:14:43 2010 francois1 ancel
** Last update Fri Mar 26 22:14:43 2010 francois1 ancel
*/

#include		<SDL/SDL.h>
#include		"t_image.h"
#include		"map.h"
#include		"npc.h"
#include		"env.h"

int			monster_time(t_map *map, t_npc *npc)
{
  t_npc			*begin;

  begin = npc;
  while (npc)
    {
      if ((map->map[npc->y][npc->x + npc->vx] != WALL_CHAR ||
	   map->map[npc->y][npc->x + npc->vx] == LADDER_CHAR) &&
	  (map->map[npc->y + 1][npc->x + npc->vx] == WALL_CHAR ||
	   map->map[npc->y + 1][npc->x + npc->vx] == LADDER_CHAR) &&
	  map->map[npc->y][npc->x + npc->vx] != ENTER_CHAR)
	{
	  npc->x += npc->vx;
	  SDL_Delay(30);
	}
      else
	npc->vx *= -1;
      npc = npc->next;
    }
  return (1);
}
