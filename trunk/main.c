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
#include	<SDL/SDL_ttf.h>
#include	"t_image.h"
#include	"err.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"define.h"
#include	"windows.h"

int		main()
{
  char		*level;
  int		continuer;
  int		finished;

  finished = 0;
  continuer = 1;
  while (continuer)
    {
      if ((level = exec_menu()) == (char *)-1)
	continuer = 0;
      else
	while ((continuer = exec_map(level)) == 0)
	  {
	    get_next_level(&level, &finished);
	    if (finished)
	      exec_map(BOSS_DIR);
	    if (level == NULL)
	      {
		continuer = 1;
		break;
	      }
	  }
    }
  return (EXIT_SUCCESS);
}
