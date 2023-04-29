# include <stdio.h>
# include <stdlib.h>


int main(int argc, char **argv)
{
	if (argc == 2) {
		int num = atoi(argv[1]);
		if (num == 1) {
			printf("1\n");
			return 0;
		}
		
		int d = 2, i = 0;

		while (num > 1) {
			while (num % d == 0) {
				if (i > 0) printf("*");
				printf("%i", d);
				num /= d;
				i++;
			}
			d++;
		}
	}
	printf("\n");
	return 0;
}
