
# include "list.h"
/*
# include<stdio.h>
# include<stdlib.h>
typedef struct s_list t_list;
struct s_list
{
	int     data;
	t_list  *next;
};

void print_list(t_list *lst)
{
	t_list *cur = lst;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	cur = lst;
	while (cur != NULL) {
		printf("%p ", (void *) cur);
		cur = cur->next;
	}
	printf("\n");
}
*/

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int n = 0, i = 0;
	// count list length
	t_list *cur = lst;
	while (cur) {
		cur = cur->next;
		n++;
	}
	if (n < 2) return lst;
	
	// copy list to array
	int v[n];
	t_list *p[n];
	cur = lst;
	while (cur) {
		v[i] = cur->data;
		p[i] = cur;
		cur = cur->next;
		i++;
	}

	// bubble sort
	i = 0;
	while (i < n - 1) {
		int j = n - 1;
		while (i < j) {
			if (!cmp(v[j - 1], v[j])) {
				int tv = v[j];
				v[j] = v[j - 1];
				v[j - 1] = tv;
				t_list *tp = p[j];
				p[j] = p[j - 1];
				p[j - 1] = tp;
			}
			j--;
		}
		i++;
	}
	// link list
	i = 0;
	while (i < n - 1) {
		p[i]->next = p[i + 1];
		i++;
	}
	p[n - 1]->next = 0;

	//print_list(p[0]);
	// debug
	//i = 0;
	//while (i < n) {
	//	printf("%i ", v[i]);
	//	i++;
	//} printf("\n");
	//i = 0;
	//while (i < n) {
	//	printf("%p %p\n", (void*) &p[i], (void*) &p[i]->next);
	//	i++;
	//} printf("\n");
	return p[0];
}


/*
int ascending(int a, int b)
{
	return (a <= b);
}

int main(void)
{
	int n = 5;
	int d[] = {5, 2, 4, 8, 1};
	int i = 0;

	t_list* head = (t_list *) malloc(sizeof(t_list));
	t_list* cur = head;
	while (i < n) {
		cur->data = d[i];
		cur->next = NULL;
		i++;
		if (i < n)
			cur->next = (t_list *) malloc(sizeof(t_list));
		cur = cur->next;
	}

	print_list(head);
	cur = sort_list(head, (*ascending));
	
	printf("\n");
	print_list(cur);
	return 0;
}
*/
