/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:56:40 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/23 23:04:48 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	j = size;
	i = ft_strlen(dst);
	res = ft_strlen(src);
	if (i > size || !j)
		return (res + size);
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (res + i);
}
// #include <stdio.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char	a[] = "yyyyyyyyyyyyyyyyy";
// 	char	b[] = "yyyyyyyyyyyyyyyyy";
// 	char	c[] = "iiertyuiopiuytreii";

// 	// printf("a = %s, b = %s, c = %s\n", a, b, c);
// 	// len1 = ft_strlcat(a, b, 20);
// 	printf("ft_len = %zu\na = %s\n", ft_strlcat(a, c, 20), a);
// 	// len2 = strlcat(c, b, 20);
// 	printf("sl_len = %zu\nc = %s\n", strlcat(b, c, 20), b);
// }
