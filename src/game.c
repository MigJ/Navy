/*
** main.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:22:18 2017 miguel joubert
** Last update Wed Feb  1 22:29:02 2017 miguel joubert
*/

#include "include/my.h"
#include "include/libs.h"
#include "include/proto.h"

t_map   map_aftchd(t_map M, t_elem E, char *str, int cond)
{
  if (cond == 2)
    {
      my_printf("%c%d: %s\n", E.s[0], E.s[1] - 48, str);
      M.map_adv = (strcmp(str, "hit") == 0) ?
	my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'x') :
	my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'o');
    }
  else
    {
      my_printf("%c%d: %s\n", E.a + 64, E.b, str);
      (cond == 1) ? M.my_map = is_touched(M.my_map, convert_co_int(E.a, E.b)) : 0;
      send_bit(cond, E.pid);
    }
  return (M);
}

void	host(t_elem E, t_map M)
{
  while (E.win != 0)
    {
      my_printf("attack:  ");
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E.s = pars_case(E.s);
      send_bit(E.s[0] - 64, E.pid);
      send_bit(E.s[1] - 48, E.pid);
      E.answer = receive_bit(E.pid);
      if (E.answer == 1) M = map_aftchd(M, E, "hit", 2);
      else if (E.answer == 0) M = map_aftchd(M, E, "missed", 2);
      my_printf("\nwaiting for enemy's attack...\n\n");
      E.a = receive_bit(E.pid);
      E.b = receive_bit(E.pid);
      printf("Recu %d %d\n", E.a, E.b);
      usleep(10000);
      if ((is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL))
	M = map_aftchd(M, E, "hit", 1), E.win--;
      else M = map_aftchd(M, E, "missed", 0);
      my_disp_map(M.map_adv);
      my_disp_map(M.my_map);
      E.answer = -1;
      printf("Vie restante : %d\n", E.win);
    }
}

int 	client(t_elem E, t_map M)
{
  while (E.win != 0)
    {
      my_printf("\nwaiting for enemy's attack...\n\n");
      E.a = receive_bit(E.pid) ;
      E.b = receive_bit(E.pid) ;
      printf("Recu %d %d\n", E.a, E.b);
      usleep(10000);
      if ((is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL))
	M = map_aftchd(M, E, "hit", 1), E.win--;
      else M = map_aftchd(M, E, "missed", 0);
      if (E.win == 0) return (0);
      my_printf("attack:  ");
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E.s = pars_case(E.s);
      send_bit(E.s[0] - 64, E.pid);
      send_bit(E.s[1] - 48, E.pid);
      E.answer = receive_bit(E.pid);
      if (E.answer == 1) M = map_aftchd(M, E, "hit", 2);
      else if (E.answer == 0) M = map_aftchd(M, E, "missed", 2);
      my_disp_map(M.map_adv);
      my_disp_map(M.my_map);
      E.answer = -1;
      printf("Vie restante : %d\n", E.win);
    }
  return (1);
}

int	main(int ac, char **av)
{
  t_elem	E;
  static t_map	M;

  if (strcmp(av[1], "-h") == 0) return (help());
  E = init_elem(ac, av, E);
  M = init_map(M, E);
  if (verify_pos(E.buff) == 1) return (1);
  else if (verify_hit(E.buff) == 1) return (1);
  else if (strcmp(av[1], "-h") == 0) return (help());
  else if (E.i == 1) host(E, M);
  else if (E.i == 2)
    {
      if (client(E, M) == 0)
	{
	  printf("You Loose\n");
	  return (0);
	}
    }
  return (0);
}
