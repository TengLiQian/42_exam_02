/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:14:38 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 23:15:17 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	simpleatoi(char *str)
{
	int	i = 0;
	int	res = 0;

	while (str[i])
		res = (res * 10) + (str[i++] - '0');
	return (res);
}

void	hexconv(int n)
{
	if (n > 15)
	{
		hexconv(n / 16);
		hexconv(n % 16);
	}
	if (n < 10)
		ft_putchar(n + '0');
	else if (n < 16)
		ft_putchar(n - 10 + 'a');
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		hexconv(simpleatoi(argv[1]));
	}
	return (write(1, "\n", 1), 0);
}
