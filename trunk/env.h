/*
**
*/

#ifndef		ENV_H
# define	ENV_H

#include	<SDL/SDL.h>

typedef	struct	s_player
{
  SDL_Rect	position;
  SDL_Surface	*player_img;
  SDL_Surface	*imageDeFond;
  int		img_height;
  int		img_lenght;
  int		life;
  int		weapon;
  int		direction;
}		t_player;

#endif
