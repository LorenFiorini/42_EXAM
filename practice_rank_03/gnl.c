# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct s_buffer
{
	int		idx;
	int		res;
	int		len;
	int 	with_nl;
	char	buf[BUFFER_SIZE + 1];
}	t_buffer;

/*
# include <stdio.h>
void print_buffer(t_buffer *buffer)
{
	printf("^^^^^^^^^^^^^^^^^^^^^\n");
	printf("idx: %d\n", buffer->idx);
	printf("res: %d\n", buffer->res);
	printf("len: %d\n", buffer->len);
	printf("with_nl: %d\n", buffer->with_nl);
	int i = 0;
	while (i < buffer->res)
	{
		printf("%c", buffer->buf[i]);
		i++;
	}
	printf("\n___________________\n");
}
*/

int		search_endline(t_buffer *buffer)
{
	int	i;

	i = 0;
	buffer->with_nl = 1;
	while (i < buffer->res)
	{
		if (buffer->buf[i] == '\n')
			return (i);
		i++;
	}
	buffer->with_nl = 0;
	return (i);
}

void	move_buffer(t_buffer *buffer)
{
	int	i;

	i = 0;
	while (buffer->idx + buffer->with_nl + i < buffer->res)
	{
		buffer->buf[i] = buffer->buf[buffer->idx + buffer->with_nl + i];
		i++;
	}
	buffer->buf[i] = '\0';
	buffer->len = 0;
	buffer->res = i;
}

char	*create_line(t_buffer *buffer, char *prev_line)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (buffer->len + buffer->idx + buffer->with_nl + 1));
	if (!line) {
		if (prev_line)
			free(prev_line);
		return (NULL);
	}
	i = 0;
	while (prev_line && i < buffer->len && prev_line[i])
	{
		line[i] = prev_line[i];
		i++;
	}
	if (prev_line)
		free(prev_line);
	i = 0;
	while (i < buffer->idx + buffer->with_nl)
	{
		line[buffer->len + i] = buffer->buf[i];
		i++;
	}
	line[buffer->len + i] = '\0';
	buffer->len += i;
	return (line);
}

char *get_next_line(int fd)
{
	static t_buffer	buffer;
	char			*line;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = create_line(&buffer, NULL);
	if (!line)
		return (NULL);
	while (!buffer.with_nl) {
		buffer.res = read(fd, buffer.buf, BUFFER_SIZE);
		buffer.idx = search_endline(&buffer);
		if (buffer.res < 0)
		{
			if (line) free(line);
			buffer.res = buffer.idx = buffer.len = 0;
			return (NULL);
		}
		line = create_line(&buffer, line);
		if (!line)
			return (NULL);
		if (buffer.res < BUFFER_SIZE)
			break;
	}
	if (buffer.with_nl)
	{
		move_buffer(&buffer);
		buffer.idx = search_endline(&buffer);
	}
	else
		buffer.res = buffer.idx = buffer.len = 0;
	return (line);
}

/*
// Test main
# include <stdio.h>
# include <fcntl.h>
int main(void)
{
	char	*line;
	int 	fd;
	int 	mx = 20;

	fd = open("aaa.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && mx--)
	{
		printf("%s", line);
		free(line);
		line =	get_next_line(fd);
	}
	return (0);
}
*/

