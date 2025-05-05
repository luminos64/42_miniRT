/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:57:09 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 13:42:09 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	f(unsigned int i, char *c)
// {
// 	if (i < 0)
// 		i = i + 1;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// 	else if (*c >= 'A' && *c <= 'Z')
// 		*c = *c + 32;
// }

// int	main(void)
// {
// 	char	a[] = "ddffDSFer";

// 	printf("a = %s\n", a);
// 	ft_striteri(a, f);
// 	printf("ft_a = %s\n", a);
// }
