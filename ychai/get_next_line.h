/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:59:13 by ychai             #+#    #+#             */
/*   Updated: 2024/06/21 13:37:01 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buff_main);
char	*ft_extract_line(char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, int i);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *str, int chr);
size_t	ft_strlen(const char *s);

#endif
