/*
** map.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:16:19 2010 francois1 ancel
** Last update Fri Mar 26 22:16:19 2010 francois1 ancel
*/

#ifndef			__MAP_H__
# define		__MAP_H__

# define MONSTER_CHAR	'm'
# define LADDER_CHAR	's'
# define WALL_CHAR	'w'
# define ENTER_CHAR	'i'
# define EXIT_CHAR	'o'
# define EMPTY_CHAR	'.'
# define KEY_CHAR	'k'
# define BLOOD_CHAR	'b'
# define LIFE_CHAR	'l'
# define GUN_CHAR	'g'
# define BOSS_CHAR	'M'

typedef struct		s_map
{
  char			**map;
  int			width;
  int			height;
  t_boss		boss;
}			t_map;

t_map			*get_map(char *path);
t_map			*check_map(t_map *map);
void			get_next_level(char **map, int *finished);

#endif			/* __MAP_H__ */
