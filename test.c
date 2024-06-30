#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *buffer;
	
	buffer = ft_calloc (15, 1);
	fd = open("text1", O_RDONLY);
	read(fd,buffer,13);
	printf("READ: %s\n", buffer);
	ft_bzero(buffer, 10);
	read(fd,buffer,5);
	printf("READ: %s\n", buffer);
	close(fd);
	return (0);
}
