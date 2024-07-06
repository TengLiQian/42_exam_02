/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:36:15 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 22:36:34 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_isprime(int nbr)
{
	int	i;

	i = 2;
	if (nbr <= 1)
		return (0);
	while (i <= (nbr / 2))
	{
		if ((nbr % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print(int i, int nbr)
{
	printf("%i", i);
	if (nbr != i)
		printf("*");
}

int	main(int argc, char *argv[])
{
	int	i;
	int	nbr;

	i = 2;
	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("%i", nbr);
		while (nbr >= i)
		{
			if (nbr % i == 0 && ft_isprime(i) == 1)
			{
				ft_print(i, nbr);
				while ((nbr /= i) % i == 0)
					ft_print(i, nbr);
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
