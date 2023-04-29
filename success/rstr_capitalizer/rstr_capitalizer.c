# include <unistd.h>


void rev_cap(char *str)
{
	int n = 0;
	while (str[n]) n++;

	char s[n];
	int i = n - 1;
	int cap = 1;
	while (i >= 0) {
		if (cap && 'a' <= str[i] && str[i] <= 'z') 
			s[i] = str[i] + 'A' - 'a';
		else if (!cap && 'A' <= str[i] && str[i] <= 'Z') 
			s[i] = str[i] + 'a' - 'A';
		else
			s[i] = str[i];
		cap = (str[i] == ' ' || str[i] == '\t');
		i--;
	}
	write(1, &s, n);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc > 1) {
		int i = 1;
		while (i < argc) {
			rev_cap(argv[i]);
			i++;
		}
	} else {
		write(1, "\n", 1);
	}
	return 0;
}
