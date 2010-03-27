/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:16:19 2010 francois1 ancel
** Last update Fri Mar 26 22:16:19 2010 francois1 ancel
*/

#ifndef			__NPC_H__
# define		__NPC_H__

#include		"t_image.h"

typedef struct		s_npc
{
  int			x;
  int			y;
  int			vx;
  int			move;
  int			frame;
  SDL_Surface		*img1;
  SDL_Surface		*img2;
  SDL_Surface		*img3;
  struct s_npc		*next;
}			t_npc;

t_npc			*get_npc_monsters(t_map *map, t_image *img);

#endif			/* __NPC_H__ */
