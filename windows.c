/*
** windows for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 01:06:35 2010 francois1 ancel
** Last update Sat Mar 27 01:06:35 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"map.h"
#include	"define.h"

SDL_Surface	*creat_win(t_map *map)
{
  int		win_height;
  int		win_width;
  SDL_Surface	*screen;

  win_width = map->width * IMG_SIZE;
  win_height = map->height * IMG_SIZE;
  if (win_width > MWIN_WIDTH)
    win_width = MWIN_WIDTH;
  if (win_height > MWIN_HEIGHT)
    win_height = MWIN_HEIGHT;
  SDL_WM_SetIcon(SDL_LoadBMP("image/DonkeyKong2.bmp"), NULL);
  screen = SDL_SetVideoMode(win_width, win_height, WIN_COLOR, 
			    SDL_HWSURFACE | SDL_DOUBLEBUF );
  SDL_WM_SetCaption("Epikong", NULL);
  return (screen);
}
