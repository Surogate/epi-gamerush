/*
** exec_fct.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 21:03:43 2010 francois1 ancel
** Last update Fri Mar 26 21:03:43 2010 francois1 ancel
*/

#ifndef EXEC_FCT_C_INCLUDED
# define EXEC_FCT_C_INCLUDED
#include	<SDL/SDL.h>
#include	"env.h"
#include	"map.h"

typedef struct	s_func
{
  Uint8		type;
  int		(*func)();
}		t_func;

typedef struct
{
  char		*str;
  SDL_Surface	*img;
}		t_dispmap;

int		exec_fct();
int		key_func(SDL_Event *event, SDL_Surface *screen, t_player *player);
void		init(SDL_Surface *screen, t_player *player, t_map *map);
void		aff(SDL_Surface *screen, t_player *player);

#endif
