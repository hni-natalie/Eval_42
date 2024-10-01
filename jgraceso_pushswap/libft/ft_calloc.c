/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:43:48 by jgraceso          #+#    #+#             */
/*   Updated: 2023/10/20 16:38:10 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total_size;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	if (size != 0)
	{
		if (count >= SIZE_MAX / size)
			return (NULL);
	}
	total_size = count * size;
	p = (void *)malloc(total_size);
	if (p)
	{
		ft_memset(p, 0, (total_size));
		return (p);
	}
	else
	{
		free(p);
		return (NULL);
	}
}
