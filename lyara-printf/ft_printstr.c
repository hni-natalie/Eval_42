/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:57:32 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/03 10:17:25 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief		Writes a string to stdoutput
 * 
 * @param s		String to iterate
 * @return		N length of char printed
*/
int	ft_printstr(char *s)
{
	int	len;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (*s && ++len)
		write(1, s++, 1);
	return (len);
}

/*
	DEBUG : 
	1. ALWAYS CHECK FOR NULL
	2. return (null) instead of NULL because
		- 	NULL is a pointer constant / not a valid string
		- 	when you want to print a string that represents null pointer,
			you need to use string literal like (null)

	LOGIC :
	1. Declare and initialize len
	2. Iterate string, write & move (pointer) string, increment count
	3. Return len
*/
