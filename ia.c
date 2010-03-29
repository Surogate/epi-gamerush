/*
** header
*/
#include	<SDL/SDL.h>
#include	"define.h"
#include	"boss.h"
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"

void	rand_move(t_boss *boss,t_map *map)
{
  int	dir;

  printf("func rand\n");
  dir = boss->dir;
  if (map->map[boss->pos.y][boss->pos.x + dir] != WALL_CHAR &&
      (map->map[boss->pos.y + 1][boss->pos.x + dir] == LADDER_CHAR ||
       map->map[boss->pos.y + 1][boss->pos.x + dir] == WALL_CHAR))
    boss->pos.x += boss->dir;
  else
    boss->dir *= -1;
}

void	shoot(t_boss *boss, t_player *player)
{
  int	direction;

  printf("func shoot\n");
  direction = player->move - boss->move;
  if (direction > 0)
    boss->dir = 1;
  else
    boss->dir = -1;
  boss->ammo_pos.x = boss->pos.x + boss->dir;
  boss->ammo_pos.y = boss->pos.y;
  boss->ammo_move = PORTEE;
  boss->ammo_dir = boss->dir;
}

void	path_finding(t_player *player, t_boss *boss, t_map *map)
{
  int	dir;

  printf("func pathfinding\n");
  dir = player->move - boss->move;
  if (dir > 0)
    dir = 1;
  else
    dir = -1;
  boss->dir = dir;
  if (map->map[boss->pos.y][boss->pos.x + dir] != WALL_CHAR &&
      (map->map[boss->pos.y + 1][boss->pos.x + dir] == LADDER_CHAR ||
       map->map[boss->pos.y + 1][boss->pos.x + dir] == WALL_CHAR))
    boss->pos.x += boss->dir;
      
}

void	ia(t_player *player, t_boss *boss, t_map *map)
{
  int	test;

  printf("func ia\n");
  if (boss->move)
    {
      if (player->position.y == boss->pos.y)
	{
	  test = player->position.x - boss->pos.x;
	  if (test < 0)
	    test *= -1;
	  if (test <= PORTEE && test > boss->move) 
	    shoot(boss, player);
	  else
	    path_finding(player, boss, map);
	}
      else
	rand_move(boss, map);
      boss->move--;
      if (!boss->move)
	player->move = NB_MOVE;
    }
}
