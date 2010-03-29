/*
**
*/

#ifndef		BOSS_H
# define	BOSS_H

typedef struct	s_boss
{
  SDL_Rect	pos;
  SDL_Surface	*img1;
  SDL_Surface	*img2;
  int		dir;
  int		move;
  SDL_Surface	*ammo;
  SDL_Rect	ammo_pos;
  int		ammo_dir;
  int		ammo_move;

}		t_boss;

#endif
