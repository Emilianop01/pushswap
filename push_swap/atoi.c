#include "push_swap.h"

long	ftatoi(const char *num)
{
	int	 i;
	long	segno;
	long	d;
	int	 j;

	segno = 1;
	i = 0;
	d = 0;
	j = 0;
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
		j++;
		if (j >= 11)
		return (22222222222);
	}
	return (d * segno);
}