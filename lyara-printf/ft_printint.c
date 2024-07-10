/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:05:06 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/04 11:01:15 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sft_nlen(int n)
{
	int	len;

	len = 0;
	if (n < 0 && ++len)
		n = -n;
	while (n > 0 && ++len)
		n /= 10;
	return (len);
}

/**
 * @brief		Writes ascii rep for int param
 * 
 * @param n		Number to be formatted
 * @return		N length of char printed
*/
int	ft_printint(int n)
{
	int	len;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	len = sft_nlen(n);
	if (n < 0)
	{
		ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_printint(n / 10);
		ft_printint(n % 10);
	}
	else
		ft_printchar(n + '0');
	if (n == 0)
		return (1);
	return (len);
}

/*
	DEBUG :
	1. Only check (n == 0) at the end, because it needs to print '0'
		- ensures fx prints char '0' and returns correct lenght of 1 afterwards
	2. If (n == 0), return (1) before (n < 0)
		- fx wont print '0' and return (1) will exit fx immediately
	3. Checking (n == 0) in the beginning is possible, but need to repeat command
		fx to printchar which is redundant
*/