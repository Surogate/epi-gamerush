/*
** menu_exec for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 28 03:08:12 2010 francois1 ancel
** Last update Sun Mar 28 03:08:12 2010 francois1 ancel
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<stdio.h>

#include		"define.h"

int			menu_up(int *i)
{
  *i = *i - 1;
  if (*i < 0)
    *i = 5;
  return (1);
}

int			menu_down(int *i)
{
  *i = (*i + 1) % 6;
  return (1);
}

int			menu_return(int *i, char **ret)
{
  static char		*tab[] = {
    MAP1_DIR,
    MAP2_DIR,
    MAP3_DIR,
    MAP4_DIR,
    MAP5_DIR,
    (char *)-1
  };

  *ret = tab[*i];
  return (0);
}

int			menu_exit(int *i, char **ret)
{
  *i = 0;
  *ret = (char *)-1;
  return (0);
}
