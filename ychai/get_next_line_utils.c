/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:14:36 by ychai             #+#    #+#             */
/*   Updated: 2024/06/21 13:53:20 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp_ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > 0x7FFFFFFF / size)
		return (0);
	temp_ptr = (void *)malloc(count * size);
	if (temp_ptr)
		ft_bzero(temp_ptr, count * size);
	return (temp_ptr);
}

void	ft_bzero(void *s, int i)
{
	char	*ptr;

	ptr = s;
	while (i-- > 0)
		*ptr++ = 0;
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*temp_str;
	unsigned int	i_main;
	unsigned int	i_sub;

	if (!s2 && !s1)
		return (NULL);
	temp_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (temp_str)
	{
		i_main = 0;
		i_sub = 0;
		while (s1 && *(s1 + i_sub))
			temp_str[i_main++] = s1[i_sub++];
		i_sub = 0;
		while (s2 && *(s2 + i_sub))
			temp_str[i_main++] = s2[i_sub++];
		temp_str[i_main] = '\0';
		free(s1);
	}
	return (temp_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}

char	*ft_strchr(const char *str, int chr)
{
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] != (char)chr)
	{
		if (str[count] == '\0')
			return (NULL);
		count++;
	}
	return ((char *)str + count);
}
