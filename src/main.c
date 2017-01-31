/*
** main.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:22:18 2017 miguel joubert
** Last update Tue Jan 31 02:18:07 2017 miguel joubert
*/

#include "../include/my.h"

int	main(int ac, char **av)
{
  int   fd;
  char  *buff;
  char	*s;
  static char	**map_adv;
  static char	**my_map;

  map_adv = my_init_map();
  printf("adv map:\n");
  my_disp_map(map_adv);
  fd = open(av[1], O_RDONLY);
  buff = malloc(sizeof(char) * 32);
  read(fd, buff, 32);
  my_map = my_position(buff);
  printf("my map:\n");
  my_disp_map(my_map);
  if (ac < 2)
    return (1);
  if (strcmp(av[1], "-h") == 0)
    {
      my_putstr("USAGE\n", 1);
      my_putstr("           ./navy [fistr_player_pid] navy_positions\n", 1);
      my_putstr("DESCRIPTION\n", 1);
      my_putstr("           first_player_pid   only for the 2nd player.  pid of\
 the first player,\n           navy_positions     file representing the positi\
ons of the ships.\n", 1); 
      return (0);
    }
  verify_pos(buff);
  verify_hit(buff);
  while ((s = get_next_line(0)))
    {
      my_map = is_touched(my_map, convert_co_char(s), 'x');
      my_disp_map(map_adv);
      my_disp_map(my_map);
    }
  return (0);
}
