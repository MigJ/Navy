/*
** main.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:22:18 2017 miguel joubert
** Last update Mon Feb  6 01:18:33 2017 miguel joubert
*/

#include "include/my.h"
#include "include/libs.h"
#include "include/proto.h"

t_map	map_aftchd(t_map M, t_elem E, char *str, int cond)
{
  if (cond == 2)
    {
      printf("\e[3m%c%d\n\e[0m", E.s[0], E.s[1] - 48);
      printf("%c%d: %s\n", E.s[0], E.s[1] - 48, str);
      M.map_adv = (strcmp(str, "hit") == 0) ?
	my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'x') :
	my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'o');
    }
  else
    {
      printf("%c%d: %s\n\n", E.a + 64, E.b, str);
      M.my_map = (cond == 1) ? my_position_init(M.my_map, convert_co_int(E.a, E.b), 'x')
	: my_position_init(M.my_map, convert_co_int(E.a, E.b), 'o');
      send_bit(cond, E.pid);
    }
  return (M);
}
int	host(t_elem E, t_map M)
{
  while (E.loose != 1 && E.win != 1)
    {
      my_printf("\nattack: ");
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E.s = pars_case(E.s);
      if (E.s != NULL) send_bit(E.s[0] - 64, E.pid);
      if (E.s != NULL) send_bit(E.s[1] - 48, E.pid);
      E.answer = receive_bit(E.pid);
      if (E.answer == 1) M = map_aftchd(M, E, strdup("hit"), 2), E.win--;
      else if (E.answer == 0) M = map_aftchd(M, E, strdup("missed"), 2);
      my_printf("\nwaiting for enemy's attack...\n");
      E.a = receive_bit(E.pid);
      E.b = receive_bit(E.pid);
      usleep(10000);
      if ((is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL))
	M = map_aftchd(M, E, strdup("hit"), 1), E.loose--;
      else M = map_aftchd(M, E, strdup("missed"), 0);
      printf("my positions:\n");
      my_disp_map(M.my_map);
      printf("\nenemy's positions:\n");
      my_disp_map(M.map_adv);
      E.answer = -1;
      free(E.s);
    }
  (E.loose == 1) ? printf("\nEnemy won\n") : printf("\nI won\n");
  return ((E.loose == 1) ? 1 : 0);
}

int	client(t_elem E, t_map M)
{
  while (E.loose != 1 && E.win != 1)
    {
      my_printf("\nwaiting for enemy's attack...\n");
      E.a = receive_bit(E.pid) ;
      E.b = receive_bit(E.pid) ;
      usleep(10000);
      if ((is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL))
	M = map_aftchd(M, E, strdup("hit"), 1), E.loose--;
      else M = map_aftchd(M, E, "missed", 0);
      if (E.win == 0) return (0);
      my_printf("attack: ");
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E.s = pars_case(E.s);
      if (E.s != NULL) send_bit(E.s[0] - 64, E.pid);
      if (E.s != NULL) send_bit(E.s[1] - 48, E.pid);
      E.answer = receive_bit(E.pid);
      if (E.answer == 1) M = map_aftchd(M, E, strdup("hit"), 2), E.win--;
      else if (E.answer == 0) M = map_aftchd(M, E, strdup("missed"), 2);
      printf("\nmy positions:\n");
      my_disp_map(M.my_map);
      printf("\nenemy's positions:\n");
      my_disp_map(M.map_adv);
      E.answer = -1;
      free(E.s);
    }
  (E.loose == 1) ? printf("\nEnemy won\n") : printf("\nI won\n");
  return ((E.loose == 1) ? 1 : 0);
}

int	main(int ac, char **av)
{
  t_elem	E;
  static t_map	M;

  if (strcmp(av[1], "-h") == 0) return (help());
  E = init_elem(ac, av, E);
  M = init_map(M, E);
  if (verify_pos(E.buff) == 1) return (84);
  else if (verify_hit(E.buff) == 1) return (84);
  else if (E.i == 1) return (host(E, M));
  else if (E.i == 2)
    if (client(E, M) == 1)
      return (1);
  return (0);
}
