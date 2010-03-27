/*
** display.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 17:49:11 2010 francois1 ancel
** Last update Sat Mar 27 17:49:11 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"define.h"
#include	"t_image.h"
#include	"image_fct.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"

void		display_player(SDL_Surface *screen, t_player *player)
{
  static int	cpt = 0;

  cpt++;
  if (cpt == 6)
    cpt = 0;
  if (cpt < 2)
    {
      if (player->direction == -1)
	blit_img_case(player->player_img1, screen,
		      player->position.x, player->position.y);
      else
	blit_img_case(player->player_img4, screen,
		      player->position.x, player->position.y);
    }
  else if (cpt < 4)
    {
      if (player->direction == -1)
	blit_img_case(player->player_img2, screen,
		      player->position.x, player->position.y);
      else
	blit_img_case(player->player_img5, screen,
		      player->position.x, player->position.y);
    }
  else
    {
      if (player->direction == -1)
	blit_img_case(player->player_img3, screen,
		      player->position.x, player->position.y);
      else
	blit_img_case(player->player_img6, screen,
		      player->position.x, player->position.y);
    }
}

void		display_npcs(SDL_Surface *screen, t_npc *npc)
{
  while (npc != 0)
    {
      npc->frame++;
      if (npc->frame == 6)
	npc->frame = 0;
      if (npc->frame < 2)
	{
	  if (npc->vx == 1)
	    blit_img_case(npc->img1, screen, npc->x, npc->y);
	  else
	    blit_img_case(npc->img4, screen, npc->x, npc->y);
	}
      else if (npc->frame < 4)
	{
	  if (npc->vx == 1)
	    blit_img_case(npc->img2, screen, npc->x, npc->y);
	  else
	    blit_img_case(npc->img5, screen, npc->x, npc->y);
	}
      else
	{
	  if (npc->vx == 1)
	    blit_img_case(npc->img3, screen, npc->x, npc->y);
	  else
	    blit_img_case(npc->img6, screen, npc->x, npc->y);
	}
      npc = npc->next;
    }
}

void		display_map(SDL_Surface *screen, t_map *map, t_image *img)
{
  int width;
  int height;

  height = 0;
  while (height < map->height)
    {
      width = 0;
      while (width < map->width)
	{
	  if (map->map[height][width] == 'w')
	    blit_img_case(img->wall, screen, width, height);
	  else if (map->map[height][width] == 's')
	    blit_img_case(img->ladder, screen, width, height);
	  else if (map->map[height][width] == '.')
	    blit_img_case(img->white, screen, width, height);
	  else if (map->map[height][width] == 'i')
	    blit_img_case(img->enter, screen, width, height);
	  else if (map->map[height][width] == 'o')
	    blit_img_case(img->exit, screen, width, height);
	  else if (map->map[height][width] == 'm')
	    blit_img_case(img->monster1, screen, width, height);
	  else if (map->map[height][width] == 'k')
	    blit_img_case(img->key, screen, width, height);
	  width++;
	}
      height++;
    }
}

test		*init_da_tab()
{
  test		*res;

  res = malloc(7 * sizeof(*res));
  if (res)
    {
      res[0].obj = '.';
      res[0].img = img_load(WHIT_DIR);
      res[1].obj = 's';
      res[1].img = img_load(WALL_DIR);
      res[2].obj = 'w';
      res[2].img = img_load(LAD_DIR);
      res[3].obj = 'm';
      res[3].img = img_load(MON_DIR1);
      res[4].obj = 'o';
      res[4].img = img_load(EXIT_DIR);
      res[5].obj = 'i';
      res[5].img = img_load(ENT_DIR);
      res[6].obj = 'k';
      res[6].img = img_load(KEY_DIR);
    }
  return (res);
}
