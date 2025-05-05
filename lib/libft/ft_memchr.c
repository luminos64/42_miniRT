/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:33:30 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/08 23:40:46 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// char	a[] = {0, 1, 2 ,3 ,4 ,5};
// 	char	a[] = "bonjour";
// 	char	b = 's';
// 	char	*r;

// 	printf("a = %s\n", a);
// 	r = ft_memchr(a, b, 7);
// 	printf("ft P = %ld\n%s\n", r - a, r);
// 	r = memchr(a, b, 7);
// 	printf("mem P = %ld\n%s\n", r - a, r);
// }
