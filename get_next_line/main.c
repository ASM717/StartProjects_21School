#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*line;

	int		fd;
	fd = open("text.txt", O_RDONLY);

	// int   fd1;
	// int   fd2;

	// fd1 = open("text.txt", O_RDONLY);
  	// fd2 = open("text1.txt", O_RDONLY);

  	// get_next_line(fd1, &line);
  	// printf("%s\n", line);
  	// get_next_line(fd1, &line);
  	// printf("%s\n", line);

  	// get_next_line(fd2, &line);
  	// printf("%s\n", line);
  	// get_next_line(fd2, &line);
  	// printf("%s\n", line);

  	// get_next_line(fd1, &line);
  	// printf("%s\n", line);
  	// get_next_line(fd2, &line);
  	// printf("%s\n", line);

  	// get_next_line(fd1, &line);
  	// printf("%s\n", line);
  	// get_next_line(fd2, &line);
  	// printf("%s\n", line);
  	// return (0);


	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);


	//while (1)
	//{}
	//return (0);
}
