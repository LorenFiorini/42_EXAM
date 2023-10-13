# include <unistd.h>

void solve(char *s, char *t)
{
	int i = 0;

	while (s[i] != '\0')
	{
		int j = 0;
		while (j < i && s[j] != s[i]) j++;
		if (j < i && s[j] == s[i]) {
			i++;
			continue;
		}

		j = 0;
		while (t[j] != '\0' && s[i] != t[j]) j++;
		if (s[i] == t[j])
			write(1, &s[i], 1);
		i++;
	}
	return ;
}

int main(int argc, char** argv)
{
	
	if (argc == 3)
	{
		solve(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	
	return 0;
}
