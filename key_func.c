/*
**
*/
#include	<SDL/SDL.h>
#include	"define.h"
#include	"env.h"
#include	"map.h"

int		press_up(t_player *player, t_map *map)
{
  if (player->position.y > 0)
    {
      if (map->map[player->position.y - 2][player->position.x] != 'w' &&
	  map->map[player->position.y - 1][player->position.x] != 'w' &&
	  map->map[player->position.y + 1][player->position.x] == 'w')
	{
	  player->position.y -= 2;
	}
      return (1);
    }
  else
    return (2);
}

int		press_down(t_player *player, t_map *map)
{
  if (map->map[player->position.y + 1][player->position.x] != 'w')
    {
      player->position.y += 1;
      return (1);
    }
  else
    return (2);
}

int		press_left(t_player *player, t_map *map)
{
  if (map->map[player->position.y][player->position.x - 1] != 'w')
    {
      player->position.x -= 1;
      return (1);
    }
  else
    return (2);
}

int		press_right(t_player *player, t_map *map)
{
  if (map->map[player->position.y][player->position.x + 1] != 'w')
    {
      player->position.x += 1;
      return (1);
    }
  else
    return (2);
}
