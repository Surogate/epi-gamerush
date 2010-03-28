/*
** back_to_start.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 16:50:54 2010 francois1 ancel
** Last update Sat Mar 27 16:50:54 2010 francois1 ancel
*/

#include	<SDL/SDL.h>
#include	<math.h>
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"
#include	<stdio.h>

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
  if (*save > 4)
    flag = you_loose(player, map);
  player->wait = 0;
  *save = 0;
  return (flag);
}
