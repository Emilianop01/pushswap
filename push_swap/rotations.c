#include "push_swap.h"

int listlen(t_list *head)
{
	int	 i;
	t_list	*curr;

	i = 0;
	curr = head;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int magg(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int listindex(t_list *head, t_list *targ)
{
	int	 i;
	t_list	*curr;

	i = 0;
	curr = head;
	while (curr && curr->content != targ->content)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

t_rot	calcrot(t_duo *duo, t_list *node, t_list *targ)
{
	t_rot	insieme;
	int	 lena;
	int	 lenb;
	int	 indexa;
	int	 indexb;

	lena = listlen(duo->a.head);
	lenb = listlen(duo->b.head);
	indexa = listindex(duo->a.head, node);
	indexb = listindex(duo->b.head, targ);
	insieme.rab = magg(indexa, indexb);
	insieme.rrab = magg((lenb-indexb), (lena - indexa));
	insieme.rra = lena - indexa + indexb;
	insieme.rrb = lenb - indexb + indexa;
	return (insieme);
}

int bestrot(t_rot rot)
{
	int	 ret;

	ret = rot.rab;
	if (ret > rot.rra)
		ret = rot.rra;
	if (ret > rot.rrb)
		ret = rot.rrb;
	if (ret > rot.rrab)
		ret = rot.rrab;
	return (ret);
}