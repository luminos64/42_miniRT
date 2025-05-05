/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:26:33 by usoontra          #+#    #+#             */
/*   Updated: 2025/03/20 19:26:46 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return (i);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	a[] = "ghjlkjo";

// 	ft_putstr_fd(a, 1);
// }
