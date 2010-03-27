/*
** exec_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:47:17 2010 francois1 ancel
** Last update Fri Mar 26 20:47:17 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "env.h"
#include "define.h"
#include "key.h"
#include "map.h"
#include "t_image.h"
#include "image_fct.h"
#include "keydown.h"
#include "exec_fct.h"

void		blit_img_case(SDL_Surface *img, SDL_Surface *to, int x, int y)
{
  SDL_Rect	pos;

  pos.x = x * IMG_SIZE;
  pos.y = y * IMG_SIZE;
  SDL_BlitSurface(img, NULL, to, &pos);
}

void		display_map(SDL_Surface *screen, t_map *map, t_image *img)
{
  int width;
  int height;

  height = 0;
  while (height < map->height)
    {
      width = 0;
      while (width < map->width)
	{
	  if (map->map[height][width] == 'w')
	    blit_img_case(img->wall, screen, width, height);
	  else if (map->map[height][width] == 's')
	    blit_img_case(img->ladder, screen, width, height);
	  else if (map->map[height][width] == '.')
	    blit_img_case(img->white, screen, width, height);
	  else if (map->map[height][width] == 'i')
	    blit_img_case(img->enter, screen, width, height);
	  else if (map->map[height][width] == 'o')
	    blit_img_case(img->exit, screen, width, height);
	  else if (map->map[height][width] == 'm')
	    blit_img_case(img->monster, screen, width, height);
	  else if (map->map[height][width] == 'k')
	    blit_img_case(img->key, screen, width, height);
	  width++;
	}
      height++;
    }
}

void		display_npc(SDL_Surface *screen, t_player *player)
{
  blit_img_case(player->player_img, screen,
		player->position.x, player->position.y);
}

void		gravite(t_player *player, t_map *map)
{
  if (map->map[player->position.y + 1][player->position.x] != 'w' &&
      map->map[player->position.y + 1][player->position.x] != 's')
    player->position.y += 1;
}

int		exec_fct(SDL_Surface *screen, t_map *map)
{
  SDL_Event	event;
  t_player	player;
  int		continuer;
  t_image	img;
  int		test;

  SDL_EnableKeyRepeat(10, 50);
  continuer = 1;
  img_init(&img);
  init(&player, map);
  while (continuer > 0)
    {
      display_map(screen, map, &img);
      display_npc(screen, &player);
      SDL_Flip(screen);
      test = SDL_PollEvent(&event);
      if (test)
	{
	  /*event_loop(&event, &player, map);*/
	  
	  int i = 0;
	  while (event_func[i].type)
	    {
	      if (event.type == event_func[i].type)
		continuer = event_func[i].func(&event, &player, map);
	      i++;
	    }
	  
	}
      gravite(&player, map);
    }
  return (EXIT_SUCCESS);
}
