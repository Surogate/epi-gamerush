/*
** keydown.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 05:23:48 2010 francois1 ancel
** Last update Sat Mar 27 05:23:48 2010 francois1 ancel
*/

#ifndef KEYDOWN_C_INCLUDED
# define KEYDOWN_C_INCLUDED

int		exit_func();
int		event_loop(SDL_Event *event, t_player *player, t_map *map);
int		key_func(t_player *player, t_map *map);

#endif
