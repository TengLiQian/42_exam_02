/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:01:35 by lteng             #+#    #+#             */
/*   Updated: 2024/03/31 00:01:49 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdio.h>
#include <stdlib.h>

int	ft_count(int x, int y)
{
	if (y < x)
		return (x - y + 1);
	return (y - x + 1);
}

int	*ft_rrange(int start, int end)
{
	int	*final;
	int	count;
	int	i;

	count = ft_count(start, end);
	i = 0;
	final = malloc(sizeof(int) * count);
	if (!final)
		return (NULL);
	while (start >= end && i < count)
	{
		final[i] = end + i;
		i++;
	}
	while (end >= start && i < count)
	{
		final[i] = end - i;
		i++;
	}
	return (final);
}

/*
int	main(void)
{
	int	start = 0;
	int	end = -3;
	int	*result1 = ft_rrange(start, end);
	int	i = 0;
	int	count = ft_count(start, end);
	while (i < count)
	{
		printf("%i", result1[i]);
		i++;
	}
	free(result1);
	return (0);
}*/
