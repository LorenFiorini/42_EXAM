# include <stdlib.h>
# include <stdio.h>

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main(int argc, char **argv)
{
	if (argc == 3) {
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		int g = gcd (a, b);
		printf("%i", g);
	}
	printf("\n");

	return 0;
}
