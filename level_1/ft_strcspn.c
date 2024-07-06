/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:46:12 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 21:46:23 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <unistd.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		count;
	const char	*r;

	count = 0;
	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
				return (count);
			r++;
		}
		s++;
		count++;
	}
	return (count);
}

/*
int	main(void)
{
	char	*str = "Hello";
	char	*reject = "aeiou";

	printf("%lu\n", ft_strcspn(str, reject));
	return (0);
}*/
