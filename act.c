/*
**
*/
#include	<SDL/SDL.h>
#include	<math.h>
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"

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

void		gravite(t_player *player, t_map *map)
{
  int			tempsActuel = 0;
  static int		tempsPrecedent = 0;
  static int		fall_len = 0;
  static int		save = 0;
  int			temp;

  if (map->map[player->position.y + 1][player->position.x] != WALL_CHAR &&
      map->map[player->position.y][player->position.x] != LADDER_CHAR)
    {
      tempsActuel = SDL_GetTicks();
      if (tempsActuel - tempsPrecedent > 30)
	{
	  temp = something_on_da_way(player, map, (int)pow(2, fall_len));
	  save += temp;
	  player->position.y += temp;
	  tempsPrecedent = tempsActuel;
	  fall_len++;
	}
      else
	SDL_Delay(30 - (tempsActuel - tempsPrecedent));
    }
  else
    {
      if (save > 4)
	you_loose(player, map);
      
      fall_len = 0;
      save = 0;
      player->wait = 0;
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

void		env_act(int *jump, t_map *map, 
			t_player *player, t_npc *monsters)
{
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
}
