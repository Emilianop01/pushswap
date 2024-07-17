/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefinal2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:23:44 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 18:34:20 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	checklowest(t_duo *duo)
{
	t_list	*curr;
	int		min;
	int		i;
	int		j;

	curr = duo->a.head;
	min = curr->content;
	i = 0;
	j = i;
	while (curr)
	{
		if (curr->content < min)
		{
			min = curr->content;
			j = i;
		}
		i++;
		curr = curr->next;
	}
	return (j);
}

int	checklowest2(t_duo *duo, int indexl)
{
	int		min;
	t_list	*curr;
	int		i;
	int		j;

	if (indexl > 0)
		curr = duo->a.head;
	else
		curr = duo->a.head->next;
	min = curr->content;
	i = 0;
	j = i;
	while (curr)
	{
		if (curr->content < min && i != indexl)
		{
			min = curr->content;
			j = i;
		}
		i++;
		curr = curr->next;
	}
	return (j);
}
