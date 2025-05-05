/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:18:58 by usoontra          #+#    #+#             */
/*   Updated: 2025/03/20 19:27:16 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[] = "dfghn";

// 	printf("a = %s\nft_str = %zu, str = %zu\n", a, ft_strlen(a), strlen(a));
// }
