/*
**
*/
#include	<SDL/SDL.h>
#include	"key.h"
#include	"env.h"

t_key		key_list[]=
  {
    {SDLK_ESCAPE, exit_func},
    {SDLK_UP, press_up},
    {SDLK_DOWN, press_down},
    {SDLK_LEFT, press_left},
    {SDLK_RIGHT, press_right},
    {0,0}
  };

int		key_func(SDL_Event *event, SDL_Surface *screen, t_player *player)
{
  int		i;
  int		retour;

  i = 0;
  retour = 1;
  while (key_list[i].keycode)
    {
      if (key_list[i].keycode == event->key.keysym.sym)
	retour = key_list[i].func(player);
      i++;
    }
  aff(screen, player);
  return (retour);
}