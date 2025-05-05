/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:00:08 by usoontra          #+#    #+#             */
/*   Updated: 2024/09/11 10:13:50 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (*s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static	int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			res[j] = ft_substr(s, i, ft_len(&s[i], c));
			if (!res[j])
				return (ft_free(res, j));
			i = i + ft_len(&s[i], c);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char	a[] = "  tripouille  42  ";
// 	// char	b = '@';
// 	char	**r;
// 	int	i;

// 	i = 0;
// 	printf("a = %s\n", a);
// 	r = ft_split(a, ' ');
// 	while (*r)
// 	{
// 		printf("%s\n", *r++);
// 		// i++;
// 	}
// 	while (*r[i] != '\0')
// 	{
// 		free(r[i]);
// 		i++;
// 	}
// 	free(r);
// }
