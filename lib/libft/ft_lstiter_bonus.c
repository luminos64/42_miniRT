/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:58 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/09 12:47:20 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f(void *content)
// {
// 	int	i = 0;
// 	// int	c = 5;
// 	char	*str;

// 	str = ft_strdup((char *)content);
// 	while (str[i])
// 	{
// 		str[i] = str[i] + 1;
// 		i++;
// 	}
// 	content = str;
// 	// return (str);
// 	// printf("fc %s\n", (char *)content);
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
// 	char	*a = "ghjkl";
// 	char	*b = "iuyt";
// 	char	*c = "fdfg";
// 	t_list	*s1;
// 	t_list	*s2;
// 	t_list	**list;

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
// 	ft_lstiter(*list, f);
// 	print_list(*list);
// 	printf("--------------------------\nft_s2\n");
// 	ft_lstiter(s2, f);
// 	print_list(s2);
// }
