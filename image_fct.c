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
#include	<SDL/SDL.h>
#include	"define.h"
#include	"err.h"
#include	"t_image.h"

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
  img->exit = img_load(EXIT_DIR);
  img->enter = img_load(ENT_DIR);
  img->monster1 = img_load(MON_DIR1);
  img->monster2 = img_load(MON_DIR2);
  img->monster3 = img_load(MON_DIR3);
  SDL_SetColorKey(img->monster1, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(img->monster1->format, 255, 255, 255));
  SDL_SetColorKey(img->monster2, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(img->monster2->format, 255, 255, 255));
  SDL_SetColorKey(img->monster3, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(img->monster3->format, 255, 255, 255));
  img->hero1 = img_load(HERO_DIR1);
  img->hero2 = img_load(HERO_DIR2);
  img->hero3 = img_load(HERO_DIR3);
  SDL_SetColorKey(img->hero1, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(img->hero1->format, 255, 255, 255));
  SDL_SetColorKey(img->hero2, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(img->hero2->format, 255, 255, 255));
  SDL_SetColorKey(img->hero3, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(img->hero3->format, 255, 255, 255));
  img->key = img_load(KEY_DIR);
  return (EXIT_SUCCESS);
}

int		img_delete(t_image *img)
{
  SDL_FreeSurface(img->white);
  SDL_FreeSurface(img->wall);
  SDL_FreeSurface(img->ladder);
  SDL_FreeSurface(img->monster1);
  SDL_FreeSurface(img->monster2);
  SDL_FreeSurface(img->monster3);
  SDL_FreeSurface(img->exit);
  SDL_FreeSurface(img->enter);
  SDL_FreeSurface(img->hero1);
  SDL_FreeSurface(img->hero2);
  SDL_FreeSurface(img->hero3);
  SDL_FreeSurface(img->key);
  return (EXIT_SUCCESS);
}
