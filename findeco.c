/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findeco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:46:37 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 18:46:43 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*findb(t_duo *duo, int node)
{
	t_list	*ret;
	t_list	*curr;
	int		min;

	min = INT_MIN;
	ret = NULL;
	curr = duo->b.head;
	while (curr)
	{
		if (min < curr->content && curr->content < node)
		{
			ret = curr;
			min = curr->content;
		}
		curr = curr->next;
	}
	return (ret);
}

t_list	*finds(t_duo *duo)
{
	t_list	*ret;
	t_list	*curr;
	int		max;

	max = INT_MIN;
	curr = duo->b.head;
	ret = NULL;
	while (curr)
	{
		if (curr->content > max)
		{
			ret = curr;
			max = curr->content;
		}
		curr = curr->next;
	}
	return (ret);
}

t_list	*findtarg(t_duo *duo, int curr)
{
	t_list	*targ;

	targ = findb(duo, curr);
	if (targ == NULL)
		targ = finds(duo);
	return (targ);
}

t_list	*findeco(t_duo *duo)
{
	t_list	*curr;
	t_list	*targ;
	t_list	*ret;
	int		min;

	if (!(duo->b.head))
		return (duo->a.head);
	curr = duo->a.head;
	while (curr)
	{
		targ = findtarg(duo, curr->content);
		if (bestrot(calcrot(duo, curr, targ)) < min)
		{
			min = bestrot(calcrot(duo, curr, targ));
			ret = curr;
		}
		curr = curr->next;
	}
	return (ret);
}
