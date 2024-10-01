/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:08:50 by jgraceso          #+#    #+#             */
/*   Updated: 2023/10/18 09:59:14 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = ft_strlen(s);
	j = 0;
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, j + 1);
	return (str);
}
