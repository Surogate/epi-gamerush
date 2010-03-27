/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:37:35 2010 francois1 ancel
** Last update Fri Mar 26 20:37:35 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"SDL/SDL.h"
#include	"exec_fct.h"
#include	"map.h"
#include	"define.h"
#include	"windows.h"

int		main(int ac, char **av)
{
  int		result;
  SDL_Surface	*screen;
  t_map		*map;

  if (ac > 1)
    map = get_map(av[1]);
  else
    return (EXIT_SUCCESS);
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      fprintf(stderr, "Can't init SDL: %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  screen = creat_win(map);
  if (!screen)
    {
      fprintf(stderr, "screen load fail %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  
  result = exec_fct(screen, map);
  SDL_Quit();
  return (result);
}
