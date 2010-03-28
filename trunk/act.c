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
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"
#include	<stdio.h>

int		something_on_da_way(t_player *player, t_map *map, int fall_len)
{
  int		height;

  height = 0;
  while (height < fall_len)
    {
      if (map->map[player->position.y + height + 1][player->position.x] == 'w' ||
	  map->map[player->position.y + height + 1][player->position.x] == 's')
	{
	  return (height);
	}
      height++;
    }
  return (height);
}

int		falling(t_player *player, t_map *map, int fall_len)
{
  int		temp;

  temp = something_on_da_way(player, map, (int)pow(2, fall_len));
  player->position.y += temp;
  return (temp);
}

int		life_verif(t_player *player, t_map *map, int *save)
{
  int		flag;

  flag = 0;
  if (*save > 4)
    flag = you_loose(player, map);
  player->wait = 0;
  *save = 0;
  return (flag);
}

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
      if (tempsActuel - tempsPrecedent > 30)
	{
	  save += falling(player, map, fall_len);
	  tempsPrecedent = tempsActuel;
	  fall_len++;
	}
      else
	SDL_Delay(30 - (tempsActuel - tempsPrecedent));
    }
  else
    {
      fall_len = 0;
      return (life_verif(player, map, &save));
    }
  return (0);
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
      if (monsters)
	{
	  if (!monsters->move)
	    monsters->move = 5;
	  monster_time(player, map, monsters);
	}
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
