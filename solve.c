/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:45:56 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 19:00:26 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	solve(t_duo *duo)
{
	int	i;

	i = countnode(duo);
	if (i < 6)
		solvesmall(duo, i);
	else
		emptya(duo);
}

int	countnode(t_duo *duo)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = duo->a.head;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	emptya(t_duo *duo)
{
	t_list	*node;
	t_list	*targ;
	int		len;
	int		min;
	int		indexb;

	indexb = 0;
	while (duo->a.head)
	{
		node = findeco(duo);
		targ = findtarg(duo, node->content);
		pushnode(duo, node, targ, indexb);
	}
	min = INT_MIN;
	len = listlen(duo->b.head);
	indexb = 0;
	ordb(duo, len, min, indexb);
	while (duo->b.head)
		pa(duo);
}

void	pushnode(t_duo *duo, t_list *node, t_list *targ, int indexb)
{
	t_rot	rot;
	int		min;
	int		indexa;
	int		lenb;
	int		lena;

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
