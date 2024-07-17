/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefinal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:18:54 by epiacent          #+#    #+#             */
/*   Updated: 2024/06/19 19:18:54 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    solve(t_duo *duo)
{
    int i;

    i = countnode(duo);
    if (i < 6)
        solvesmall(duo, i);
    else
        emptya(duo);
}

int countnode(t_duo *duo)
{
    t_list  *curr;
    int     i;
    
    i = 0;
    curr = duo->a.head;
    while (curr)
    {
        i++;
        curr = curr->next;
    }
    return (i);
}

void    solvesmall(t_duo *duo, int i)
{
    if (i == 2)
        ra(duo);
    if (i == 3)
        solve3(duo);
    if (i > 3)
        solve35(duo, i);
}

void    solve3(t_duo *duo)
{
    int a1;
    int a2;
    int a3;

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

void    solve35(t_duo *duo, int i)
{
    int     indexl;
    int     indexs;

    indexl = checklowest(duo);
    indexs = checklowest2(duo, indexl);
    solve45(indexl, indexs, i, duo);
    solve3(duo);
    if (i == 5 && duo->b.head->content < duo->b.head->next->content)
        sb(duo);
    while (duo->b.head)
        pa(duo);
}

void   solve45(int indexl, int indexs, int i, t_duo *duo)
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
void    solve5(int indexl, int indexs, t_duo *duo)
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

int checklowest(t_duo *duo)
{
    t_list  *curr;
    int     min;
    int     i;
    int     j;

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

int checklowest2(t_duo *duo, int indexl)
{
    int     min;
    t_list  *curr;
    int     i;
    int     j;

    if (indexl > 0)
        curr = duo->a.head;
    else
        curr = duo->a.head->next;
    min = curr->content;
    i = 0;
    j = i;
    while (curr)
    {
        if (curr->content < min  && i != indexl)
        {
            min = curr->content;
            j = i;
        }
        i++;
        curr = curr->next;
    }
    return (j);
}