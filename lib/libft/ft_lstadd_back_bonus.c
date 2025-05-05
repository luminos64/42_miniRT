/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:07:17 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/08 19:51:10 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
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
// 	char	*a = "";
// 	char	*b = "kjh";
// 	t_list	*s;
// 	t_list	**list;

// 	printf("a = %s\nb = %s\n", a, b);
// 	printf("------------------------\n");
// 	s = ft_lstnew(a);
// 	list = &s;
// 	print_list(*list);
// 	printf("------------------------\n");
// 	ft_lstadd_back(list, ft_lstnew(b));
// 	print_list(*list);
// 	printf("------------------------\n");
// }
