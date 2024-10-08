/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:08:16 by jgraceso          #+#    #+#             */
/*   Updated: 2023/10/18 16:08:20 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_create(int n, size_t len, char *tab)
{
	while (n > 0)
	{
		tab[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*tab;
	size_t	len;
	size_t	k;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	len = ft_len(n);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	k = 0;
	if (n < 0)
	{
		n = -n;
		tab[0] = '-';
		k = 1;
	}
	tab[len--] = '\0';
	tab = ft_create(n, len, tab);
	return (tab);
}
