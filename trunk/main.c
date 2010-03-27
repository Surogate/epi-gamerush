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
#include	<SDL/SDL.h>
#include	"err.h"
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
    {
      printf("Usage : ./prog [map/?.map]\n");
      return (EXIT_SUCCESS);
    }
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    err_SDL("Can't init SDL", 1);
  screen = creat_win(map);
  if (!screen)
    err_SDL("screen load fail", 1);
  result = exec_fct(screen, map);
  SDL_Quit();
  return (result);
}
