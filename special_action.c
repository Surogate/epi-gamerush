/*
**
*/

#include	<SDL/SDL.h>
#include	"define.h"
#include	"t_image.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"init_player.h"

int		pass(t_player *player)
{
  player->move = 0;
  return (1);
}

int		fire(t_player *player)
{
  if (player->item.weapon)
    {
      printf("FIRE!!!\n");
      player->item.weapon--;
      player->banane.move = PORTEE;
      player->banane.dir = player->direction;
      player->banane.pos.x = player->position.x + player->direction;
      player->banane.pos.y = player->position.y;
      pass(player);
    }
  else
    printf("NO MORE AMMO!!!\n");
  return (1);
}

int		take_it(t_player *player, t_map *map)
{
  if (map->map[player->position.y][player->position.x] == EXIT_CHAR &&
      player->item.key)
    {
      printf("\033[36mLevel complete!\033[00m\n");
      return (0);
    }
  if (map->map[player->position.y][player->position.x] == LIFE_CHAR)
    {
      printf("You get an extra life.\n");
      map->map[player->position.y][player->position.x] = EMPTY_CHAR;
      player->life += 1;
    }
  if (map->map[player->position.y][player->position.x] == KEY_CHAR)
    {
      printf("You got a key.\n");
      map->map[player->position.y][player->position.x] = EMPTY_CHAR;
      player->item.key = 1;
    }
  if (map->map[player->position.y][player->position.x] == GUN_CHAR)
     {
       player->item.weapon++;
       map->map[player->position.y][player->position.x] = EMPTY_CHAR;
     }
  return (1);
}
