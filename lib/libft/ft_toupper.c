/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:22:20 by usoontra          #+#    #+#             */
/*   Updated: 2024/08/29 15:05:52 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
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

// 	printf("a = %c %d ft a = %c %d\n", a, a, ft_toupper(a), ft_toupper(a));
// 	printf("b = %c %d ft b = %c %d\n", b, b, ft_toupper(b), ft_toupper(b));
// 	printf("c = %c %d ft c = %c %d\n", c, c, ft_toupper(c), ft_toupper(c));
// 	printf("d = %c %d ft d = %c %d\n", d, d, ft_toupper(d), ft_toupper(d));
// 	printf("a = %c %d ct a = %c %d\n", a, a, toupper(a), toupper(a));
// 	printf("b = %c %d ct b = %c %d\n", b, b, toupper(b), toupper(b));
// 	printf("c = %c %d ct c = %c %d\n", c, c, toupper(c), toupper(c));
// 	printf("d = %c %d ct d = %c %d\n", d, d, toupper(d), toupper(d));
// }
