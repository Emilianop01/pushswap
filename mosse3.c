/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:18:18 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/10 20:09:55 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_duo *duo)
{
    t_list  *node;
    
    node = duo->a.head;
    duo->a.head = duo->a.head->next;
    node->next = duo->b.head;
    duo->b.head = node;
    write(1, "pb\n", 3);
}

void    pa(t_duo *duo)
{
    t_list  *node;
    
    node = duo->b.head;
    duo->b.head = duo->b.head->next;
    node->next = duo->a.head;
    duo->a.head = node;
    write(1, "pa\n", 3);
}

void    rrotate(t_list **list)
{
    t_list  *first;
    t_list  *last;
    t_list  *prev;

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

void    rra(t_duo *duo)
{
    rrotate(&(duo->a.head));
    write(1, "rra\n", 4);
}

void    rrb(t_duo *duo)
{
    rrotate(&(duo->b.head));
    write(1, "rrb\n", 4);
}

void    rrr(t_duo *duo)
{
    rrotate(&(duo->a.head));
    rrotate(&(duo->b.head));
    write(1, "rrr\n", 4);
}