/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:21:18 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/04 10:00:55 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sft_nlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0 && ++len)
		n /= 16;
	return (len);
}

/**
 * @brief		Writes hex rep of pointer value
 * 
 * @param n		Number to be formatted
 * @param x		Char to determine lowercase or uppercase
 * @return		N length of char printed
*/
int	ft_printhex(unsigned int n, char x)
{
	const char		*hex;
	unsigned int	len;

	if (x == 'X')
		hex = "0123456789ABCDEF";
	else if (x == 'x')
		hex = "0123456789abcdef";
	len = sft_nlen(n);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n >= 16)
		ft_printhex((n / 16), x);
	write(1, &hex[n % 16], 1);
	return (len);
}

/*
	DEBUG :
	1. const char *hex instead of hex[]
		- WHY?
		- 	with a pointer, we can simply assign string literal to pointer
			and it will point to the memory location the string literal
			// "Give me a pointer that can point to some characters,
				and I'll tell you what characters later."
		-	if declare array, they cant be reassigned, cant change contents
			// "Set aside space in memory for some characters,
				and tell me what characters right now."

	2. FT_PRINTHEX
		- included check if (n == 0)
		- WHY? so it knows to write 0 if n == 0
		- otherwise it will not print anything
		- sft returns 1, printhex returns 0 > infinite loop
		- thus check > writes 0 and returns 1, fx terminates
*/
