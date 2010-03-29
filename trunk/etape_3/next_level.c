/*
** next_level.c for epikong
**
** Made by quentin muller
** Login   <muller_b@epitech.net>
**
** Started on  Wed Mar  3 11:45:11 2010 quentin muller
** Last update Sun Mar 14 18:30:19 2010 quentin muller
*/

#include		<string.h>

#include		"define.h"

char			*get_level_name(int i)
{
 static char		*tab[] = {
    MAP1_DIR,
    MAP2_DIR,
    MAP3_DIR,
    MAP4_DIR,
    MAP5_DIR,
    (char *)-1
  };

 return (tab[i]);
}

int			get_level_num(char *map)
{
  static char		*tab[] = {
    MAP1_DIR,
    MAP2_DIR,
    MAP3_DIR,
    MAP4_DIR,
    MAP5_DIR,
    (char *)-1
  };
  int			level;

  level = 0;
  if (map == NULL)
    return (-1);
  while (level < 5)
    {
      if (strcmp(map, tab[level]) == 0)
	break;
      level++;
    }
  return (level);
}

void			get_next_level(char **map, int *finished)
{
  static int		levels[] = {0, 0, 0, 0, 0};
  int			level_num;
  int			i;

  if ((level_num = get_level_num(*map)) != -1)
    {
      levels[level_num] = 1;
      if (level_num == 4)
	*map = NULL;
      else
	*map = get_level_name(level_num + 1);
      i = 0;
      *finished = 1;
      while (i < 5)
	{
	  if (levels[i] == 0)
	    *finished = 0;
	  i++;
	}
    }
}
