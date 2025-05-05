/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:34:25 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/07 19:07:25 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	a = 'a';
// 	char	b = 'B';
// 	char	c = '5';
// 	int	d = 0;

// 	printf("a = %c %d ft a = %c %d\n", a, a, ft_tolower(a), ft_tolower(a));
// 	printf("b = %c %d ft b = %c %d\n", b, b, ft_tolower(b), ft_tolower(b));
// 	printf("c = %c %d ft c = %c %d\n", c, c, ft_tolower(c), ft_tolower(c));
// 	printf("d = %c %d ft d = %c %d\n", d, d, ft_tolower(d), ft_tolower(d));
// 	printf("a = %c %d ct a = %c %d\n", a, a, tolower(a), tolower(a));
// 	printf("b = %c %d ct b = %c %d\n", b, b, tolower(b), tolower(b));
// 	printf("c = %c %d ct c = %c %d\n", c, c, tolower(c), tolower(c));
// 	printf("d = %c %d ct d = %c %d\n", d, d, tolower(d), tolower(d));
// }
