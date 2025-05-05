/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:22:21 by usoontra          #+#    #+#             */
/*   Updated: 2024/08/29 13:23:17 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	char	a = 'w';
// 	char	b = 'T';
// 	char	c = ' ';

// 	printf("a = %c, b = %c, c = %c\n", a, b, c);
// 	printf("ft a = %d, b = %d, ", ft_isalpha(a), ft_isalpha(b));
// 	printf("c = %d\n", ft_isalpha(c));
// 	printf("ct a = %d, b = %d, c = %d\n", isalpha(a), isalpha(b), isalpha(c));
// }
