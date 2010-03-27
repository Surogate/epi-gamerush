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

SDL_Surface	*ecran = NULL;

void pausex()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void			disp_life(SDL_Surface *ecran, int x, int y)
{
  SDL_Surface		*lvl = NULL;
  SDL_Rect		pos_lvl;
  int			i;

  i = 0;
  while (i < 10)
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

int main(int argc, char *argv[])
{
 
  SDL_Init(SDL_INIT_VIDEO);
  /*Ecran*/
  ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Epikong", NULL);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

  disp_life(ecran, 312, 232);

  SDL_Flip(ecran);

  pausex();

  SDL_Quit();
  
  return EXIT_SUCCESS;
}
