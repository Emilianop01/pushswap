/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefinal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:44:32 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 18:44:36 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	solvesmall(t_duo *duo, int i)
{
	if (i == 2)
		ra(duo);
	if (i == 3)
		solve3(duo);
	if (i > 3)
		solve35(duo, i);
}

void	solve3(t_duo *duo)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = duo->a.head->content;
	a2 = duo->a.head->next->content;
	a3 = duo->a.head->next->next->content;
	if (a1 < a2 && a1 < a3)
	{
		sa(duo);
		ra(duo);
	}
	else if (a1 > a2 && a2 > a3)
	{
		sa(duo);
		rra(duo);
	}
	else if (a1 > a2 && a2 < a3 && a1 < a3)
		sa(duo);
	else if (a1 > a2 && a2 < a3 && a1 > a3)
		ra(duo);
	else if (a1 < a2 && a2 > a3)
		rra(duo);
}

void	solve35(t_duo *duo, int i)
{
	int	indexl;
	int	indexs;

	indexl = checklowest(duo);
	indexs = checklowest2(duo, indexl);
	solve45(indexl, indexs, i, duo);
	solve3(duo);
	if (i == 5 && duo->b.head->content < duo->b.head->next->content)
		sb(duo);
	while (duo->b.head)
		pa(duo);
}

void	solve45(int indexl, int indexs, int i, t_duo *duo)
{
	if (i == 5)
		solve5(indexl, indexs, duo);
	indexl = checklowest(duo);
	if (indexl == 3)
	{
		rra(duo);
		pb(duo);
	}
	else
	{
		while (indexl--)
			ra(duo);
		pb(duo);
	}
}

void	solve5(int indexl, int indexs, t_duo *duo)
{
	if (indexl <= 2 && indexl < indexs && indexl <= 5 - indexs)
		while (indexl--)
			ra(duo);
	else if (indexl > 2 && 5 - indexl <= indexs && 5 - indexl < 5 - indexs)
		while (indexl++ < 5)
			rra(duo);
	else if (indexs <= 2 && indexs < indexl && indexs <= 5 - indexl)
		while (indexs--)
			ra(duo);
	else
		while (indexs++ < 5)
			rra(duo);
	pb(duo);
}
