/*
** display.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 17:49:11 2010 francois1 ancel
** Last update Sun Mar 28 21:17:33 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"define.h"
#include	"t_image.h"
#include	"image_fct.h"
#include	"boss.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"xio.h"

void		aff_da_banana(t_player *player, SDL_Surface *screen)
{
  unsigned int	co;

  if (player->banane.move)
    {
      co = SDL_MapRGB(screen->format, 255, 255, 255);
      SDL_SetColorKey(player->banane.img, SDL_RLEACCEL | SDL_SRCCOLORKEY, co);
      player->banane.move--;
      blit_img_case(player->banane.img, screen,
		    player->banane.pos.x, player->banane.pos.y);
      player->banane.pos.x += player->banane.dir;
    }
  else
    {
      player->banane.pos.x = 0;
      player->banane.pos.y = 0;
    }
}

void		display_player(SDL_Surface *screen, t_player *player)
{
  static int	cpt = 0;
  int		x;
  int		y;

  x = player->position.x;
  y = player->position.y;
  cpt++;
  if (cpt == 6)
    cpt = 0;
  if (cpt < 2)
    if (player->direction == -1)
      blit_img_case(player->player_img1, screen, x, y);
    else
      blit_img_case(player->player_img4, screen, x, y);
  else if (cpt < 4)
    if (player->direction == -1)
      blit_img_case(player->player_img2, screen, x, y);
    else
      blit_img_case(player->player_img5, screen, x, y);
  else
    if (player->direction == -1)
      blit_img_case(player->player_img3, screen, x, y);
    else
      blit_img_case(player->player_img6, screen, x, y);
  aff_da_banana(player, screen);
}

void		display_npcs(SDL_Surface *screen, t_npc *npc)
{
  while (npc != 0)
    {
      if (npc->life)
	{
	  npc->frame++;
	  if (npc->frame == 6)
	    npc->frame = 0;
	  if (npc->frame < 2)
	    if (npc->vx == 1)
	      blit_img_case(npc->img1, screen, npc->x, npc->y);
	    else
	      blit_img_case(npc->img4, screen, npc->x, npc->y);
	  else if (npc->frame < 4)
	    if (npc->vx == 1)
	      blit_img_case(npc->img2, screen, npc->x, npc->y);
	    else
	      blit_img_case(npc->img5, screen, npc->x, npc->y);
	  else
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
  int		i;
  int		width;
  int		height;

  height = 0;
  while (height < map->height)
    {
      width = 0;
      while (width < map->width)
	{
	  i = 0;
	  while (img->tab[i].obj)
	    {
	      if (map->map[height][width] == img->tab[i].obj)
		blit_img_case(img->tab[i].img, screen, width, height);
	      i++;
	    }
	  width++;
	}
      height++;
    }
}

t_imgtab		*init_da_tab()
{
  static t_imgtab	res[11];

  res[0].obj = EMPTY_CHAR;
  res[0].img = img_load(WHIT_DIR);
  res[1].obj = WALL_CHAR;
  res[1].img = img_load(WALL_DIR);
  res[2].obj = LADDER_CHAR;
  res[2].img = img_load(LAD_DIR);
  res[3].obj = MONSTER_CHAR;
  res[3].img = img_load(MON_DIR1);
  res[4].obj = EXIT_CHAR;
  res[4].img = img_load(EXIT_DIR);
  res[5].obj = ENTER_CHAR;
  res[5].img = img_load(ENT_DIR);
  res[6].obj = KEY_CHAR;
  res[6].img = img_load(KEY_DIR);
  res[7].obj = BLOOD_CHAR;
  res[7].img = img_load(BLOOD_DIR);
  res[8].obj = GUN_CHAR;
  res[8].img = img_load(GUN_DIR);
  res[9].obj = LIFE_CHAR;
  res[9].img = img_load(LIFE_DIR);
  res[10].obj = '\0';
  res[10].img = NULL;
  return (res);
}
