/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:10:58 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/08 22:01:59 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

	// if (!big)
	// 	return (0);

// #include <bsd/string.h>

// int	main(void)
// {
// 	char	a[] = "aaabcabcd";
// 	// char	b[] = "";
// 	char	*ptr;
// 	// int	i = -1;

// 	// printf("a = %s, b = %s, len = %d\n", a, b, i);
// 	ptr = ft_strnstr(a, "cd", 8);
// 	printf("ft = %s\n", ptr);
// 	ptr = strnstr(a, "cd", 8);
// 	printf("st = %s\n", ptr);
// }
