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
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"xio.h"

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
}

void		display_npcs(SDL_Surface *screen, t_npc *npc)
{
  while (npc != 0)
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
  static t_imgtab	res[10];

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

void		display_life(SDL_Surface *screen, t_player *player)
{
  TTF_Font	*font;
  SDL_Surface	*text;
  char		str[50];
  SDL_Rect	pos;
  SDL_Color	color = {0, 0, 0, 0};

  if (TTF_Init() < 0)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      return ;
    }
  font = TTF_OpenFont(FONT_DIR, MFONT_SIZE);
  if (!font)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      return ;
    }
  sprintf(str, "%i life remaining", player->life);
  text = TTF_RenderText_Blended(font, str, color);
  pos.x = 16;
  pos.y = 16;
  SDL_BlitSurface(text, NULL, screen, &pos);
  sprintf(str, "%d ammo", player->item.weapon);
  text = TTF_RenderText_Blended(font, str, color);
  pos.y = 32;
  SDL_BlitSurface(text, NULL, screen, &pos);
  sprintf(str, "%d move", player->move);
  text = TTF_RenderText_Blended(font, str, color);
  pos.y = 48;
  SDL_BlitSurface(text, NULL, screen, &pos);
  sprintf(str, "%d key", player->item.key);
  text = TTF_RenderText_Blended(font, str, color);
  pos.y = 64;
  SDL_BlitSurface(text, NULL, screen, &pos);
  TTF_CloseFont(font);
  TTF_Quit();
}
