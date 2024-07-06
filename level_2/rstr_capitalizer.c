/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:06:11 by lteng             #+#    #+#             */
/*   Updated: 2024/03/31 00:06:22 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

void	char_convert(char a, char b)
{
	char	new_char;

	if (a >= 'A' && a <= 'Z' && (b != ' ' && b != '\t' && b != '\0'))
	{
		new_char = a + 32;
		write(1, &new_char, 1);
	}
	else if (a >= 'a' && a <= 'z' && (b == ' ' || b == '\t' || b == '\0'))
	{
		new_char = a - 32;
		write(1, &new_char, 1);
	}
	else
		write(1, &a, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argc >= 2 && i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			char_convert(argv[i][j], argv[i][j + 1]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	if (argc < 2)
		write(1, "\n", 1);
	return (0);
}
