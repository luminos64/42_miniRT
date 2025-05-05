/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:26 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/07 21:21:41 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_assign(char *res, int n, int len)
{
	long	i;

	i = n;
	if (i < 0)
	{
		i = i * -1;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (len-- && i != 0)
	{
		res[len] = (i % 10) + '0';
		i = i / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	temp;

	len = 1;
	temp = n;
	if (n < 0)
	{
		len++;
		temp *= -1;
	}
	while (temp > 9)
	{
		temp = temp / 10;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	ft_assign(res, n, len);
	return (res);
}

// int	main(void)
// {
// 	int	i = -345678765LL;
// 	char	*a;

// 	printf("i = %d\n", i);
// 	a = ft_itoa(-2147483648LL);
// 	printf("a = %s\n", a);
// }
