/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:40:07 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 13:55:33 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	if (fd < 0)
		return ;
	i = n;
	if (n < 0)
	{
		i = (i * -1);
		write(fd, "-", 1);
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
	{
		i = i + '0';
		write(fd, &i, 1);
	}
}

// int	main(void)
// {
// 	int	a = -898097;

// 	printf("%d\n", a);
// 	ft_putnbr_fd(a, 1);
// }
