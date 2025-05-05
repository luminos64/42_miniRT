/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:11:26 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/11 10:24:21 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	i;

	i = (unsigned char)c;
	ptr = NULL;
	while (*s)
	{
		if (*s == i)
			ptr = (char *)s;
		s++;
	}
	if (!i)
		return ((char *)s);
	return (ptr);
}

	// if (!s)
	// 	return (NULL);

// int	main(void)
// {
// 	char	a[] = "Hai the ssdpoiu!!";
// 	char	b = 'j';
// 	char	*r;

// 	printf("a = %s, b = %c\n", a, b);
// 	r = ft_strrchr(a, b);
// 	printf("a = %s, b = %c, P = %ld, r = %s\n", a, b, r - a, r);
// 	// if (!r)
// 	// 	printf("NULL");
// 	r = strrchr(a, b);
// 	printf("a = %s, b = %c, P = %ld, r = %s\n", a, b, r - a, r);
// }
