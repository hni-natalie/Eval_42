/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:02:07 by jgraceso          #+#    #+#             */
/*   Updated: 2024/09/22 15:02:13 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *read_buff, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(read_buff, buff);
	free(read_buff);
	return (tmp);
}

char	*create_line(int fd, char *read_buff)
{
	char	*buffer;
	int		read_bytes;

	if (!read_buff)
	{
		read_buff = malloc(1);
		read_buff[0] = '\0';
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(read_buff, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		read_buff = ft_strjoin_free(read_buff, buffer);
	}
	free(buffer);
	return (read_buff);
}

char	*get_line(char *read_buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!read_buff[i])
		return (NULL);
	while (read_buff[i] && read_buff[i] != '\n')
		i++;
	line = ft_substr(read_buff, 0, i + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_new_buff(char *read_buff)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (read_buff[i] && read_buff[i] != '\n')
		i++;
	if (!read_buff[i])
	{
		free (read_buff);
		return (NULL);
	}
	buff = (char *)malloc(ft_strlen(read_buff) - i + 1);
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (read_buff[i])
		buff[j++] = read_buff[i++];
	buff[j] = '\0';
	free(read_buff);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*read_buff[1000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &read_buff[fd], 0))
		return (NULL);
	read_buff[fd] = create_line(fd, read_buff[fd]);
	if (read_buff[fd] == NULL)
		return (NULL);
	line = get_line(read_buff[fd]);
	read_buff[fd] = get_new_buff(read_buff[fd]);
	return (line);
}
