/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:37:36 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/16 20:45:29 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_duo   stack;

    if (argc == 1)
        return (0);
    if (argc == 2 && argv[1][0] == '\0')
        return (write(2, "Error\n", 6));
    if (argc == 2)
    {
        argv = split(argv[1]);
        if (!argv)
            return (write(2, "Error\n", 6));
    }
    if (checks(argc, argv) == 0)
        return (write(2, "Error\n", 6));
    create_stack(&stack, argv, argc);
    if (argc == 2)
        freematrix(argv);
    if (checklist(&stack) == 0)
        freequit(&stack, 1);
    solve(&stack);
    freequit(&stack, 0);
}

int checks(int argc, char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        if (isnumb(argv[i]) == 0)
        {
            if (argc == 2)
                freematrix(argv);
            return (0);
        }
        if (ftatoi(argv[i]) > INT_MAX || ftatoi(argv[i]) < INT_MIN)
        {
            if (argc == 2)
                freematrix(argv);
            return (0);
        }
        i++;
    }
    return (1);
}

int checklist(t_duo *duo)
{
    if (checkdup(duo) == 0)
        return (0);
    if (checkorder(duo) == 0)
        freequit(duo, 0);
    return (1);
}

int lenarr(char **arr)
{
    int i;

    i = 1;
    while (arr[i])
        i++;
    return (i);
}