/*
** image_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:14:43 2010 francois1 ancel
** Last update Fri Mar 26 22:14:43 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"SDL/SDL.h"
#include	"t_image.h"
#include	"define.h"

SDL_Surface	*img_load(char *path)
{
  SDL_Surface	*img;
  SDL_Surface	*tmp;

  tmp = SDL_LoadBMP(path);
  if (tmp)
    {
      img = SDL_DisplayFormat(tmp);
      SDL_FreeSurface(tmp);
      return (img);
    }
  return (NULL);
}

int		img_init(t_image *img)
{
  img->white = img_load(WHIT_DIR);
  img->wall = img_load(WALL_DIR);
  img->ladder = img_load(LAD_DIR);
  img->monster = img_load(MON_DIR);
  SDL_SetColorKey(img->monster, SDL_SRCCOLORKEY, SDL_MapRGB(img->monster->format, 255, 255, 255));
  img->exit = img_load(EXIT_DIR);
  img->enter = img_load(ENT_DIR);
  img->hero = img_load(HERO_DIR);
  /*  SDL_SetColorKey(img->hero, SDL_SRCCOLORKEY, SDL_MapRGB(img->hero->format, 255, 255, 255));*/
  img->key = img_load(KEY_DIR);
  /*  SDL_SetColorKey(img->key, SDL_SRCCOLORKEY, SDL_MapRGB(img->key->format, 255, 255, 255));*/
  return (EXIT_SUCCESS);
}

int		img_delete(t_image *img)
{
  SDL_FreeSurface(img->white);
  SDL_FreeSurface(img->wall);
  SDL_FreeSurface(img->ladder);
  SDL_FreeSurface(img->monster);
  SDL_FreeSurface(img->exit);
  SDL_FreeSurface(img->enter);
  SDL_FreeSurface(img->hero);
  SDL_FreeSurface(img->key);
  return (EXIT_SUCCESS);
}
