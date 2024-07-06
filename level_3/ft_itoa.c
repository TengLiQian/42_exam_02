/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:43:33 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 22:43:52 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdio.h>
#include <stdlib.h>

int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	long		temp;
	char		*result;

	temp = n;
	len = ft_count(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		temp *= -1;
	while (len > 0)
	{
		result[len - 1] = temp % 10 + '0';
		temp /= 10;
		len--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

/*
int	main(void)
{
	char	*result;

	result = ft_itoa(-12324242);
	printf("%s", result);
	free(result);
	return (0);
}*/

