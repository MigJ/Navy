/*
** main.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:22:18 2017 miguel joubert
** Last update Sun Feb 19 21:01:00 2017 Joubert Miguel
*/

#include "../include/my.h"

t_map	map_aftchd(t_map M, t_elem E, char *str, int cond)
{
  char *c;

  if ((c = malloc(sizeof(char) * 3)) == NULL) return (M);
  if (cond == 2)
    {
      my_putstr(my_strcat(my_strcat(E.s, ": "), str), 1);
      if (is_played(E.my_stock) == 0)
	M.map_adv = (my_strcmp(str, "hit") == 0) ?
  my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'x') :
  my_position_init(M.map_adv, convert_co_int(E.s[0] - 64, E.s[1] - 48), 'o');
    }
  else
    {
      *c = E.a + 64;
      c[1] = E.b + 48;
      c[2] = 0;
      my_putstr(my_strcat(my_strcat(c, ": "), my_strcat(str, "\n")), 1);
      if (is_played(E.adv_stock) == 0)
	M.my_map = (cond == 1)
	  ? my_position_init(M.my_map, convert_co_int(E.a, E.b), 'x')
	  : my_position_init(M.my_map, convert_co_int(E.a, E.b), 'o');
      send_bit(cond, E.pid);
    }
  return (M);
}

t_elem	assign_values(t_elem E, int cond)
{
  if (cond == 0 && E.s != NULL)
    {
      E.s = pars_case(E.s);
      if ((E.my_stock[E.k] = malloc(sizeof(char) * 3)) == NULL)
	return (E);
      E.my_stock[E.k] = my_strdup(E.s);
      E.my_stock[++E.k] = NULL;
      send_bit(E.s[0] - 64, E.pid);
      send_bit(E.s[1] - 48, E.pid);
    }
  else if (cond == 1)
    {
      E.a = receive_bit(E.pid);
      E.b = receive_bit(E.pid);
      if ((E.adv_stock[E.j] = malloc(sizeof(char) * 3)) == NULL)
	return (E);
      *E.adv_stock[E.j] = E.a + 64;
      E.adv_stock[E.j][1] = E.b + 48;
      E.adv_stock[E.j][2] = 0;
      E.adv_stock[++E.j] = NULL;
    }
  return (E);
}

int	host(t_elem E, t_map M)
{
  while (E.loose != 1 && E.win != 1)
    {
      my_putstr("\nattack: ", 1);
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E = assign_values(E, 0);
      E.answer = receive_bit(E.pid);
      if (E.answer == 1 && is_played(E.my_stock) == 0)
	M = map_aftchd(M, E, my_strdup("hit"), 2), E.win--;
      else if (E.answer == 0 || is_played(E.my_stock) == 1)
	M = map_aftchd(M, E, my_strdup("missed"), 2);
      if (E.win == 1) break;
      if (is_played(E.my_stock)==1) MY= double_case(E.my_stock, E.k--);
      my_putstr("\nwaiting for enemy's attack...\n", 1);
      E = assign_values(E, 1);
      if (is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL
	  && is_played(E.adv_stock) == 0)
	M = map_aftchd(M, E, my_strdup("hit"), 1), E.loose--;
      else M = map_aftchd(M, E, my_strdup("missed"), 0);
      if (E.loose == 1) break;
      if (is_played(E.adv_stock)==1) ADV=double_case(E.adv_stock, E.j--);
      E.answer = disp_all_map(M.my_map, M.map_adv);
      free(E.s);
    }
  (E.win == 1) ? my_putstr("\nI won\n", 1) : my_putstr("\nEnemy won\n", 1);
  return ((E.loose == 1) ? 1 : 0);
}

int	client(t_elem E, t_map M)
{
  while (E.loose != 1 && E.win != 1)
    {
      my_putstr("\nwaiting for enemy's attack...\n", 1);
      E = assign_values(E, 1);
      if (is_touched(M.my_map, convert_co_int(E.a, E.b)) != NULL
	  && is_played(E.adv_stock) == 0)
	M = map_aftchd(M, E, my_strdup("hit"), 1), E.loose--;
      else M = map_aftchd(M, E, "missed", 0);
      if (E.loose == 1) break;
      if (is_played(E.adv_stock)==1) ADV=double_case(E.adv_stock, E.j--);
      my_putstr("attack: ", 1);
      while ((E.s = get_next_line(0)) && verify_exist(E.s) == 1);
      E = assign_values(E, 0);
      E.answer = receive_bit(E.pid);
      if (E.answer == 1 && is_played(E.my_stock) == 0)
	M = map_aftchd(M, E, my_strdup("hit"), 2), E.win--;
      else if (E.answer == 0 || is_played(E.my_stock) == 1)
	M = map_aftchd(M, E, my_strdup("missed"), 2);
      if (E.win == 1) break;
      if (is_played(E.my_stock)==1) MY = double_case(E.my_stock, E.k--);
      E.answer = disp_all_map(M.my_map, M.map_adv);
      free(E.s);
    }
  (E.loose == 1) ? my_putstr("\nEnemy won\n", 1) : my_putstr("\nI won\n", 1);
  return ((E.loose == 1) ? 1 : 0);
}

int	main(int ac, char **av)
{
  t_elem	E;
  static t_map	M;

  if (ac < 2)
    return (84);
  if (my_strcmp(av[1], "-h") == 0) return (help());
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
