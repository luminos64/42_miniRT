/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:12:02 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/02 16:23:24 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
		*(unsigned char *)(dest + i++) = *(unsigned char *)(src++);
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[] = "kkkkkkkkk";
// 	char	b[] = "something";
// 	char	c[] = "anything";
// 	int	i = 10;

// 	printf("a = %s, b = %s, c = %s, size = %d\n", a, b, c, i);
// 	ft_memcpy(a, b, i);
// 	printf("ft a = %s\n", a);
// 	memcpy(a, c, i);
// 	printf("st a = %s\n", a);
// }
