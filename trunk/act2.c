
#include	<SDL/SDL.h>
#include	<math.h>
#include	<stdio.h>
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"
#include	"define.h"

int		something_on_da_way(t_player *player, t_map *map, int fall_len)
{
  int		height;

  height = 0;
  while (height < fall_len)
    {
      if (map->map[player->position.y + height + 1][player->position.x]
	  == 'w' ||
	  map->map[player->position.y + height + 1][player->position.x] == 's')
	{
	  return (height);
	}
      height++;
    }
  return (height);
}

int		falling(t_player *player, t_map *map, int fall_len)
{
  int		temp;

  temp = something_on_da_way(player, map, (int)pow(2, fall_len));
  player->position.y += temp;
  return (temp);
}

int		life_verif(t_player *player, t_map *map, int *save)
{
  int		flag;

  flag = 0;
  if (*save > DEAD_FALL)
    flag = you_loose(player, map);
  player->wait = 0;
  *save = 0;
  return (flag);
}
