/*
** struct.h for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:01:49 2017 miguel joubert
** Last update Mon Feb  6 11:11:04 2017 miguel joubert
*/

#ifndef _STRUCT_H
#define _STRUCT_H

typedef struct s_hit
{
  char  **all_case;
  int   i;
  int   tmp;
  int   j;
  int   k;
  int   pos;
  int    bol;
}t_hit;

typedef struct s_vector
{
  int	x;
  int	y;
}t_vector;

typedef struct s_elem
{
  int   fd;
  int   pid;
  char  *buff;
  int   i;
  int	j;
  char  *s;
  char	**my_stock;
  char	**adv_stock;
  int	loose;
  int	win;
  int	a;
  int	b;
  int	answer;
}t_elem;

typedef struct s_map
{
  char   **map_adv;
  char   **my_map;
}t_map;

typedef struct s_touch
{
  char  **dest;
  int   i;
  int   j;
  int   k;
}t_touch;

#endif /* _STRUCT_H */
