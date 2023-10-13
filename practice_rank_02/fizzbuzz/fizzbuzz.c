# include <unistd.h>

int main(void)
{
	int num = 1;
	char c;
	while (num <= 100) {
		if ((num % 3) && (num % 5)) {
			c = (num % 100) / 10 + '0';
			if (c != '0') write(1, &c, 1);
			c = num % 10 + '0';
			write(1, &c, 1);
		} else {
			if (num % 3 == 0)
				write(1, "fizz", 4);
			if (num % 5 == 0)
				write(1, "buzz", 4);
		}
		write(1, "\n", 1);
		num++;
	}
	return 0;
}
