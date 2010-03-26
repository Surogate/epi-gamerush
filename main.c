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

int		main()
{
  int		result;
  SDL_Surface	*screen;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      fprintf(stderr, "Can't init SDL: %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
  SDL_WM_SetCaption("Epikong", NULL);
  if (!screen)
    {
      fprintf(stderr, "screen load fail %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  result = exec_fct(screen);
  if (result == EXIT_FAILURE)
    perror("exec_fct");
  SDL_Quit();
  return (result);
}
