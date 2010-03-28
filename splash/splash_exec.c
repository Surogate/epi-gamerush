/*
** splash_exec for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 28 06:51:18 2010 francois1 ancel
** Last update Sun Mar 28 06:51:18 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"define.h"
#include	"err.h"

void		splash_write(SDL_Surface *screen, char *str, SDL_Rect *pos)
{
  TTF_Font	*font;
  SDL_Color	color = {0, 0, 0, 0};
  SDL_Surface	*text;

  if (TTF_Init() < 0)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      return ;
    }
  font = TTF_OpenFont("./font/SERIM___.ttf", 16);
  if (!font)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      return ;
    }
  text = TTF_RenderText_Solid(font, str, color);
  SDL_BlitSurface(text, NULL, screen, pos);
  SDL_Flip(screen);
  TTF_CloseFont(font);
  TTF_Quit();
}

void		splash_exec(SDL_Surface *screen, char *str, SDL_Color *color)
{
  SDL_Surface	*splash;
  SDL_Rect	pos;
  SDL_Event	event;

  splash = SDL_CreateRGBSurface(SDL_HWSURFACE, screen->w, 32, 
				WIN_COLOR, 0, 0, 0, 0);
  if (!splash)
    {
      fprintf(stderr, "SDL error : %s", SDL_GetError());
      return ;
    }
  SDL_FillRect(splash, NULL, SDL_MapRGB(screen->format, 
					255, 0, 0));
  pos.w = 0;
  pos.h = (screen->h / 2) - 16;
  SDL_BlitSurface(splash, NULL, screen, &pos);
  SDL_Flip(screen);
  SDL_FreeSurface(splash);
  pos.h = (screen->h / 2) - 8;
  pos.w = 16;
  splash_write(screen, str, &pos);
  SDL_WaitEvent(&event);
}
