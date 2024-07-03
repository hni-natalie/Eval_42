/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:41:48 by ychai             #+#    #+#             */
/*   Updated: 2024/06/21 13:39:52 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_line(char *str)
{
	char	*temp_line;
	int		count;

	if (!str || !(str + 1))
		return (NULL);
	str++;
	temp_line = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	count = 0;
	while (str[count])
	{
		temp_line[count] = str[count];
		count++;
	}
	return (temp_line);
}

char	*ft_extract_line(char *str)
{
	int		word_count;
	int		i;
	char	*temp;

	if (!str || !str[0])
		return (NULL);
	word_count = 0;
	while (str[word_count] && str[word_count] != '\n')
		word_count++;
	if (str[word_count] == '\n')
		word_count++;
	temp = ft_calloc(word_count + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

char	*ft_read_file(int fd, char *buff_main)
{
	int		read_check;
	char	*buff_temp;

	if (ft_strchr(buff_main, '\n'))
		return (buff_main);
	buff_temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buff_temp && !ft_strchr(buff_main, '\n'))
	{
		read_check = read(fd, buff_temp, BUFFER_SIZE);
		if (read_check < 1)
			break ;
		buff_main = ft_strjoin(buff_main, buff_temp);
		ft_bzero(buff_temp, BUFFER_SIZE);
	}
	free(buff_temp);
	return (buff_main);
}

char	*get_next_line(int fd)
{
	static char	*buff_fix;
	char		*buff_tmp;	
	char		*buff_rtn;	

	printf("Static: %s\n", buff_fix);
	buff_tmp = ft_read_file(fd, buff_fix);
	buff_rtn = ft_extract_line(buff_tmp);
	buff_fix = ft_save_line(ft_strchr(buff_tmp, '\n'));
	printf("Static: %s\n", buff_fix);
	free(buff_tmp);
	return (buff_rtn);
}


int	main(void)
{
	int		fd;
	char	*rtn;
 
	fd = open("text1", O_RDONLY);
	printf("FD=%d\n", fd);
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	printf("=-=-=-=-=-=-=-=-=-\n");
	for (int i = 0; i < 7; i++)
	{
		rtn = get_next_line(fd);
		printf("Return= ~~~%s~~~\n", rtn);
		free(rtn);
	}
	printf("\n\n");
	close(fd);
}
