/*
** main.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:22:18 2017 miguel joubert
** Last update Thu Feb  9 14:21:33 2017 miguel joubert
*/

#include "../include/my.h"

t_map	map_aftchd(t_map M, t_elem E, char *str, int cond)
{
  if (cond == 2)
    {
      //      printf("%c%d\n", E.s[0], E.s[1] - 48);
      //printf("%c%d: %s\n", E.s[0], E.s[1] - 48, str);
      write(1, &(E.s[0]), 1);
      write(1, &(E.s[1]), 1);
      write(1, ": ", 2);
      puts(str);
      if (is_played(E.my_stock) == 0)
	M.map_adv = (strcmp(str, "hit") == 0) ?
	  my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'x') :
	  my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'o');
    }
  else
    {
      char c = E.a + 64;
      write(1, &c, 1);
      c = E.b + 48;
      write(1, &c, 1);
      write(1, ": ", 2);
      puts(str);
      write(1, "\n", 1);
      //      printf("%c%d: %s\n\n", E.a + 64, E.b, str);
      if (is_played(E.adv_stock) == 0)
	M.my_map = (cond == 1 && is_played(E.my_stock) == 0)
	  ? my_position_init(M.my_map, convert_co_int(E.a, E.b), 'x')
	  : my_position_init(M.my_map, convert_co_int(E.a, E.b), 'o');
      send_bit(cond, E.pid);
    }
  return (M);
}

int	host(t_elem E, t_map M)
{
  while (E.loose != 1 && E.win != 1)
    {
      my_putstr("\nattack: ", 1);
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E.s = pars_case(E.s);
      if (E.s != NULL) E.my_stock[E.j] = strdup(E.s);
      if (E.s != NULL) E.my_stock[E.j + 1] = NULL;
      if (E.s != NULL) send_bit(E.s[0] - 64, E.pid);

      if (E.s != NULL) send_bit(E.s[1] - 48, E.pid);

      E.answer = receive_bit(E.pid);
      if (E.answer == 1 && is_played(E.my_stock) == 0) M = map_aftchd(M, E, strdup("hit"), 2), E.win--;
      else if (E.answer == 0 || is_played(E.my_stock) == 1) M = map_aftchd(M, E, strdup("missed"), 2);
      write(1, "\nwaiting for enemy's attack...\n", strlen("\nwaiting for enemy's attack...\n"));
      E.a = receive_bit(E.pid);
      E.b = receive_bit(E.pid);
      //      usleep(10000);
      E.adv_stock[E.j] = malloc(sizeof(char) * 3);
      *E.adv_stock[E.j] = E.a - 64;
      E.adv_stock[E.j][1] = E.b - 48;
      E.adv_stock[E.j][2] = 0;
      E.adv_stock[++E.j] = NULL;
      if (is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL && is_played(E.adv_stock) == 0)
	M = map_aftchd(M, E, strdup("hit"), 1), E.loose--;
      else M = map_aftchd(M, E, strdup("missed"), 0);
      write(1, "my positions:\n", strlen("my positions:\n"));
      my_disp_map(M.my_map);
      write(1, "\nenemy's positions:\n", strlen("\nenemy's positions:\n"));
      my_disp_map(M.map_adv);
      E.answer = -1;
      free(E.s);
    }
  (E.loose == 1) ? write(1, "\nEnemy won\n", strlen("\nEnemy won\n")) : write(1, "\nI won\n", strlen("\nI won\n"));
  return ((E.loose == 1) ? 1 : 0);
}

int	client(t_elem E, t_map M)
{
  while (E.loose != 1 && E.win != 1)
    {
      write(1, "\nwaiting for enemy's attack...\n", strlen("\nwaiting for enemy's attack...\n"));
      E.a = receive_bit(E.pid);
      //usleep(1000);
      E.b = receive_bit(E.pid);
      //usleep(1000);
      E.adv_stock[E.j] = malloc(sizeof(char) * 3);
      *E.adv_stock[E.j] = E.a + 64;
      E.adv_stock[E.j][1] = E.b + 48;
      E.adv_stock[E.j][2] = 0;
      E.adv_stock[E.j + 1] = NULL;
      //usleep(1000);
      if (is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL && is_played(E.adv_stock) == 0)
	M = map_aftchd(M, E, strdup("hit"), 1), E.loose--;
      else M = map_aftchd(M, E, "missed", 0);
      if (E.win == 0) return (0);
      write(1, "attack: ", strlen("attack: "));
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E.s = pars_case(E.s);
      if (E.s != NULL) E.my_stock[E.j] = strdup(E.s);
      if (E.s != NULL) E.my_stock[++E.j] = NULL;
      if (E.s != NULL) send_bit(E.s[0] - 64, E.pid);

      if (E.s != NULL) send_bit(E.s[1] - 48, E.pid);

      E.answer = receive_bit(E.pid);
      if (E.answer == 1 && is_played(E.my_stock) == 0) M = map_aftchd(M, E, strdup("hit"), 2), E.win--;
      else if (E.answer == 0 || is_played(E.my_stock) == 1) M = map_aftchd(M, E, strdup("missed"), 2);
      write(1, "\nmy positions:\n", strlen("\nmy positions:\n"));
      my_disp_map(M.my_map);
      write(1, "\nenemy's positions:\n", strlen("\nenemy's positions:\n"));
      my_disp_map(M.map_adv);
      E.answer = -1;
      free(E.s);
    }
  (E.loose == 1) ? write(1, "\nEnemy won\n", strlen("\nEnemy won\n")) : write(1, "\nI won\n", strlen("\nI won\n"));
  return ((E.loose == 1) ? 1 : 0);
}

int	main(int ac, char **av)
{
  t_elem	E;
  static t_map	M;

  if (strcmp(av[1], "-h") == 0) return (help());
  E = init_buff(E, ac, av);
  if (verify_length(E.buff) == 1) return (84);
  E.buff = pars_map(E.buff);
  if (verify_pos(E.buff) == 1) return (84);
  if (verify_hit(E.buff) == 1) return (84);
  E = init_elem(E, ac, av);
  M = init_map(M, E);
  if (E.i == 1) return (host(E, M));
  if (E.i == 2)
    if (client(E, M) == 1)
      return (1);
  return (0);
}
