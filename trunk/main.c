/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:37:35 2010 francois1 ancel
** Last update Fri Mar 26 20:37:35 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	"t_image.h"
#include	"err.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"define.h"
#include	"windows.h"

int		main()
{
  /*  result = EXIT_SUCCESS;
  if (ac > 1)
    result = exec_map(av[1]);
  else
    printf("Usage : ./prog [map/?.map]\n");
    return (result);*/
  exec_menu();
  return (EXIT_SUCCESS);
}
