#include "push_swap.h"
//polipo

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

int	copiaw(const char *s, char **frase, int i, int l, int j)
{
	int	k;
	
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
	int		l;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	l = 1;
	j = 0;
	arr = (char **)malloc(countw(str) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (copiaw(str, arr, i, l, j) == 0)
	{
		freematrix(arr);
		return (NULL);
	}
	return (arr);
}