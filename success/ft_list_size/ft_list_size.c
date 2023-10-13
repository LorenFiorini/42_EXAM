

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int	ft_list_size(t_list *begin_list)
{
	int n = 0;
	t_list *cur = begin_list;

	while (cur) {
		cur = cur->next;
		n++;
	}
	return n;
}

/*
Test for ft_list_size function


#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i = 1, n = 2;
	t_list *head;
	t_list *cur;

	head = (t_list *) malloc(sizeof(t_list));
	head->data = (void *) 0;
	cur = head;
	while (i < n) {
		cur->next = (t_list *) malloc(sizeof(t_list));
		cur = cur->next;
		cur->data = (void *) 0;
		cur->next = 0;
		i++;
	}


	printf("%d\n", ft_list_size(head));
	return 0;
}
*/
