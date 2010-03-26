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

int		exec_fct(SDL_Surface *screen)
{
  int		continuer = 1;
  SDL_Event	event;
  
  while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_QUIT:
	  continuer = 0;
        }
    }
  return (EXIT_SUCCESS);
}
