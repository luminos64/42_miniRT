/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:27:41 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/06 11:53:47 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// void	print_list(t_list *lst)
// {
// 	int	i = 0;

// 	while (lst)
// 	{
// 		printf("%d : %s\n", i, (char *)lst->content);
// 		lst = lst->next;
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char	*a = "opiuy";
// 	char	*b = "cvn";
// 	t_list	*s;
// 	t_list	**list;

// 	printf("a = %s\nb = %s\n", a, b);
// 	printf("-----------------------\n");
// 	s = ft_lstnew(a);
// 	list = &s;
// 	ft_lstadd_front(list, ft_lstnew(b));
// 	print_list(*list);
// 	printf("-----------------------\n");
// 	// s = ft_lstlast(*list);
// 	printf("last = %s\n", (char *)ft_lstlast(*list)->content);
// 	// printf("last = %s\n", (char *)s->content);
// 	printf("-----------------------\n");
// }
