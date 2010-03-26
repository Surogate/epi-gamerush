/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:37:35 2010 francois1 ancel
** Last update Fri Mar 26 20:37:35 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"SDL/SDL.h"
#include	"exec_fct.h"
#include	"define.h"

int		main(int ac, char **av)
{
  int		result;
  SDL_Surface	*screen;
  t_map		*map;

  if (ac > 1)
    map = get_map(av[1]);
  else
    return (EXIT_SUCCESS);
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      fprintf(stderr, "Can't init SDL: %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetIcon(SDL_LoadBMP("DonkeyKong2.bmp"), NULL);
  screen = SDL_SetVideoMode(WIN_LENGTH, WIN_HEIGHT, WIN_COLOR, SDL_SWSURFACE);
  SDL_WM_SetCaption("Epikong", NULL);
  if (!screen)
    {
      fprintf(stderr, "screen load fail %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  result = exec_fct(screen);
  SDL_Quit();
  return (result);
}
