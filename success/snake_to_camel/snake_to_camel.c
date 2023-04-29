# include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2) {
		int cap = 0;
		int i = 0;
		char c;

		while (argv[1][i]) {
			if (argv[1][i] == '_') {
				cap = 1;
			} else {
				c = argv[1][i];
				if (cap) c = c + 'A' - 'a';
				write(1, &c, 1);
				cap = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);

	return 0;
}
