/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:55:04 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/03 10:29:47 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief		Writes char
 * 
 * @param n		Char to be formatted
 * @return		N length of char printed
*/
int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
