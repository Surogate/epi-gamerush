/*
** display.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 18:07:19 2010 francois1 ancel
** Last update Sat Mar 27 18:07:19 2010 francois1 ancel
*/

#ifndef DISPLAY_C_INCLUDED
# define DISPLAY_C_INCLUDED

void		display_player(SDL_Surface *screen, t_player *player);
void		display_npcs(SDL_Surface *screen, t_npc *npc);
void		display_map(SDL_Surface *screen, t_map *map, t_image *img);
t_imgtab	*init_da_tab();
void		display_life(SDL_Surface *screen, t_player *player);

#endif
