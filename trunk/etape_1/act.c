/*
** act for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:14:43 2010 francois1 ancel
** Last update Fri Mar 26 22:14:43 2010 francois1 ancel
*/

#include	<SDL/SDL.h>
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"

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
      else
	SDL_Delay(30 - (tempsActuel - tempsPrecedent));
    }
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

void		env_act(int *jump, t_map *map, t_player *player, t_npc *monsters)
{
  if (*jump == 0)
    gravite(player, map);
  if (*jump >= 2)
    *jump = 0;
  if (!player->move)
    {
      if (!monsters->move)
	monsters->move = 5;
      monster_time(player, map, monsters);
    }
  are_you_dying(monsters, player, map);
  SDL_Delay(50);
}

void		player_act(int *jump, int *continuer,
			   t_map *map, t_player *player)
{
  *continuer = handle_event(player, map);
  if (*continuer == 42)
    *jump = *jump + 1;
}
