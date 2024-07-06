/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:34:19 by lteng             #+#    #+#             */
/*   Updated: 2024/03/31 00:34:41 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

int	ft_found(char a, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (a == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_found(argv[1][i], argv[2]) != 0)
				counter++;
			i++;
		}
		if (counter == i)
		{
			i = 0;
			while (argv[1][i] != '\0')
				write(1, &argv[1][i++], 1);
			write(1, "\0", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
