/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:42:59 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 12:41:42 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}
//#include <stdio.h>
//#include <ctype.h>

// int	main(void)
// {
// 	char	a = 't';
// 	char	b = 'F';
// 	char	c = '3';
// 	char	d = ' ';

// 	printf("a = %c, b = %c, c = %c, d = %c\n", a, b, c, d);
// 	printf("ft\na = %d, b = %d, ", ft_isalnum(a), ft_isalnum(b));
// 	printf("c = %d, d = %d\n", ft_isalnum(c), ft_isalnum(d));
// 	printf("ct\n");
// 	printf("a = %d, b = %d, ", isalnum(a), isalnum(b));
// 	printf("c = %d, d = %d\n", isalnum(c), isalnum(d));
// }
