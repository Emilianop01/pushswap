/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:40:34 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 20:10:21 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	isnumb(char *n)
{
	int	i;

	i = 0;
	while (n[i] == ' ')
		i++;
	if (n[i] == '+' || n[i] == '-')
		i++;
	if (!n[i])
		return (0);
	while (n[i] && ('0' <= n[i] && n[i] <= '9'))
	{
		i++;
	}
	while (n[i] == ' ')
	{
		i++;
	}
	if (n[i])
		return (0);
	return (1);
}

int	checkdup(t_duo *stack)
{
	t_list	*curr;
	t_list	*cont;

	curr = stack->a.head;
	while (curr)
	{
		cont = curr->next;
		while (cont)
		{
			if (curr->content == cont->content)
				return (0);
			cont = cont->next;
		}
		curr = curr->next;
	}
	return (1);
}

int	checkorder(t_duo *duo)
{
	t_list	*curr;

	curr = duo->a.head;
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (1);
		curr = curr->next;
	}
	return (0);
}
