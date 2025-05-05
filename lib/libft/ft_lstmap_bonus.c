/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:56:17 by usoontra          #+#    #+#             */
/*   Updated: 2024/10/15 23:18:24 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_del(t_list *lst)
// {
// 	if (lst)
// 		free((lst)->content);
// 	free(lst);
// 	return (NULL);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f ||!del)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (NULL);
	res = temp;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&temp, del);
		}
		ft_lstadd_back(&res, temp);
		lst = lst->next;
	}
	temp->next = NULL;
	return (res);
}

// void	*f(void *content)
// {
// 	int	i = 0;
// 	char	*str;

// 	str = ft_strdup((char *)content);
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			str[i] = str[i] - 32;
// 		else if (str[i] >= 'A' && str[i] <= 'Z')
// 			str[i] = str[i] + 32;;
// 		i++;
// 	}
// 	content = str;
// 	return ((char *)content);
// }

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
// 	char	*a = "ghjsDFSDkl";
// 	char	*b = "iuSDFSDyt";
// 	char	*c = "fdSDFfg";
// 	t_list	*s1;
// 	t_list	*s2;
// 	t_list	*st;
// 	t_list	**list;
// 	t_list	*test;

// 	printf("a = %s\nb = %s\nc = %s\n", a, b, c);
// 	printf("--------------------------\nlist\n");
// 	s1 = ft_lstnew(a);
// 	list = &s1;
// 	ft_lstadd_back(list, ft_lstnew(c));
// 	print_list(*list);
// 	printf("--------------------------\ns2\n");
// 	s2 = ft_lstnew(b);
// 	print_list(s2);
// 	printf("--------------------------\nft_list\n");
// 	test = ft_lstmap(*list, (void *)f, del);
// 	print_list(test);
// 	printf("--------------------------\nft_s2\n");
// 	st = ft_lstmap(s2, (void *)f, del);
// 	print_list(st);
// }
