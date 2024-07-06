/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:47:45 by lteng             #+#    #+#             */
/*   Updated: 2024/03/30 21:48:00 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;
	int	j;
	int	firstword = 0;

	if (argc >= 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		j = i;
		while (argv[1][i] > 32)
			i++;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] > 32)
			{
				write(1, &argv[1][i], 1);
				firstword = 1;
			}
			if ((argv[1][i] < 33) && (argv[1][i - 1] > 32) && argv[1][i + 1])
				write(1, &argv[1][i], 1);
			i++;
		}
		if (firstword)
			write(1, " ", 1);
		while (argv[1][j] > 32)
			write(1, &argv[1][j++], 1);
	}
	return (write(1, "\n", 1), 0);
}
