/*
** exec_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:47:17 2010 francois1 ancel
** Last update Fri Mar 26 20:47:17 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "exec_fct.h"
#include "map.h"
#include "t_image.h"
#include "image_fct.h"

int		exit_func()
{
  return (0);
}

t_func		event_func[]=
  {
    {SDL_QUIT, exit_func},
    {0,0}
  };

void		init_screen(SDL_Surface *screen)
{
  SDL_Surface	*rectangle = NULL, *imageDeFond = NULL;
  SDL_Rect	position;

  position.x = 0;
  position.y = 0;
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
  imageDeFond = SDL_LoadBMP("CLOUDS.BMP");
  SDL_BlitSurface(imageDeFond, NULL, screen, &position);
  SDL_Flip(screen);
  SDL_FreeSurface(rectangle);
  SDL_FreeSurface(imageDeFond);
}

void		display_map(SDL_Surface *screen, t_map *map)
{
  
}

void		display_npc(SDL_Surface *screen, t_map *map)
{
}

int		exec_fct(SDL_Surface *screen, t_map *map)
{
  SDL_Event	event;
  int		i; 
  int		continuer;
  t_image	img;

  continuer = 1;
  img_init(&img);
  init_screen(screen);
  while (continuer > 0)
    {
      display_map(screen, map);
      display_npc(screen, map);
      SDL_WaitEvent(&event);
      i = 0;
      while (event_func[i].type)
	{
	  if (event.type == event_func[i].type)
	    continuer = event_func[i].func();
	  i++;
	}
    }
  return (EXIT_SUCCESS);
}
