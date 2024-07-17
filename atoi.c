/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:15:14 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/16 20:44:22 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ftatoi(const char *num)
{
    int     i;
    long    segno;
    long    d;

    segno = 1;
    i = 0;
    d = 0;
    while  (num[i] == ' ')
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
    return (d * segno);
}