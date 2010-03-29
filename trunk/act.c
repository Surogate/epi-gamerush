/*
** act.c for epikong
**
** Made by quentin muller
** Login   <muller_b@epitech.net>
**
** Started on  Wed Mar  3 11:45:11 2010 quentin muller
** Last update Sun Mar 14 18:30:19 2010 quentin muller
*/

#include	<SDL/SDL.h>
#include	<math.h>
#include	<stdio.h>
#include	"boss.h"
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"
#include	"define.h"

int		gravite(t_player *player, t_map *map)
{
  int			tempsActuel;
  static int		tempsPrecedent = 0;
  static int		fall_len = 0;
  static int		save = 0;

  if (map->map[player->position.y + 1][player->position.x] != WALL_CHAR &&
      map->map[player->position.y][player->position.x] != LADDER_CHAR &&
      map->map[player->position.y + 1][player->position.x] != LADDER_CHAR)
    {
      tempsActuel = SDL_GetTicks();
      if (tempsActuel - tempsPrecedent > 50)
	{
	  save += falling(player, map, fall_len);
	  tempsPrecedent = tempsActuel;
	  fall_len++;
	}
      else
	SDL_Delay(50 - (tempsActuel - tempsPrecedent));
    }
  else
    {
      fall_len = 0;
      return (life_verif(player, map, &save));
    }
  return (1);
}

int		handle_event(t_player *player, t_map *map)
{
  SDL_Event	event;
  int		temp;

  temp = SDL_PollEvent(&event);
  if (temp)
    return (event_loop(&event, player, map));
  return (1);
}

int		env_act(t_map *map,
			t_player *player, t_npc *monsters)
{
  int		retour;

  if (!player->move)
    {
      if (map->boss.img1)
	{
	  if (!map->boss.move)
	    map->boss.move = NB_MOVE;
	  ia(player, &map->boss, map);
	}
      else if (monsters)
	{
	  if (!monsters->move)
	    monsters->move = NB_MOVE;
	  monster_time(player, map, monsters);
	}
      else
	player->move = NB_MOVE;
    }
  retour = are_you_dying(monsters, player, map);
  SDL_Delay(50);
  return (retour);
}

void		player_act(int *continuer,
			   t_map *map, t_player *player)
{
  *continuer = handle_event(player, map);
}
