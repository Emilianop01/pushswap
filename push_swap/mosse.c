#include "push_swap.h"

void	sa(t_duo *stacks)
{
	t_list	*n1;
	t_list	*n2;

	n1 = stacks->a.head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stacks->a.head = n2;
	write(1, "sa\n", 3);
}

void	sb(t_duo *stacks)
{
	t_list	*n1;
	t_list	*n2;

	n1 = stacks->b.head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stacks->b.head = n2;
	write(1, "sb\n", 3);
}

void	ss(t_duo *stacks)
{
	t_list	*n1;
	t_list	*n2;

	n1 = stacks->a.head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stacks->a.head = n2;
	n1 = stacks->b.head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stacks->b.head = n2;
	write(1, "ss\n", 3);
}