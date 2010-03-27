#ifndef			__NPC_H__
# define		__NPC_H__

typedef struct		s_npc
{
  int			x;
  int			y;
  int			vx;
  int			frame;
  SDL_Surface		*img1;
  SDL_Surface		*img2;
  SDL_Surface		*img3;
  struct s_npc		*next;
}			t_npc;

t_npc			*get_npc_monsters(t_map *map, t_image *img);

#endif			/* __NPC_H__ */
