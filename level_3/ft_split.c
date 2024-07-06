/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:10:44 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 22:16:20 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k;
	char	**array = (malloc(sizeof(**array) * 100));

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] > 32)
		{
			k = 0;
			array[j] = malloc(sizeof(char) * 100);
			while (str[i] > 32)
				array[j][k++] = str[i++];
		array[j][k] = '\0';
		j++;
		}
		else
			i++;
	}
	array[j] = 0;
	return (array);
}

/*
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("Hello this is my World");
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}*/
