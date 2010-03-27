#ifndef			__MAP_H__
# define		__MAP_H__

# define MONSTER_CHAR	'm'
# define LADDER_CHAR	's'
# define WALL_CHAR	'w'
# define ENTER_CHAR	'i'
# define EXIT_CHAR	'o'
# define EMPTY_CHAR	'.'

typedef struct		s_map
{
  char			**map;
  int			width;
  int			height;
}			t_map;

t_map			*get_map(char *path);

#endif			/* __MAP_H__ */
