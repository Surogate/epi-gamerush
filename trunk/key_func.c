/*
**
*/
#include	<SDL/SDL.h>
#include	"define.h"
#include	"env.h"

int		press_up(t_player *player)
{
  if (player->position.y)
    {
      player->position.y -= 10;
      return (1);
    }
  else
    return (0);
}

int		press_down(t_player *player)
{
  if (player->position.y + player->img_height < WIN_HEIGHT)
    {
      player->position.y += 10;
      return (1);
    }
  else
    return (0);
}

int		press_left(t_player *player)
{
  if (player->position.x)
    {
      player->position.x -= 10;
      return (1);
    }
  else
    return (0);
}

int		press_right(t_player *player)
{
  if (player->position.x + player->img_lenght < WIN_LENGTH)
    {
      player->position.x += 10;
      return (1);
    }
  else
    return (0);
}
