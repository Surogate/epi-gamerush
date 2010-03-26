/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 20:37:35 2010 francois1 ancel
** Last update Fri Mar 26 20:37:35 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

int main(int ac, char **av)
{
  int result;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      perror("SDL init fail");
      return (EXIT_FAILURE);
    }
  result = exec_fct();
  if (result == EXIT_FAILURE)
    perror("exec_fct");
  SDL_Quit();
  return (result);
}
