/*
**header
*/

#include "env.h"

int			monster_time(t_player *player, t_map *map, t_npc *npc)
{
  t_npc			*begin;

  begin = npc;
  printf("[%d]\n", npc->move);
  if (npc->move)
    {
      while (npc)
	{
	  printf("Les monstres joues\n");
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
    {
      printf("-->reinit player<--\n");
      player->move = 5;
    }
  return (1);
}
