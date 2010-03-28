/*
** init_player.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 01:06:35 2010 francois1 ancel
** Last update Sat Mar 27 01:06:35 2010 francois1 ancel
*/

#include	<SDL/SDL.h>
#include	"t_image.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"init_player.h"
#include	"define.h"

void		search_pos(t_map *map, int *res, char to_find)
{
  int		width;
  int		height;

  height = 0;
  while (height < map->height)
    {
      width = 0;
      while (width < map->width)
	{
	  if (map->map[height][width] == to_find)
	    {
	      res[0] = width;
	      res[1] = height;
	    }
	  width++;
	}
      height++;
    }
}

void		init(t_player *player, t_map *map, t_image *img)
{
  int		pos[2];

  pos[0] = 0;
  pos[1] = 0;
  search_pos(map, pos, ENTER_CHAR);
  player->position.x = pos[0];
  player->position.y = pos[1];
  player->move = NB_MOVE;
  player->life = NB_LIFE;
  player->wait = 0;
  player->item.weapon = 0;
  player->item.key = 0;
  player->direction = -1;
  player->img_lenght = 10;
  player->img_height = 10;
  player->banane.move = 0;
  player->player_img1 = img->hero1;
  player->player_img2 = img->hero2;
  player->player_img3 = img->hero3;
  player->player_img4 = img->hero4;
  player->player_img5 = img->hero5;
  player->player_img6 = img->hero6;
}
