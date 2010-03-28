/*
** windows.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 28 03:28:35 2010 francois1 ancel
** Last update Sun Mar 28 03:28:35 2010 francois1 ancel
*/

#ifndef WINDOWS_C_INCLUDED
# define WINDOWS_C_INCLUDED

int		exec_map(char *path);
void		print_menu(SDL_Surface *screen, TTF_Font *font);
void		disp_menu(SDL_Surface *screen);
char		*exec_menu();
SDL_Surface	*creat_win(t_map *map);

#endif
