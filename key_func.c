/*
**
*/
#include	<SDL/SDL.h>
#include	"define.h"
#include	"env.h"

int		press_up(t_player *player)
{
  if (player->position.y > 0)
    {
      player->position.y -= 1;
      return (1);
    }
  else
    return (2);
}

int		press_down(t_player *player)
{
  if (player->position.y + player->img_height < MWIN_HEIGHT)
    {
      player->position.y += 1;
      return (1);
    }
  else
    return (2);
}

int		press_left(t_player *player)
{
  if (player->position.x > 0)
    {
      player->position.x -= 1;
      return (1);
    }
  else
    return (2);
}

int		press_right(t_player *player)
{
  if (player->position.x + player->img_lenght < MWIN_WIDTH)
    {
      player->position.x += 1;
      return (1);
    }
  else
    return (2);
}
