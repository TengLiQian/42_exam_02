/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:47:09 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 21:47:21 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_count(int x, int y)
{
	if (y < x)
		return (x - y + 1);
	return (y - x + 1);
}

int	*ft_range(int start, int end)
{
	int	*final;
	int	count;
	int	i;

	count = ft_count(start, end);
	i = 0;
	final = malloc(sizeof(int) * count);
	if (!final)
		return (NULL);
	while (start <= end && i < count)
	{
		final[i] = start + i;
		i++;
	}
	while (end <= start && i < count)
	{
		final[i] = start - i;
		i++;
	}
	return (final);
}
/*
int	main(void)
{
	int	start = 1;
	int	end = -3;
	int	*result1 = ft_range(start, end);
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
