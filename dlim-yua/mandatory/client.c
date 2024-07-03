/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:04:37 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 18:04:39 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;

	if (argc != 3)
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		transfer_bits(pid, (unsigned char)(argv[2][i]));
		i++;
	}
	return (0);
}
