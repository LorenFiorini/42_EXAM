# include <stdlib.h>
# include <stdio.h>


char *ft_itoa(int nbr)
{
	int cnt = (nbr <= 0);
	long long num = (long long) nbr;

	while (num)
	{
		num /= 10;
		cnt++;
	}

	char *ans = (char *) malloc(cnt + 1);

	ans[cnt--] = '\0';
	num = (long long) nbr;
	if (nbr < 0)
	{
		ans[0] = '-';
		num *= -1;
	}
	else
		ans[0] = '0';
	
	while (cnt >= 0 && num > 0)
	{
		ans[cnt] = '0' + (num % 10);
		cnt--;
		num /= 10;
	}	

	return ans;
}

/*
int main()
{
	int num = 12345;
	char *s = ft_itoa(num);
	printf("%s\n", s);

	num = -3864619;
	s = ft_itoa(num);
	printf("%s\n", s);

	num = 0;
	s = ft_itoa(num);
	printf("%s\n", s);

	return 0;
}
*/
