/*
**
*/

#ifndef		KEY_H
# define	KEY_H
#include	"env.h"

typedef	struct	s_key
{
  SDLKey	keycode;
  int		(*func)();
}		t_key;

int		exit_func();
int		press_up(t_player *player);
int		press_down(t_player *player);
int		press_left(t_player *player);
int		press_right(t_player *player);

#endif
