
#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	int i = 0;
	int r = 1;
	char c;
	char *ans = malloc(100000);

	while ((r = read(fd, &c, BUFFER_SIZE)) > 0) {
		ans[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	ans[i] = '\0';

	if (r < 0 || i = 0 || (!buffer[i - 1] && !r)) {
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
