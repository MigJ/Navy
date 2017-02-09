/*
** init.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 19:49:12 2017 miguel joubert
** Last update Thu Feb  9 15:58:18 2017 miguel joubert
*/

#include "../include/my.h"

int	client_init(int pid_server)
{
  int   pid;

  usleep(1000);
  pid = getpid();
  signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  write(1, "my_pid : ", strlen("my_pid : "));
  my_put_nbr(pid);
  write(1, "\n", 1);
  kill(pid_server, SIGUSR1);
  pause();
  write(1, "successfully connected\n\n", strlen("successfully connected\n\n"));
  //send_bit(44, pid_server);
  return (pid_server);
}

int	server_init()
{
  pid_t pid_client;
  pid_t pid_server;

  pid_server = getpid();
  write(1, "my_pid : ", strlen("my_pid : "));
  my_put_nbr(pid_server);
  write(1, "\n", 1);
  write(1, "waiting for enemy connection...\n", strlen("waiting for enemy connection...\n"));
  pid_client = get_pidclient();
  kill(pid_client, SIGUSR1);
  write(1, "enemy connected\n\n", strlen("enemy connected\n\n"));
  signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  //  if (receive_bit(pid_client) != 44)
  //   exit (84);
  return (pid_client);
}

t_elem	init_buff(t_elem E, int ac, char **av)
{
  E.i = (ac == 2) ? 1 : 2;
  if (E.i == 1) E.fd = open(av[1], O_RDONLY);
  else E.fd = open(av[2], O_RDONLY);
  E.buff = malloc(sizeof(char) * 32);
  read(E.fd, E.buff, 32);
  E.buff[31] = 0;
  return (E);
}

t_elem	init_elem(t_elem E, int ac, char **av)
{
  E.pid = (ac == 2) ? server_init() : client_init(my_getnbr(av[1]));
  E.my_stock = malloc(sizeof(char *) * 100);
  E.adv_stock = malloc(sizeof(char *) * 100);
  E.win = E.loose = 15;
  E.j = 0;
  return (E);
}

t_map	init_map(t_map M, t_elem E)
{
  M.map_adv = my_init_map();
  M.my_map = my_position(E.buff);
  write(1, "my positions:\n", strlen("my positions:\n"));
  my_disp_map(M.my_map);
  write(1, "\nenemy's positions:\n", strlen("\nenemy's positions:\n"));
  my_disp_map(M.map_adv);
  return (M);
}
