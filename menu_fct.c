/*
** menu_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 28 00:48:50 2010 francois1 ancel
** Last update Sun Mar 28 00:48:50 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"t_image.h"
#include	"image_fct.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"key.h"
#include	"define.h"
#include	"menu_exec.h"

void			print_mark(SDL_Surface *screen, int select)
{
  SDL_Surface		*mark = img_load(MARK_DIR);
  SDL_Rect		pos;

  pos.x = MENU_X - 50;
  pos.y = MENU_Y + select * (FONT_SIZE + 5);
  SDL_BlitSurface(mark, NULL, screen, &pos);
  SDL_Flip(screen);
}

void		menu_key(int *select, char **ret)
{
  int		i;
  Uint8		*keystate;
  static t_key 	keylist[] = {
    {SDLK_ESCAPE, menu_exit},
    {SDLK_UP, menu_up},
    {SDLK_DOWN, menu_down},
    {SDLK_RETURN, menu_return},
    {0, 0}
  };

  keystate = SDL_GetKeyState(NULL);
  i = 0;
  while (keylist[i].keycode)
    {
      if (keystate[keylist[i].keycode])
	keylist[i].func(select, ret);
      i++;
    }
  if (ret != (char *)-1)
    printf("ret = %s\n", ret);
}

char		*menu_loop(SDL_Surface *screen)
{
  static int	select = 0;
  SDL_Event	event;
  char		*ret;

  ret = NULL;
  print_mark(screen, select);
  SDL_WaitEvent(&event);
  if (event.type == SDL_QUIT)
    return ((char *)-1);
  if (event.type == SDL_KEYDOWN)
    menu_key(&select, &ret);
  return (ret);
}
