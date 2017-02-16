/*
** init.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 19:49:12 2017 miguel joubert
** Last update Thu Feb 16 22:23:39 2017 Joubert Miguel
*/

#include "../include/my.h"

int	client_init(int pid_server)
{
  int   pid;

  pid = getpid();
  signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  my_putstr("my_pid : ", 1);
  my_put_nbr(pid);
  my_putstr("\n", 1);
  kill(pid_server, SIGUSR1);
  pause();
  my_putstr("successfully connected\n\n", 1);
  return (pid_server);
}

int	server_init()
{
  pid_t pid_client;
  pid_t pid_server;

  pid_server = getpid();
  my_putstr("my_pid : ", 1);
  my_put_nbr(pid_server);
  my_putstr("\n", 1);
  my_putstr("waiting for enemy connection...\n", 1);
  pid_client = get_pidclient();
  kill(pid_client, SIGUSR1);
  my_putstr("enemy connected\n\n", 1);
  signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  return (pid_client);
}

t_elem	init_buff(t_elem E, int ac, char **av)
{
  E.i = (ac == 2) ? 1 : 2;
  if (E.i == 1) E.fd = open(av[1], O_RDONLY);
  else E.fd = open(av[2], O_RDONLY);
  if ((E.buff = malloc(sizeof(char) * 32)) == NULL)
    return (E);
  read(E.fd, E.buff, 32);
  E.buff[31] = 0;
  return (E);
}

t_elem	init_elem(t_elem E, int ac, char **av)
{
  E.pid = (ac == 2) ? server_init() : client_init(my_getnbr(av[1]));
  if ((E.my_stock = malloc(sizeof(char *) * 100)) == NULL)
    return (E);
  if ((E.adv_stock = malloc(sizeof(char *) * 100)) == NULL)
    return (E);
  E.win = E.loose = 15;
  E.j = 0;
  E.k = 0;
  return (E);
}

t_map	init_map(t_map M, t_elem E)
{
  M.map_adv = my_init_map();
  M.my_map = my_position(E.buff);
  my_disp_map(M.my_map, "my_map");
  my_disp_map(M.map_adv, "map_adv");
  return (M);
}
