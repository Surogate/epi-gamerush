/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:37:35 2010 francois1 ancel
** Last update Fri Mar 26 20:37:35 2010 francois1 ancel
*/

#ifndef		ENV_H
# define	ENV_H

#include	<SDL/SDL.h>
#include	"map.h"
#include	"npc.h"

typedef struct	s_obj
{
  int		keys;
  int		weapon;
}		t_obj;

typedef	struct	s_player
{
  SDL_Rect	position;
  SDL_Rect	vitesse;
  SDL_Surface	*player_img1;
  SDL_Surface	*player_img2;
  SDL_Surface	*player_img3;
  SDL_Surface	*imageDeFond;
  t_obj		item[1];
  int		img_height;
  int		img_lenght;
  int		life;
  int		weapon;
  int		direction;
  int		move;
}		t_player;

int		monster_time(t_player *player, t_map *map, t_npc *npc);

#endif
