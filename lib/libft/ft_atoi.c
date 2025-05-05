/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:58:47 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/07 20:46:03 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nprt)
{
	int		sign;
	long	res;

	while ((*nprt > 8 && *nprt < 14) || *nprt == 32)
		nprt++;
	sign = 1;
	if (*nprt == '-' || *nprt == '+')
	{
		if (*nprt == '-')
			sign = -1;
		nprt++;
	}
	res = 0;
	while (*nprt >= '0' && *nprt <= '9')
	{
		res = res * 10 + (*nprt - '0');
		nprt++;
	}
	return (res * sign);
}

// int	main(void)
// {
// 	char	a[] = "345678";
// 	char	b[] = "5 6gkhj78";
// 	char	c[] = "++09876";
// 	char	d[] = "\0";

// 	printf("a = %s, b = %s, c = %s, d = %s\n", a, b, c, d);
// 	printf("ft\na = %d, b = %d, ", ft_atoi(a), ft_atoi(b));
// 	printf("c = %d, d = %d\n", ft_atoi(c), ft_atoi(d));
// 	printf("atoi\na = %d, b = %d ,", atoi(a), atoi(b));
// 	printf("c = %d, d = %d\n", atoi(c), atoi(d));
// }
