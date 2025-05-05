/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:53:48 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/08 22:00:50 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res;

	res = 0;
	while (src[res])
		res++;
	if (size < 1)
		return (res);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

// if (!src)
// 	return ((size_t) NULL);

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "wers";
// 	char	b[] = "gggggg";
// 	char	c[] = "llllll";
// 	int	size = 6;
// 	int	len;

// 	printf("a = %s, b = %s, c = %s size = %d\n", a, b, c, size);
// 	len = ft_strlcpy(a, b, size);
// 	printf("ft_len = %d\na = %s\n", len, a);
// 	len = strlcpy(a, c, size);
// 	printf("st_len = %d\na = %s\n", len, a);
// }
