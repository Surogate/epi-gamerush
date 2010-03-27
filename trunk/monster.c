/*
**header
*/

#include		"env.h"

int			monster_time(t_player *player, t_map *map, t_npc *npc)
{
  t_npc			*begin;

  begin = npc;
  if (npc->move)
    {
      while (npc)
	{
	  if (map->map[npc->y][npc->x + npc->vx] != 'w' &&
	      (map->map[npc->y + 1][npc->x + npc->vx] == 'w' ||
	       map->map[npc->y + 1][npc->x + npc->vx] == 's'))
	    npc->x += npc->vx;
	  else
	    npc->vx *= -1;
	  npc->move--;
	  npc = npc->next;
	}
    }
  if (!begin->move)
    player->move = 5;
  return (1);
}
