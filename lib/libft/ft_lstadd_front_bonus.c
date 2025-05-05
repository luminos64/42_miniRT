/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:26:39 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/08 21:32:02 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// void print_list(t_list *lst) {
// 	size_t	i;

// 	i = 0;
// 	while (lst) {
// 		printf("%zu:%s\n", i, (char *)lst->content);
// 		lst = lst->next;
// 		i++;
// 	}
// }

// void	del(void *content)
// {
// 	ft_bzero(content, 0);
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	if (!lst)
// 		return ;
// 	temp = lst;
// 	del(lst->content);
// 	free(temp);
// }

// int	main(void)
// {
// 	char	*a = "dfgh";
// 	char	*b = "werty";
// 	t_list	*s1;
// 	t_list	**list;

// 	printf("a = %s\nb = %s\n", a, b);
// 	printf("------------------------\n");
// 	s1 = ft_lstnew(a);
// 	list = &s1;
// 	ft_lstadd_front(list, ft_lstnew(b));
// 	print_list(*list);
// 	ft_lstclear(list, del);
// 	// print_list(*list);
// 	// free(list);
// }
