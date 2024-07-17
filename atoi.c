/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:41:17 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 20:18:16 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

long	ftatoi(const char *num)
{
	int		i;
	long	segno;
	long	d;

	segno = 1;
	i = 0;
	d = 0;
	while (num[i] == ' ')
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			segno = -1;
		i++;
	}
	while (num[i])
	{
		d = d * 10 + num[i] - 48;
		i++;
	}
	if (i >= 11)
		return (214745645645);
	return (d * segno);
}
