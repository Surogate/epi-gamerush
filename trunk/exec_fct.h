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

int		exec_fct(SDL_Surface *screen, t_map *map);
void		gravite(t_player *player, t_map *map);
int		handle_event(t_player *player, t_map *map);
void		env_act(t_map *map, 
			t_player *player, t_npc *monsters);
void		blit_img_case(SDL_Surface *img, SDL_Surface *to,
			      int x, int y);
void		player_act(int *continuer,
			   t_map *map, t_player *player);
void		env_act(t_map *map, 
			t_player *player, t_npc *monsters);

#endif
