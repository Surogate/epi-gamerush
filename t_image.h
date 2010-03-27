/*
** t_image for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 21:46:17 2010 francois1 ancel
** Last update Fri Mar 26 21:46:17 2010 francois1 ancel
*/

#ifndef		T_IMAGE_INCLUDED
# define	T_IMAGE_INCLUDED

typedef struct	s_image
{
  SDL_Surface	*white;
  SDL_Surface	*wall;
  SDL_Surface	*ladder;
  SDL_Surface	*monster1;
  SDL_Surface	*monster2;
  SDL_Surface	*monster3;
  SDL_Surface	*exit;  
  SDL_Surface	*enter;
  SDL_Surface	*hero1;
  SDL_Surface	*hero2;
  SDL_Surface	*hero3;
  SDL_Surface	*key;
}		t_image;

typedef	struct
{
  char		obj;
  SDL_Surface	*img;
}		test;

#endif
