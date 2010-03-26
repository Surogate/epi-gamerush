#ifndef			__MAP_H__
# define		__MAP_H__

typedef struct	s_map
{
  char		**map;
  int		width;
  int		height;
}		t_map;

t_map		*get_map(char *path);

#endif			/* __MAP_H__ */
