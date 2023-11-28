//# include "list.h"

# include<stdio.h>
# include<stdlib.h>
typedef struct s_list t_list;
struct s_list
{
	int     data;
	t_list  *next;
};


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	if (lst == NULL || lst->next == NULL) return lst;

	t_list *head = lst;
	t_list *cur = lst;
	t_list *a, *b, *c;
	if (!cmp(cur->data, cur->next->data)) {
		a = cur;
		b = cur->next;
		c = cur->next->next;
		head = b;
		b->next = a;
		a->next = c;
	}
	cur = head;
	while (cur->next->next != NULL) {
		lst = cur;
		while (cur->next->next != NULL && !cmp(cur->next->data, cur->next->next->data)) {
			a = cur->next;
			b = cur->next->next;
			c = cur->next->next->next;
			cur->next = b;
			b->next = a;
			a->next = c;

			cur = cur->next;	
		}
		cur = lst->next;
	}

	return head;
}


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

	cur = head;
	while (cur != NULL) {
		printf("%i ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	cur = sort_list(head, (*ascending));
	while (cur != NULL) {
		printf("%i ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return 0;
}
