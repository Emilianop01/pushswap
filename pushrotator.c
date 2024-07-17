/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushrotator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:51:59 by epiacent          #+#    #+#             */
/*   Updated: 2024/06/17 20:51:59 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    pushrab(t_duo *duo, int indexa, int indexb)
{
    if (indexa == indexb)
    {
        while(indexa--)
            rr(duo);
    }
    else if (indexa > indexb)
    {
        indexa = indexa - indexb;
        while (indexa--)
            ra(duo);
        while (indexb--)
            rr(duo);
    }
    else
    {
        indexb = indexb - indexa;
        while (indexb--)
            rb(duo);
        while (indexa--)
            rr(duo);
    }
    pb(duo);
}

void    pushrrab(t_duo *duo, int diffa, int diffb)
{
    if (diffa == diffb)
    {
        while(diffa--)
            rrr(duo);
    }
    else if (diffa > diffb)
    {
        diffa = diffa - diffb;
        while (diffa--)
            rra(duo);
        while (diffb--)
            rrr(duo);
    }
    else
    {
        diffb = diffb - diffa;
        while (diffb--)
            rrb(duo);
        while (diffa--)
            rrr(duo);
    }
    pb(duo);
}

void    pushrra(t_duo *duo, int diffa, int indexb)
{
    while (diffa--)
        rra(duo);
    while (indexb--)
        rb(duo);
    pb(duo);
}

void    pushrrb(t_duo *duo, int indexa, int diffb)
{
    while (indexa--)
        ra(duo);
    while (diffb--)
        rrb(duo);
    pb(duo);
}