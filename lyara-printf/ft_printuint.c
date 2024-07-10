/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:40:20 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/09 11:49:41 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sft_nlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0 && ++len)
		n = n / 10;
	return (len);
}

/**
 * @brief		Writes ascii rep of int to stdoutput
 * 
 * @param n		Number to be formatted		
 * @return		N length of char printed
*/
int	ft_printuint(unsigned int n)
{
	unsigned int	len;

	len = sft_nlen(n);
	if (n >= 10)
	{
		ft_printuint(n / 10);
		ft_printuint(n % 10);
	}
	if (n < 10)
		ft_printchar(n + '0');
	if (n == 0)
		return (1);
	return (len);
}
