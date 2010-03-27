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
#include	"env.h"
#include	"exec_fct.h"
#include	"define.h"
#include	"image_fct.h"
#include	"init_player.h"
#include	"key.h"
#include	"keydown.h"
#include	"map.h"
#include	"npc.h"


test		*init_da_tab()
{
  test		*res;

  res = malloc(7 * sizeof(*res));
  if (res)
    {
      res[0].obj = '.';
      res[0].img = img_load(WHIT_DIR);
      res[1].obj = 's';
      res[1].img = img_load(WALL_DIR);
      res[2].obj = 'w';
      res[2].img = img_load(LAD_DIR);
      res[3].obj = 'm';
      res[3].img = img_load(MON_DIR1);
      res[4].obj = 'o';
      res[4].img = img_load(EXIT_DIR);
      res[5].obj = 'i';
      res[5].img = img_load(ENT_DIR);
      res[6].obj = 'k';
      res[6].img = img_load(KEY_DIR);
    }
  return (res);
}

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
	    blit_img_case(img->monster1, screen, width, height);
	  else if (map->map[height][width] == 'k')
	    blit_img_case(img->key, screen, width, height);
	  width++;
	}
      height++;
    }
}

void		display_player(SDL_Surface *screen, t_player *player)
{
  static int	cpt = 0;

  cpt++;
  if (cpt == 3)
    {
      cpt = 0;
      blit_img_case(player->player_img1, screen,
		    player->position.x, player->position.y);
    }
  else if (cpt == 1)
    blit_img_case(player->player_img2, screen,
		  player->position.x, player->position.y);
  else
    blit_img_case(player->player_img3, screen,
		  player->position.x, player->position.y);
}

void		display_npcs(SDL_Surface *screen, t_npc *npc)
{
  while (npc != 0)
    {
      npc->frame++;
      if (npc->frame == 3)
	{
	  npc->frame = 0;
	  blit_img_case(npc->img1, screen, npc->x, npc->y);
	}
      else if (npc->frame == 1)
	blit_img_case(npc->img2, screen, npc->x, npc->y);
      else
	blit_img_case(npc->img3, screen, npc->x, npc->y);
      npc = npc->next;
    }
}

/*
int		find_path(SDL_Rect *position, t_map *map, int i)
{
  int		res;


}
*/

void		gravite(t_player *player, t_map *map)
{
  static int		tempsActuel = 0;
  static int		tempsPrecedent = 0;

  if (map->map[player->position.y + 1][player->position.x] != 'w' &&
      map->map[player->position.y + 1][player->position.x] != 's')
    {
      tempsActuel = SDL_GetTicks();
      if (tempsActuel - tempsPrecedent > 30)
	{
	  player->position.y += 1;
	  tempsPrecedent = tempsActuel;
	}
      else /* Si ça fait moins de 30ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
	{
	  SDL_Delay(30 - (tempsActuel - tempsPrecedent));
	}
      /*SDL_Delay(100);*/
    }
}

int		exec_fct(SDL_Surface *screen, t_map *map)
{
  SDL_Event	event;
  t_player	player;
  int		continuer;
  t_image	img;
  int		test;
  int		pouet;
  t_npc		*monsters;

  SDL_EnableKeyRepeat(10, 10);
  continuer = 1;
  img_init(&img);
  init(&player, map, &img);
  monsters = get_npc_monsters(map, &img);
  pouet = 0;
  while (continuer > 0)
    {
      display_map(screen, map, &img);
      display_npcs(screen, monsters);
      display_player(screen, &player);
      SDL_Flip(screen);
      if (continuer != 42)
	{
	  test = SDL_PollEvent(&event);
	  if (test)
	    continuer = event_loop(&event, &player, map);
	}
      else
	{
	  pouet++;
	  if (map->map[player.position.y - 1][player.position.x] != 'w')
	    player.position.y--;
	  continuer = 1;
	}
      if (continuer == 42)
	pouet++;
      if (pouet == 0)
	gravite(&player, map);
      if (pouet >= 2)
	pouet = 0;
      SDL_Delay(50);
    }
  return (EXIT_SUCCESS);
}
