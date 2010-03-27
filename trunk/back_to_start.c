/*
** header
*/
#include	"map.h"
#include	"env.h"

void		are_you_dieing(t_npc *npc, t_player *player, t_map *map)
{
  while (npc)
    {
      if (npc->x == player->position.x && npc->y == player->position.y)
	you_loose(player, map);
      npc = npc->next;
    }
}

void		you_loose(t_player *player, t_map *map)
{
  int		pos[2];

  player->life--;
  pos[0] = 0;
  pos[1] = 0;
  search_pos(map, pos);
  player->position.x = pos[0];
  player->position.y = pos[1];
  if (!player->life)
    {
      printf("\033[31mgame over\033[00m\n");
      exit(0);
    }
}
