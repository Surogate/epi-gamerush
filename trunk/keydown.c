/*
**
*/

#include	<SDL/SDL.h>
#include	"key.h"
#include	"env.h"
#include	"map.h"
#include	"exec_fct.h"
#include	"keydown.h"

t_key		key_list[]=
  {
    {SDLK_ESCAPE, exit_func},
    {SDLK_LEFT, press_left},
    {SDLK_RIGHT, press_right},
    {SDLK_UP, press_up},
    {SDLK_DOWN, press_down},
    {0,0}
  };

t_func		event_func[]=
  {
    {SDL_QUIT, exit_func},
    {SDL_KEYDOWN, key_func},
    {0,0}
  };

int		exit_func()
{
  return (0);
}

int		event_loop(SDL_Event *event, t_player *player, t_map *map)
{
  int		i;
  int		continuer;

  i = 0;
  while (event_func[i].type)
    {
      if (event->type == event_func[i].type)
	continuer = event_func[i].func(event, player, map);
      i++;
    }
  return (continuer);
}

int		key_func(SDL_Event *event, t_player *player, t_map *map)
{
  int		i;
  int		retour;
  Uint8		*keystate = SDL_GetKeyState(NULL);

  i = 0;
  retour = 1;
  while (key_list[i].keycode)
    {
      if (keystate[key_list[i].keycode])
	retour = key_list[i].func(player, map);
      i++;
    }
  return (retour);
}
