/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:43:11 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/02 16:27:24 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptd;
	unsigned char	*pts;

	ptd = (unsigned char *)dest;
	pts = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (pts < ptd)
	{
		while (n--)
			ptd[n] = pts[n];
	}
	else
	{
		while (n--)
			*(ptd++) = *(pts++);
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[] = "something";
// 	char	b[] = "hhh";
// 	char	c[] = "lll";

// 	printf("a = %s, b = %s, c = %s\n", a, b, c);
// 	ft_memmove(a, b, 10);
// 	printf("a = %s, b = %s, c = %s\n", a, b, c);
// 	memmove(a, c, 7);
// 	printf("a = %s, b = %s, c = %s\n", a, b, c);
// }
