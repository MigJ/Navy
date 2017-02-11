/*
** main.c for navy in /home/nathan.trehout/delivery/PSU_2016_navy/src
** 
** Made by Nathan Trehout
** Login   <nathan.trehout@epitech.net>
** 
** Started on  Tue Jan 31 03:42:42 2017 Nathan Trehout
** Last update Sat Feb 11 17:52:43 2017 miguel joubert
*/

#include "../include/my.h"

static int	sig_detected = -1;

void	sig_handler(int	sig)
{
  if (sig == SIGUSR1)
    sig_detected = 0;
  else if (sig == SIGUSR2)
    sig_detected = 1;
}

void	handle_signal(int sig, siginfo_t *si, void *context)
{
  (void) context;
  if (sig == SIGUSR1)
    sig_detected = si->si_pid;
  else if (sig == SIGUSR2)
    sig_detected = 1;
}

int	get_pidclient()
{
  int	pid;
  struct sigaction s_val;

  sigemptyset(&s_val.sa_mask);
  sigaddset(&s_val.sa_mask, SIGINT);
  s_val.sa_flags = SA_SIGINFO;
  s_val.sa_sigaction = handle_signal;
  sigaction(SIGUSR1, &s_val, NULL);
  sigaction(SIGUSR2, &s_val, NULL);
  while (sig_detected == -1);
  pid = sig_detected;
  sig_detected = -1;
  return (pid);
}

unsigned int	receive_bit(pid_t pid_client)
{
  int	i;
  unsigned int	nb;

  i = nb = 0;
  while (i < 32)
    {
      nb <<= 1;
      pause();
      usleep(2000);
      while (kill(pid_client, SIGUSR1) != 0);
      if (sig_detected == 0)
	nb += 0;
      else if (sig_detected == 1)
	nb += 1;
      sig_detected = -1;
      i++;
    }
  return (nb);
}

void	send_bit(unsigned int	nb, int pid_server)
{
  int	i;

  i = 0;
  nb = ((nb >> 1) & 0x55555555u) | ((nb & 0x55555555u) << 1);
  nb = ((nb >> 2) & 0x33333333u) | ((nb & 0x33333333u) << 2);
  nb = ((nb >> 4) & 0x0f0f0f0fu) | ((nb & 0x0f0f0f0fu) << 4);
  nb = ((nb >> 8) & 0x00ff00ffu) | ((nb & 0x00ff00ffu) << 8);
  nb = ((nb >> 16) & 0xffffu) | ((nb & 0xffffu) << 16);
  while (i < 32)
    {
      usleep(2000);
      if (nb % 2 == 0)
	while (kill(pid_server, SIGUSR1) != 0);
      else
	while (kill(pid_server, SIGUSR2) != 0);
      pause();
      sig_detected = 0;
      i++;
      nb >>= 1;
    }
}
