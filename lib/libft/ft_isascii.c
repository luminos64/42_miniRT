/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:06:11 by usoontra          #+#    #+#             */
/*   Updated: 2024/08/29 14:06:37 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
//#include <stdio.h>
//#include <ctype.h>

// int main(void)
// {
//     char    a = '7';
//     int    b = 0x80;

//     printf("a = %c b = %c\n", a, b);
//     printf("a = %d b = %d\n", ft_isascii(a), ft_isascii(b));
//     printf("ct\na = %d b = %d\n", isascii(a), isascii(b));
// }
