/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:21 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/06 10:26:59 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
// 	char	*a = "etrt";
// 	char	*b = "mnbvc";
// 	char	*c = "[-poiy]";
// 	t_list	*s;
// 	t_list	**list;
// 	int	i;

// 	printf("a = %s\nb = %s\nc = %s\n", a, b, c);
// 	printf("----------------------------------\n");
// 	s = ft_lstnew(a);
// 	list = &s;
// 	ft_lstadd_front(list, ft_lstnew(b));
// 	ft_lstadd_front(list, ft_lstnew(c));
// 	print_list(*list);
// 	printf("----------------------------------\n");
// 	i = ft_lstsize(*list);
// 	printf("i = %d\n", i);
// 	// while (list)
// 	// {
// 	// 	printf("%d : %s\n", i , (char *)list->content);
// 	// 	list = list->next;
// 	// 	i++;
// 	// }
// }
