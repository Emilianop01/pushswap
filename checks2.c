/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:39:02 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/17 20:02:08 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countw(char const *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i])
			i++;
		if (i > 0)
			j++;
		while (str[i] == ' ' && str[i])
			i++;
	}
	return (j + 2);
}

int	copiaw(const char *s, char **frase, int i, int j)
{
	int	k;
	int	l;

	l = 1;
	frase[0] = NULL;
	while (s[i])
	{
		k = i;
		while (s[k] != ' ' && s[k])
			k++;
		if (k - i > 0)
		{
			frase[l] = (char *)malloc(k - i + 1);
			if (!frase[l])
				return (0);
			j = 0;
			while (i < k)
				frase[l][j++] = s[i++];
			frase[l++][j] = 0;
		}
		while (s[i] == ' ' && s[i])
			i++;
	}
	frase[l] = NULL;
	return (1);
}

char	**split(char const *str)
{
	char	**arr;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char **)malloc(countw(str) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (copiaw(str, arr, i, j) == 0)
	{
		freematrix(arr);
		return (NULL);
	}
	return (arr);
}
