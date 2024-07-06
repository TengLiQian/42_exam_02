/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:09:37 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 22:09:48 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int x)
{
	char	a;

	a = '0';
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else if (x <= 9)
	{
		a += x;
		write(1, &a, 1);
	}
}

int	main(int argc, char *argv[])
{
	int	common_denom;

	common_denom = 1;
	if (argc == 3 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0)
	{
		if (atoi(argv[1]) > atoi(argv[2]))
			common_denom = atoi(argv[2]);
		else
			common_denom = atoi(argv[1]);
		while (common_denom > 0)
		{
			if (atoi(argv[1]) % common_denom == 0
				&& atoi(argv[2]) % common_denom == 0)
			{
				ft_putnbr(common_denom);
				break ;
			}
			common_denom -= 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
