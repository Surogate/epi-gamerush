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
  img->wall = img_load(WALL_DIR);
  img->ladder = img_load(LAD_DIR);
  img->monster = img_load(MON_DIR);
  img->exit = img_load(EXIT_DIR);
  img->enter = img_load(ENT_DIR);
  return (EXIT_SUCCESS);
}

int		img_delete(t_image *img)
{
  SDL_FreeSurface(img->wall);
  SDL_FreeSurface(img->ladder);
  SDL_FreeSurface(img->monster);
  SDL_FreeSurface(img->exit);
  SDL_FreeSurface(img->enter);
  return (EXIT_SUCCESS);
}
