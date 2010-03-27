/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:16:19 2010 francois1 ancel
** Last update Fri Mar 26 22:16:19 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"err.h"
#include	"exec_fct.h"
#include	"map.h"
#include	"define.h"
#include	"windows.h"
#include	"xio.h"
#include	"t_image.h"
#include	"image_fct.h"

void			act_life()
{
  
}

void			disp_life(SDL_Surface *ecran, int px, 
				  int py, t_player *player)
{
  SDL_Surface		*lvl = NULL;
  SDL_Rect		pos_lvl;
  int			i;

  i = 0;
  while ((player->position.x != px) && (player->position.x != py))
    {
      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 153, 153, 153));
      lvl = img_load("./image/L1.bmp");
      pos_lvl.x = x; 
      pos_lvl.y = y;
      SDL_BlitSurface(lvl, NULL, ecran, &pos_lvl);
      SDL_Flip(ecran);
      SDL_Delay(100);
      SDL_FreeSurface(lvl);
      lvl = img_load("./image/L2.bmp");
      pos_lvl.x = x; 
      pos_lvl.y = y;
      SDL_BlitSurface(lvl, NULL, ecran, &pos_lvl);
      SDL_Flip(ecran);
      SDL_Delay(100);
      SDL_FreeSurface(lvl);
      lvl = img_load("./image/L3.bmp");
      pos_lvl.x = x; 
      pos_lvl.y = y;
      SDL_BlitSurface(lvl, NULL, ecran, &pos_lvl);
      SDL_Flip(ecran);
      SDL_Delay(100);
      SDL_FreeSurface(lvl);
      lvl = img_load("./image/L1.bmp");
      pos_lvl.x = x; 
      pos_lvl.y = y;
      SDL_BlitSurface(lvl, NULL, ecran, &pos_lvl);
      SDL_Flip(ecran);
      SDL_Delay(100);
      i++;
    }
  SDL_FreeSurface(lvl);
}
