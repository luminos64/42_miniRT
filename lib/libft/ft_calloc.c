/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:24:13 by usoontra          #+#    #+#             */
/*   Updated: 2024/10/15 23:18:51 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*ptr;
	size_t	smem;

	smem = nmemb * size;
	if ((long)nmemb < 0 || (long)size < 0)
		return (NULL);
	ptr = (void *)malloc(smem);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, smem);
	return (ptr);
}

// int	main(void)
// {
// 	int	*ptrc;
// 	int	*ptrf;
// 	int	i;
// 	int	size = 5;

// 	ptrc = (int *)calloc(size, sizeof(int));
// 	ptrf = ft_calloc(size, sizeof(int));
// 	printf("size = %d\n", size);
// 	printf("Not Allocate\n");
// 	printf("prtc\tptrf\n");
// 	i = 0;
// 	while (i < size +3)
// 	{
// 		printf("%d\t%d\n", ptrc[i], ptrf[i]);
// 		i++;
// 	}
// 	free(ptrc);
// 	free(ptrf);
// }
