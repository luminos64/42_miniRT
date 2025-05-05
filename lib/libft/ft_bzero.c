/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:39:35 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/11 10:17:33 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*(ptr++) = 0;
	}
}

	// if (!s)
	// 	return ;

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	ft[] = "dfgdfghjhg";
// 	char	st[] = "dfgdfghjhg";

// 	printf("ft = %s, st = %s\n", ft, st);
// 	ft_bzero(ft + 3, 4);
// 	bzero(st + 3, 4);
// 	printf("ft = %s, st = %s\n", ft, st);
// 	ft_bzero(ft, 2);
// 	bzero(st, 2);
// 	printf("ft = %s, st = %s\n", ft, st);
// }
