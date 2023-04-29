
typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;


static void dfs(char **tab, t_point s, int i, int j, char ch)
{
	tab[i][j] = 'F';
	int id = 0, n = 4;
	int a[] = {0, 0, 1, -1};
	int b[] = {1, -1, 0, 0};

	while (id < n) {
		int r = i + a[id];
		int c = j + b[id];
		id++;
		if (r < 0 || c < 0 || r == s.y || c == s.x || tab[r][c] != ch)
			continue;
		dfs(tab, s, r, c, ch);
	}
	
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	dfs(tab, size, begin.y, begin.x, tab[begin.y][begin.x]);
}


// TEST
/*
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10000001",
		"10010101",
		"10110001",
		"11101111",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {3, 1};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
*/

