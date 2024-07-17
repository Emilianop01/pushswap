/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:41:57 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 18:42:02 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_duo *duo)
{
	t_list	*node;

	node = duo->b.head;
	duo->b.head = duo->b.head->next;
	node->next = duo->a.head;
	duo->a.head = node;
	write(1, "pa\n", 3);
}

void	rrotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;

	prev = *list;
	if (!prev->next)
		return ;
	while (prev->next->next)
		prev = prev->next;
	first = *list;
	last = ftlstlast(*list);
	prev->next = NULL;
	last->next = first;
	*list = last;
}

void	rra(t_duo *duo)
{
	rrotate(&(duo->a.head));
	write(1, "rra\n", 4);
}

void	rrb(t_duo *duo)
{
	rrotate(&(duo->b.head));
	write(1, "rrb\n", 4);
}

void	rrr(t_duo *duo)
{
	rrotate(&(duo->a.head));
	rrotate(&(duo->b.head));
	write(1, "rrr\n", 4);
}
