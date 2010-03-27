/*
**
*/
#include	<SDL/SDL.h>
#include	"env.h"

void		init(SDL_Surface *screen, t_player *player)
{
  player->position.x = 0;
  player->position.y = 0;
  player->life = 1;
  player->weapon = 0;
  player->direction = 1;
  player->img_lenght = 10;
  player->img_height = 10;
  player->player_img = SDL_LoadBMP("player.bmp");
  player->imageDeFond = SDL_LoadBMP("CLOUDS.BMP");
  aff(screen, player);
}
