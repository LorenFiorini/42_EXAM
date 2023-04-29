# include <unistd.h>

void capitalize(char *str)
{
	int i = 0;
	int cap = 1;

	while (str[i] != '\0')
	{
		if (cap && 'a' <= str[i] && str[i] <= 'z')
			str[i] += 'A' - 'a';
		else if (!cap && 'A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		
		cap = (str[i] == ' ' || str[i] == '\n');
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		capitalize(argv[i]);
		i++;
	}
	if (argc == 1)
		write(1, "\n", 1);
	return 0;
}
