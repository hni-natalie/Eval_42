/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:32:28 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/04 14:19:20 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sft_printfmt(va_list args, const char c)
{
	int	printlen;

	printlen = 0;
	if (c == 'c')
		printlen = ft_printchar(va_arg(args, int));
	else if (c == 's')
		printlen = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		printlen = ft_printptr(va_arg(args, uintptr_t));
	else if (c == 'd' || c == 'i')
		printlen = ft_printint(va_arg(args, int));
	else if (c == 'u')
		printlen = ft_printuint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		printlen = ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		printlen = ft_printchar('%');
	return (printlen);
}

/**
 * @brief			Prints formatted string with variables
 * 
 * @param s			String to be formatted (Data type)
 * @param va_list	Variables of args to be formatted
 * @return			N length of chars printed
*/
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		printlen;

	printlen = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			printlen += sft_printfmt(args, *++s);
		else
			printlen += ft_printchar(*s);
		s++;
	}
	va_end(args);
	return (printlen);
}

/*
	VARIADIC FUNCTIONS
	; 	Functions that accept a var number or args, useful when
		args count are unknown beforehand
	KEY CONCEPTS
	- ellipsis ('...') indicates it takes a variable number of arguments
	- <stdarg.h> library that provides macros to handle va_args
	- 'va_list' declares var to handle va_args
	- 'va_start(args, varname)' initialize va_list
	- 'va_arg(args, datatype)' retrieve the next arg as the datatype
		- used to retrieve next arg from va_list args
		- va_arg macro returns next arg from list, cast to uint
		- va arg advances va_list pointer to next arg in list

	- 'va_end(args)' cleans up va_list
		- WHY need this?
		- memory management (va_start mallocs > va_end frees)
		- prevent errors (if dont end, list becomes inconsistent)
		- portability (windows needs it for proper cleanup)
*/