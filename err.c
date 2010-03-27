/*
** err.c for epikong in ~
**
** Made by quentin muller
** Login   <muller_b@epitech.net>
**
** Started on  Sun Mar 14 13:16:11 2010 quentin muller
** Last update Sun Mar 14 18:31:17 2010 quentin muller
*/

#include		<errno.h>
#include		<SDL/SDL.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>

void			err_SDL(char *str, char quit)
{
  fprintf(stderr, "SDL Error: %s - %s\n", str, SDL_GetError());
  if (quit)
    exit(EXIT_FAILURE);
  else
    return ;
}

void			err(char *str, char quit)
{
  fprintf(stderr, "Error: %s - %s\n", str, strerror(errno));
  if (quit)
    exit(EXIT_FAILURE);
  else
    return ;
}

void			err_inside(char *str, char quit)
{
  fprintf(stderr, "Error: %s\n", str);
  if (quit)
    exit(EXIT_FAILURE);
  else
    return ;
}

void			putstr(char *str)
{
  write(1, str, strlen(str));
}
