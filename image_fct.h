/*
** image_fct.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 23:59:40 2010 francois1 ancel
** Last update Fri Mar 26 23:59:40 2010 francois1 ancel
*/

#ifndef IMAGE_FCT_C_INCLUDED
# define IMAGE_FCT_C_INCLUDED

SDL_Surface	*img_load(char *path);
int		img_init(t_image *img);
int		img_delete(t_image *img);
void		next_lvl(SDL_Surface *ecran);

#endif
