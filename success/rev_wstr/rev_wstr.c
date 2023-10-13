# include <unistd.h>

void rev_words(char *s)
{
	int n = 0;
	while (s[n]) n++;

	int i = n - 1, j = n - 1;
	while (i >= 0) {

		while (i >= 0 && s[i] != ' ' && s[i] != '\t') i--;
		write(1, &s[i+1], j - i);
		j = --i;
		if (i >= 0) write(1, " ", 1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2) {
		rev_words(argv[1]);
	}
	write(1, "\n", 1);
	return 0;
}
