/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:44:45 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 13:57:39 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

	// if (!s)
	// 	return (NULL);

// int	main(void)
// {
// 	char	a[] = "oiuytr";
// 	char	*b;
// 	char	*c;

// 	printf("a = %s\n", a);
// 	b = ft_strdup(a);
// 	printf("ft = %s\n", b);
// 	c = strdup(a);
// 	printf("st = %s\n", c);
// }
