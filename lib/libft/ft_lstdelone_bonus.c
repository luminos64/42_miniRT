/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:55:52 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 13:53:30 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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

// void	del(void *content)
// {
// 	ft_bzero(content, 0);
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	char	*a = "kjhgfd";
// 	char	*b = "cvbnm";
// 	char	*c = "kjhj";
// 	t_list	*sa;
// 	t_list	*sb;
// 	t_list	*sc;
// 	t_list	**list;

// 	printf("a = %s\nb = %s\nc = %s\n", a, b, c);
// 	printf("---------------------------------\n");
// 	sa = ft_lstnew(a);
// 	sb = ft_lstnew(b);
// 	sc = ft_lstnew(c);
// 	printf("sa = %s\n", (char *)sa->content);
// 	printf("sb = %s\nsc = %s\n", (char *)sb->content, (char *)sc->content);
// 	printf("---------------------------------\n");
// 	list = &sa;
// 	sa->next = sb;
// 	sb->next = sc;
// 	printf("list\n");
// 	print_list(*list);
// 	printf("---------------------------------\n");
// 	ft_lstdelone(sb, del);
// 	sb = NULL;
// 	sa->next = NULL;
// 	printf("list\n");
// 	print_list(*list);
// 	printf("---------------------------------\n");
// 	printf("sa = %s\n", (char *)sa->content);
// 	printf("sb = %s\n", (char *)sb);
// 	printf("sc = %s\n", (char *)sc->content);
// 	printf("---------------------------------\n");
// }
