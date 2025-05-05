/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:18:27 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 16:47:51 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// int	main(void)
// {
// 	char	a[] = "What is the...!!";
// 	char	*b;
// 	int	start = 400;
// 	int	len = 20;

// 	printf("a = %s, start = %d, len = %d\n", a, start, len);
// 	b = ft_substr(a, start, len);
// 	printf("ft = %s\n", b);
// 	free(b);
// }
