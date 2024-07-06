/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:04:46 by lteng             #+#    #+#             */
/*   Updated: 2024/03/31 00:04:58 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	max_num;
	int	i;

	max_num = 0;
	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > max_num)
			max_num = tab[i];
		i++;
	}
	return (max_num);
}
/*
int	main(void)
{
	int	arr1[] = {1, 2, 3, 8, 15, 4};
	printf("%i\n", max(arr1, 6));
	return (0);
}*/
