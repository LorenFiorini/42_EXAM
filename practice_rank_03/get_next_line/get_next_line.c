# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 4
#endif

char *get_next_line(int fd)
{
	static char line[100000];
	char *ans;
	int n = 0;
	int r = 0;
	char ch = (char) 255;

	if (fd < 0 || BUFFER_SIZE <= 0) {
		return (NULL);
	}
	//while (line[n] != '\0') n++;

	while (r == 0) {
		r = read(fd, &line[n], BUFFER_SIZE);
		if (r <= 0) break;
		while (r && line[n] !='\n') {
			n++;
			r--;
		}
	}
	if (r < 0 || n == 0) {
		return (NULL);
	}
	ans = (char *)malloc((n + (r > 0)) * sizeof(char));
	int i = 0;
	while (i < n || (i == n && line[i] == '\n')) {
		ans[i] = ch ^ line[i];
		i++;
	}
	ans[i] = '\0';
	if (r > 0) {
		n++;
		i = 0;
		while (i < r) {
			line[i] = line[n + i];
			i++;
		}
		line[i] = '\0';
	}

	return (ans);
}

/*
int main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	return(0);
}
*/
