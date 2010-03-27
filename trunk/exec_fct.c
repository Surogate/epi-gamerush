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
#include "exec_fct.h"
#include "env.h"
#include "define.h"
#include "key.h"
#include "map.h"
#include "t_image.h"
#include "image_fct.h"


int		exit_func()
{
  return (0);
}

void		aff(SDL_Surface *screen, t_player *player)
{
  SDL_Rect	position;

  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(player->imageDeFond, NULL, screen, &position);
  SDL_BlitSurface(player->player_img, NULL, screen, &player->position);
  SDL_Flip(screen);
}


t_func		event_func[]=
  {
    {SDL_QUIT, exit_func},
    {SDL_KEYDOWN, key_func},
    {0,0}
  };

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
	  width++;
	}
      height++;
    }
}

void		display_npc(SDL_Surface *screen, t_map *map)
{
  
}

void		gravite(t_player *player)
{
  player->position.y += 1;
}

int		exec_fct(SDL_Surface *screen, t_map *map)
{
  SDL_Event	event;
  t_player	player;
  int		i; 
  int		continuer;
  t_image	img;
  int		test;

  SDL_EnableKeyRepeat(1, 10);
  continuer = 1;
  img_init(&img);
  while (continuer > 0)
    {
      display_map(screen, map, &img);
      display_npc(screen, map);
      test = SDL_PollEvent(&event);
      if (test)
	{
	  i = 0;
	  while (event_func[i].type)
	    {
	      if (event.type == event_func[i].type)
		continuer = event_func[i].func(&event, screen, &player);
	      i++;
	    }
	}
      gravite(&player);
      aff(screen, &player);
    }
  return (EXIT_SUCCESS);
}
