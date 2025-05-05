/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:39:31 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/11 10:24:14 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	i;

	i = (unsigned char)c;
	while (*s)
	{
		if (*s == i)
		{
			ptr = (char *)s;
			return (ptr);
		}
		s++;
	}
	if (!i)
		return ((char *)s);
	return (NULL);
}

	// if (!s)
	// 	return (NULL);

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "Hai the ssdpoiu!!";
// 	char	b = 'i';
// 	char	*r;

// 	printf("a = %s, b = %c\n", a, b);
// 	r = ft_strchr(a, b);
// 	printf("a = %s, b = %c, P = %ld, r = %s\n", a, b, r - a, r);
// 	r = strchr(a, b);
// 	printf("a = %s, b = %c, P = %ld, r = %s\n", a, b, r - a, r);
// }
