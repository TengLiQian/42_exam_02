/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:27:40 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 23:27:58 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

#include <unistd.h>

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
		a = x + '0';
		write(1, &a, 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		ft_putnbr(argc - 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
