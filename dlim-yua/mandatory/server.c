/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:04:58 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 18:04:59 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int sig, siginfo_t *in, void *c)
{
	static unsigned char	bit[2];

	(void)in;
	(void)c;
	if (!bit[1])
		bit[1] = '0';
	bit[0] |= (sig == SIGUSR1);
	bit[1]++;
	if (bit[1] == '8')
	{
		ft_printf("%c", bit[0]);
		bit[1] = '0';
		bit[0] = 0;
	}
	else
		bit[0] <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %i\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
