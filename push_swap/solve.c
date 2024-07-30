#include "push_swap.h"

void	emptya(t_duo *duo)
{
	t_list	*node;
	t_list	*targ;
	int	 len;
	int	 min;
	int	 index;

	while (duo->a.head)
	{
		node = findeco(duo);
		targ = findtarg(duo, node->content);
		pushnode(duo, node, targ);
	}
	min = INT_MIN;
	len = listlen(duo->b.head);
	index = 0;
	ordb(duo, len, min, index);
	while (duo->b.head)
		pa(duo);
}

void	pushnode(t_duo *duo, t_list *node, t_list *targ)
{
	t_rot	rot;
	int	 min;
	int	 indexa;
	int	 indexb;
	int	 lena;
	int	 lenb;

	indexa = listindex(duo->a.head, node);
	indexb = listindex(duo->b.head, targ);
	lena = listlen(duo->a.head);
	lenb = listlen(duo->b.head);
	rot = calcrot(duo, node, targ);
	min = bestrot(rot);
	if (rot.rab == min)
		pushrab(duo, indexa, indexb);
	else if (rot.rrab == min)
		pushrrab(duo, lena - indexa, lenb - indexb);
	else if (rot.rra == min)
		pushrra(duo, lena - indexa, indexb);
	else
		pushrrb(duo, indexa, lenb - indexb);
}

void	ordb(t_duo *duo, int len, int min, int index)
{
	t_list	*curr;
	t_list	*max;

	curr = duo->b.head;
	while (curr)
	{
		if (curr->content > min)
		{
			min = curr->content;
			max = curr;
		}
		curr = curr->next;
	}
	index = listindex(duo->b.head, max);
	if (index <= len - index)
		while (index--)
			rb(duo);
	else
	{
		index = len - index;
		while (index--)
			rrb(duo);
	}
}