/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:55:04 by usoontra          #+#    #+#             */
/*   Updated: 2024/08/29 14:07:44 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
	{
		return (1);
	}
	return (0);
}

//#include <stdio.h>
//#include <ctype.h>

// int	main(void)
// {
// 	char	a = 'a';
// 	char	b = '\n';

// 	printf("a = %c, b = %c\n", a, b);
// 	printf("a = %d, b = %d\n", ft_isprint(a), ft_isprint(b));
// 	printf("ct\n");
// 	printf("a = %d, b = %d\n", isprint(a), isprint(b));
// }
