/*
** image_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:14:43 2010 francois1 ancel
** Last update Fri Mar 26 22:14:43 2010 francois1 ancel
*/

#include	<SDL/SDL.h>
#include	"t_image.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"init_player.h"
#include	"back_to_start.h"
#include	"define.h"

int		are_you_dying(t_npc *npc, t_player *player, t_map *map)
{
  while (npc)
    {
      if (npc->x == player->position.x && npc->y == player->position.y &&
	  npc->life)
	{
	  return (you_loose(player, map));
	}
      npc = npc->next;
    }
  return (1);
}

int		you_loose(t_player *player, t_map *map)
{
  int		pos[2];

  player->life--;
  printf("\033[31m%d life remaining!\033[00m\n", player->life);
  pos[0] = 0;
  pos[1] = 0;
  search_pos(map, pos, ENTER_CHAR);
  if (map->map[player->position.y][player->position.x] == EMPTY_CHAR)
    map->map[player->position.y][player->position.x] = BLOOD_CHAR;
  player->position.x = pos[0];
  player->position.y = pos[1];
  player->direction = -1;
  player->move = NB_MOVE;
  if (!player->life)
    {
      printf("\033[31mgame over\033[00m\n");
      return (-1);
    }
  return (1);
}
