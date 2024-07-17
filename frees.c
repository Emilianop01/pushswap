/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:39:45 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 20:02:23 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freequit(t_duo *stacks, int i)
{
	t_list	*temp;
	t_list	*freed;

	temp = stacks->a.head;
	while (temp)
	{
		freed = temp;
		temp = temp->next;
		free(freed);
	}
	if (stacks->b.head)
		temp = stacks->b.head;
	while (temp)
	{
		freed = temp;
		temp = temp->next;
		free(freed);
	}
	if (i == 1)
		write(2, "Error\n", 6);
	exit(0);
}

void	freematrix(char **matrix)
{
	int	i;

	i = 1;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}
