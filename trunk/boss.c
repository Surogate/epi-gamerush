/*
**
*/
#include <SDL/SDL.h>
#include "define.h"
#include "boss.h"
#include "map.h"
#include "t_image.h"
#include "npc.h"
#include "env.h"
#include "init_player.h"
#include "image_fct.h"

void	init_boss(t_boss *boss, t_map *map)
{
  int		pos[2];

  pos[0] = 0;
  pos[1] = 0;
  search_pos(map, pos, BOSS_CHAR);
  boss->pos.x = pos[0];
  boss->pos.y = pos[1];
  if (pos[1] && pos[0])
    {
      printf("init boss\n");
      boss->dir = 1;
      printf("pouet1\n");
      boss->move = 0;
      printf("pouet2\n");
      boss->ammo_move = 0;
      printf("pouet3\n");
      boss->ammo = img_load(BG_DIR);
      printf("pouet4\n");
      boss->img1 = img_load(BOSS_DIR1);
      printf("pouet5\n");
      boss->img1 = img_load(BOSS_DIR2);
      printf("fin init\n");
    }
  else
    {
      boss->img1 = 0;
      printf("pas de boss\n");
    }
}
