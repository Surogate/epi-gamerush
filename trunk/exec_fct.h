/*
** exec_fct.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 21:03:43 2010 francois1 ancel
** Last update Fri Mar 26 21:03:43 2010 francois1 ancel
*/

#ifndef EXEC_FCT_C_INCLUDED
# define EXEC_FCT_C_INCLUDED

typedef struct	s_func
{
  Uint8		type;
  int		(*func)();
}		t_func;
int exec_fct();

#endif
