/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:33:41 by lteng             #+#    #+#             */
/*   Updated: 2024/03/31 00:34:05 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
	return (result);
}
/*
int	main(void)
{
	printf("%hhu\n", reverse_bits(0));
	return (0);
}*/
