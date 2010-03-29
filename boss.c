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
      boss->dir = 1;
      boss->move = 0;
      boss->ammo_move = 0;
      boss->ammo = img_load(BG_DIR);
      boss->img1 = img_load(BOSS_DIR1);
      boss->img1 = img_load(BOSS_DIR2);
    }
}
