/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:40:59 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/08 20:03:49 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		start;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (len == start)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[len]))
		len--;
	res = ft_substr(s1, start, (len - start) + 1);
	return (res);
}

// int	main(void)
// {
// 	char	a[] = "   xxxtripouille";
// 	char	b[] = " x";
// 	char	*p;

// 	printf("a = %s, b = %s\n", a, b);
// 	p = ft_strtrim(a, b);
// 	printf("p = %s\n", p);
// }
