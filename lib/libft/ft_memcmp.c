/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:45:26 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/07 22:57:07 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	a[] = "wertyu";
// 	char	b[] = "wertyu";
// 	char	c[] = "wexv";
// 	char	d[] = "weaerf";
// 	char	e[] = "";
// 	int	i;

// 	printf("a = %s, b = %s, c = %s, d = %s, e = %s\n", a, b, c, d, e);
// 	i = ft_memcmp(a, b, 6);
// 	printf("ft ab = %d ", i);
// 	i = ft_memcmp(a, c, 6);
// 	printf("ac = %d ", i);
// 	i = ft_memcmp(a, d, 6);
// 	printf("ad = %d ", i);
// 	i = ft_memcmp(a, e, 6);
// 	printf("ae = %d\n", i);

// 	i = memcmp(a, b, 6);
// 	printf("st ab = %d ", i);
// 	i = memcmp(a, c, 6);
// 	printf("ac = %d ", i);
// 	i = memcmp(a, d, 6);
// 	printf("ad = %d ", i);
// 	i = memcmp(a, e, 6);
// 	printf("ae = %d\n", i);
// }
