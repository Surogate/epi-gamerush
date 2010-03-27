/*
** display.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Mar 27 17:49:11 2010 francois1 ancel
** Last update Sat Mar 27 17:49:11 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"t_image.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"

void		display_player(SDL_Surface *screen, t_player *player)
{
  static int	cpt = 0;

  cpt++;
  if (cpt == 6)
    cpt = 0;
  if (cpt < 2)
    {
      if (player->direction == -1)
	blit_img_case(player->player_img1, screen,
		      player->position.x, player->position.y);
      else
	blit_img_case(player->player_img4, screen,
		      player->position.x, player->position.y);
    }
  else if (cpt < 4)
    {
      if (player->direction == -1)
	blit_img_case(player->player_img2, screen,
		      player->position.x, player->position.y);
      else
	blit_img_case(player->player_img5, screen,
		      player->position.x, player->position.y);
    }
  else
    {
      if (player->direction == -1)
	blit_img_case(player->player_img3, screen,
		      player->position.x, player->position.y);
      else
	blit_img_case(player->player_img6, screen,
		      player->position.x, player->position.y);
    }
}

void		display_npcs(SDL_Surface *screen, t_npc *npc)
{
  while (npc != 0)
    {
      npc->frame++;
      if (npc->frame == 6)
	npc->frame = 0;
      if (npc->frame < 2)
	{
	  if (npc->vx == 1)
	    blit_img_case(npc->img1, screen, npc->x, npc->y);
	  else
	    blit_img_case(npc->img4, screen, npc->x, npc->y);
	}
      else if (npc->frame < 4)
	{
	  if (npc->vx == 1)
	    blit_img_case(npc->img2, screen, npc->x, npc->y);
	  else
	    blit_img_case(npc->img5, screen, npc->x, npc->y);
	}
      else
	{
	  if (npc->vx == 1)
	    blit_img_case(npc->img3, screen, npc->x, npc->y);
	  else
	    blit_img_case(npc->img6, screen, npc->x, npc->y);
	}
      npc = npc->next;
    }
}
