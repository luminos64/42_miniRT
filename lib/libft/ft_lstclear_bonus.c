/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:28:01 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 12:45:59 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

// void	del(void *content)
// {
// 	ft_bzero(content, 0);
// }

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
// 	char	*a = "lkjhg";
// 	char	*b = "yuiop";
// 	t_list	*s;
// 	t_list	**list;

// 	printf("a = %s\nb = %s\n", a, b);
// 	printf("------------------\n");
// 	s = ft_lstnew(a);
// 	list = &s;
// 	ft_lstadd_back(list, ft_lstnew(b));
// 	print_list(*list);
// 	printf("------------------\n");
// 	ft_lstclear(list, del);
// 	print_list(*list);
// 	printf("------------------\n");
// }
