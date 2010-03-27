/*
** image_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:14:43 2010 francois1 ancel
** Last update Fri Mar 26 22:14:43 2010 francois1 ancel
*/

#ifndef		__KEY_H__
# define	__KEY_H__

typedef	struct	s_key
{
  SDLKey	keycode;
  int		(*func)();
}		t_key;

int		exit_func();
int		press_up(t_player *player, t_map *map);
int		press_down(t_player *player, t_map *map);
int		press_left(t_player *player, t_map *map);
int		press_right(t_player *player, t_map *map);
int		pass(t_player *player);

#endif		/* __KEY_H__ */
