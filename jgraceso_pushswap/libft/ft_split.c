/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:45:13 by jgraceso          #+#    #+#             */
/*   Updated: 2023/10/24 14:45:15 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	*ft_getword(char const *s, char c, int n)
{
	char	*wd;
	int		len;
	int		i;
	int		j;

	i = n;
	j = 0;
	len = ft_wordlen(s, c, n);
	wd = (char *)malloc(sizeof(char) * (len + 1));
	if (!wd)
		return (0);
	while (s[i] != c && s[i] != '\0')
		wd[j++] = s[i++];
	wd[j] = '\0';
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = -1;
	if (!s)
		return (0);
	arr = (char **)malloc((sizeof(char *) * (ft_count_word(s, c) + 1)));
	if (!arr)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			arr[++j] = ft_getword(s, c, i++);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	arr[++j] = NULL;
	return (arr);
}
