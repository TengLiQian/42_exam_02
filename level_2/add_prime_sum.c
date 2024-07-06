/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:41:30 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 23:41:49 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <stdio.h>
#include <unistd.h>

int	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
	{
		digit = nbr + '0';
		write (1, &digit, 1);
	}
	return (0);
}

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

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	main(int argc, char *argv[])
{
	int	pre_nbr;
	int	result;

	pre_nbr = 2;
	result = 0;
	if (argc == 2 && argv[1] > 0)
	{
		while (pre_nbr <= ft_atoi(argv[1]))
		{
			if (ft_isprime(pre_nbr) == 1)
				result += pre_nbr;
			pre_nbr += 1;
		}
		ft_putnbr(result);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
