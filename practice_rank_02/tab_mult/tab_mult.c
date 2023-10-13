#include <unistd.h>

void ft_putnbr(int num)
{
	int v[] = {0,0,0,0,0,0,0,0,0,0,0};
	int i = 0;
	char c;
	while (num >= 0)
	{
		v[i] = num % 10;
		num /= 10;
		if (num == 0) break;
		i++;
	}

	while (i >= 0)
	{
		c = v[i] + '0';
		write(1, &c, 1);
		i--;
	}
}

int stoi(char* s)
{
	int num = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		num *= 10;
		num += s[i] - '0';
		i++;
	}
	return num;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 1;
		int num = stoi(argv[1]);
		while (i < 10) 
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(i * num);
			write(1, "\n", 1);
			i++;
		}
	} else {
		write(1, "\n", 1);
	}
	
	return 0;
}
