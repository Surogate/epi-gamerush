/*
** err.c for epikong in ~
**
** Made by quentin muller
** Login   <muller_b@epitech.net>
**
** Started on  Sun Mar 14 13:16:11 2010 quentin muller
** Last update Sun Mar 14 18:31:17 2010 quentin muller
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void			err(char *str, char quit)
{
  fprintf(stderr, "Error: %s - %s\n", str, strerror(errno));
  if (quit)
    exit(EXIT_FAILURE);
  else
    return ;
}
