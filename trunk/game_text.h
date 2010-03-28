/*
** game_text.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 28 23:31:14 2010 francois1 ancel
** Last update Sun Mar 28 23:31:14 2010 francois1 ancel
*/

#ifndef GAME_TEXT_C_INCLUDED
# define GAME_TEXT_C_INCLUDED

void		display_life(SDL_Surface *screen, t_player *player);
void		display_text(SDL_Surface *screen, t_player *player,
			     TTF_Font *font);
#endif
