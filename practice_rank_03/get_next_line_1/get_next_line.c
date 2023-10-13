# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd)
{
	char *line[100000]; 
	int i = 0, len = 0;
	char c;

	if (BUFER_SIZE <= 0 || fd < 0)
		return (NULL);

	while (1) {
		i = (int) read(fd, &c, 1);
		if (i <= 0) break;
		line[len] = c;
		len += i;
		if (c == '\n')
			break;
	}
	line[len] = '\0';
	if (i < 0 || len == 0 || (i == 0 && line[len-1] == '\0')) {
		return (NULL);
	}
	char *ans = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len) {
		ans[i] = line[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
