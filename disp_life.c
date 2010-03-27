/*
**
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


/*gcc -lSDLmain -lSDL -o test disp_life.c image_fct.c*/

void			act_life()
{
  
}

void			disp_life(SDL_Surface *ecran, int px, int py, t_player *player)
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
