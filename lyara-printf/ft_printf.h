/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:12:14 by rraja-az          #+#    #+#             */
/*   Updated: 2024/07/03 13:47:46 by rraja-az         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

/* PRINTF.C */

int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printptr(uintptr_t ptr);
int		ft_printint(int n);
int		ft_printuint(unsigned int n);
int		ft_printhex(unsigned int n, char x);
int		ft_printf(const char *s, ...);

#endif