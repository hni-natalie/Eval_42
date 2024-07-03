/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:05:36 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 18:05:43 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	transfer_bits(int pid, unsigned char ch)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = ch;
	while (i > 0)
	{
		i--;
		tmp = ch >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

void	signal_handler(int sig, siginfo_t *in, void *c)
{
	(void)sig;
	(void)in;
	(void)c;
	if (sig == SIGUSR1)
		ft_printf("PID (%i) RECEIVED STRING!\n", in->si_pid);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	i = 0;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	while (argv[2][i])
	{
		transfer_bits(pid, (unsigned char)(argv[2][i]));
		i++;
	}
	transfer_bits(pid, (unsigned char)('\0'));
	while (1)
		pause();
	return (0);
}
