/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:59:44 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/04 09:09:21 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sft_putptr(uintptr_t n)
{
	int			len;
	const char	hex[] = "0123456789abcdef";

	len = 0;
	if (n >= 16)
		len += sft_putptr(n / 16);
	write(1, &hex[n % 16], 1);
	len++;
	return (len);
}

/**
 * @brief		Writes prefix '0x' / '0' to stdout,
 * 				Calls helper to print hex rep of pointer value. 
 * @param ptr	Address of pointer to be printed
 * @return		N length of char printed
*/
int	ft_printptr(uintptr_t ptr)
{
	int	printlen;

	printlen = 0;
	printlen += write(1, "0x", 2);
	if (ptr == 0)
		printlen += write(1, "0", 1);
	else
	{
		if (ptr < 16)
			printlen += sft_putptr(ptr);
		else
		{
			printlen += sft_putptr(ptr / 16);
			printlen += sft_putptr(ptr % 16);
		}
	}
	return (printlen);
}

/*
	SFT_PUTPTR // prints the string directly
	1. Takes uintptr_t n
		- 	WHY uintptr_t?
		-	type specifically designed to hold pointer value as int
		-	suitable for highly portable and flexible use in code
	2. Checks if n >= 16, true> recursively divide by 16 
	3. Remainder of modulus points to hex index and writes correspondingly

	FT_PRINTPTR
	1. Takes uintptr_t int 
	2. printlen; track count of char printed
	3. count increases to 2 when 0x printed(start of hexa)
	4. checks if ptr is 0, writes 0 to to stdoutput, count + 1
	5. ELSE
		-	Check if ptr < 16; true > writes hex rep
			ELSE
			- recursively divides by 16 to handle bigger number
			- recursively modulus by 16 to handle 
*/

/*
	EG
	1. ft_printptr(0x1234)
		- writes 0x > printlen += 2
		- ptr is not 0 > calls sft_putptr(0x1234)
	2. FIRST CALL - sft_putptr(0x1234)
		- n >= 16 > recursively calls sft_putptr(n / 16) = (0x123)
	3. SECOND CALL - sft_putptr(0x123)
		- n >= 16 > recursively calls sft_putptr(n / 16) = (0x12)
	4. THIRD CALL - sft_putptr(0x12)
		- n >= 16 > recursively calls sft_putptr(n / 16) = (0x1)
	5. FOURTH CALL - sft_putptr(0x1)
		- n >= 16 > false > writes &hex[1] based on % result (1)
		- len = 1
	6. RETURNS THIRD CALL - sft_putptr(0x12)
		- writes &hex[2] based on % (2) 
		- len = 2
	7. RETURNS SECOND CALL - sft_putptr(0x123)
		- writes &hex[3] based on % (3) 
		- len = 3
	8. RETURNS FIRST CALL - sft_putptr(0x1234)
		- writes &hex[4] based on % (4) 
		- len = 4
	9. RETURNS ft_printptr(0x1234)
		- printlen = 6 (2 from "0x")
		- fx returns 6
*/