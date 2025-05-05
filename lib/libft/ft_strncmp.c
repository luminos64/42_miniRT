/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:22:10 by usoontra          #+#    #+#             */
/*   Updated: 2025/01/06 19:59:08 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		if (i == n - 1)
			break ;
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

// int	main(void)
// {
// 	char	a[] = "test\200";
// 	char	b[] = "test\0";
// 	int	i;

// 	printf("a = %s, b = %s\n", a, b);
// 	i = ft_strncmp(a, b, 6);
// 	printf("ft ab = %d ", i);
// }
