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

int		exit_func()
{
  return (0);
}

t_func		event_func[]=
  {
    {SDL_QUIT, exit_func},
    {0,0}
  };

int		exec_fct(SDL_Surface *screen)
{
  SDL_Event	event;
  int		i; 
  int		continuer;

  continuer = 1;
  while (continuer > 0)
    {
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
