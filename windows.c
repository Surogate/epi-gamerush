/*
** windows for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 01:06:35 2010 francois1 ancel
** Last update Sat Mar 27 01:06:35 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>

#include	"t_image.h"
#include	"image_fct.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"define.h"
#include	"err.h"
#include	"windows.h"
#include	"exec_fct.h"
#include	"menu_fct.h"

int		exec_map(char *path)
{
  int		result;
  SDL_Surface	*screen;
  t_map		*map;

  map = check_map(get_map(path));
  if (!map)
    return (EXIT_FAILURE);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    err_SDL("Can't init SDL", 1);
  screen = creat_win(map);
  if (!screen)
    err_SDL("screen load fail", 1);
  result = exec_fct(screen, map);
  SDL_FreeSurface(screen);
  SDL_Quit();
  return (result);
}

void		print_menu(SDL_Surface *screen, TTF_Font *font)
{
  SDL_Rect	pos;
  int		i;
  SDL_Color	color = {0, 0, 0, 0};
  SDL_Surface	*text;
  char		*name[] = {
    "Stage 1",
    "Stage 2",
    "Stage 3",
    "Stage 4",
    "Stage 5",
    "Exit",
    NULL};

  pos.x = MENU_X + 10;
  pos.y = MENU_Y;
  i = 0;
  while (name[i])
    {
      text = TTF_RenderText_Solid(font, name[i], color);
      pos.y = 380 + i * (FONT_SIZE + 5);
      SDL_BlitSurface(text, NULL, screen, &pos);
      i++;
    }
}

void		disp_menu(SDL_Surface *screen)
{
  TTF_Font	*font;

  if (TTF_Init() < 0)
    {
      fprintf(stderr, "TTF error : %s\n", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  font = TTF_OpenFont(MENU_FONT, FONT_SIZE);
  if (!font)
    {
      fprintf(stderr, "TTF error : %s\n", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  print_menu(screen, font);
  SDL_Flip(screen);
  TTF_CloseFont(font);
  TTF_Quit();
}

char		*exec_menu()
{
  SDL_Surface	*screen;
  SDL_Surface	*background;
  SDL_Rect	pos;
  int		continuer;
  char		*ret;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    err_SDL("Can't init SDL", 1);
  SDL_WM_SetIcon(SDL_LoadBMP("image/DonkeyKong2.bmp"), NULL);
  screen = SDL_SetVideoMode(MWIN_WIDTH, MWIN_HEIGHT, WIN_COLOR,
			    SDL_HWSURFACE | SDL_DOUBLEBUF );
  SDL_WM_SetCaption("Epikong", NULL);
  background = img_load(MENU_BACK);
  pos.x = 0;
  pos.y = 0;
  while (continuer)
    {
      SDL_BlitSurface(background, NULL, screen, &pos);
      disp_menu(screen);
      ret = menu_loop(screen);
      if (ret)
	continuer = 0;
    }
  SDL_Quit();
  return (ret);
}

SDL_Surface	*creat_win(t_map *map)
{
  int		win_height;
  int		win_width;
  SDL_Surface	*screen;

  win_width = map->width * IMG_SIZE;
  win_height = map->height * IMG_SIZE;
  if (win_width > MWIN_WIDTH)
    win_width = MWIN_WIDTH;
  if (win_height > MWIN_HEIGHT)
    win_height = MWIN_HEIGHT;
  SDL_WM_SetIcon(SDL_LoadBMP("image/DonkeyKong2.bmp"), NULL);
  screen = SDL_SetVideoMode(win_width, win_height, WIN_COLOR,
			    SDL_HWSURFACE | SDL_DOUBLEBUF );
  SDL_WM_SetCaption("Epikong", NULL);
  return (screen);
}
