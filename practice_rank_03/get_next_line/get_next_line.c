//# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>


/*
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
//# define BUFFER_SIZE 5
char *get_next_line(int fd);

int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	
	return (0);
}
 // || (i == 0 && line[len-1] == '\0')) {
*/

char *get_next_line(int fd)
{
	char line[100000]; 
	int i = 0, len = 0, j;
	char c[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	while (1) {
		i = (int) read(fd, &c, BUFFER_SIZE);
		if (i <= 0) break;
		j = 0;
		while (j < i) {
			line[len + j] = c[j];
			if (c[j] == '\n')
				break;
			j++;
		}
		len += j;
		if (j < BUFFER_SIZE)
			break;
	}
	
	if (i < 0 || len == 0){
		return (NULL);
	}
	char *ans = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i <= len) {
		ans[i] = line[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

