# include <stdlib.h>

char    *ft_strdup(char *src)
{
	int n = 0;
	while (src[n]) n++;

	char *ans = (char *) malloc((n + 1) * sizeof(char));

	while (n >= 0) {
		ans[n] = src[n];
		n--;
	}

	return ans;
}

/*
#include<stdio.h>
int main(void)
{
	char *s = "Hello, World!";
	char *t = ft_strdup(s);
	printf("%s\n", t);
	return 0;
}
*/
