/*
** exec_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:47:17 2010 francois1 ancel
** Last update Fri Mar 26 20:47:17 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"t_image.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"define.h"
#include	"image_fct.h"
#include	"init_player.h"
#include	"key.h"
#include	"keydown.h"
#include	"back_to_start.h"
#include	"display.h"

void		blit_img_case(SDL_Surface *img, SDL_Surface *to, int x, int y)
{
  SDL_Rect	pos;

  pos.x = x * IMG_SIZE;
  pos.y = y * IMG_SIZE;
  SDL_BlitSurface(img, NULL, to, &pos);
}

t_npc		*init_all(t_image *img, t_player *player, t_map *map)
{
  img_init(img);
  init(player, map, img);
  return (get_npc_monsters(map, img));
}

int		exec_fct(SDL_Surface *screen, t_map *map)
{
  t_player	player;
  int		continuer;
  t_image	img;
  int		jump;
  t_npc		*monsters;

  SDL_EnableKeyRepeat(10, 10);
  continuer = 1;
  monsters = init_all(&img, &player, map);
  jump = 0;
  while (continuer > 0)
    {
      display_map(screen, map, &img);
      display_npcs(screen, monsters);
      display_player(screen, &player);
      display_life(screen, &player);
      SDL_Flip(screen);
      continuer = gravite(&player, map);
      if (continuer >= 0)
	player_act(&continuer, map, &player);
      if (continuer > 0)
	continuer = env_act(map, &player, monsters);
    }
  img_delete(&img);
  return (continuer);
}
