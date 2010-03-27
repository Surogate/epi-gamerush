/*
**
*/
#include	<SDL/SDL.h>
#include	"env.h"
#include	"map.h"

void		search_pos(t_map *map, int *res)
{
  int		width;
  int		height;

  height = 0;
  while (height < map->height)
    {
      width = 0;
      while (width < map->width)
	{
	  if (map->map[height][width] == 'i')
	    {
	      res[0] = width;
	      res[1] = height;
	    }
	  width++;
	}
      height++;
    }
}

void		init(SDL_Surface *screen, t_player *player, t_map *map)
{
  int		pos[2];

  search_pos(map, pos);
  player->position.x = pos[0];
  player->position.y = pos[1];
  player->life = 1;
  player->weapon = 0;
  player->direction = 1;
  player->img_lenght = 10;
  player->img_height = 10;
  player->imageDeFond = SDL_LoadBMP("CLOUDS.BMP");
  player->player_img = SDL_LoadBMP("image/Kong.bmp");
  aff(screen, player);
}
