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

static char	*fill_word(char *str, int start, int end);
static int	word_count(char *str);

int	word_count(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if ((*str != ' ' || *str != '\t' || *str != '\n' || *str != ',')
			&& in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*str == ' ' || *str == '\t' || *str == '\n' || *str == ',')
			in_word = 0;
		str++;
	}
	return (count);
}

char	*fill_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	arr = malloc(sizeof(char *) * (word_count(str) + 1));
	while (i < word_count(str))
	{
		while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'
			|| str[end] == ',')
			end++;
		start = end;
		while (str[end] && str[end] != ' ' && str[end] != '\t'
			&& str[end] != '\n' && str[end] != ',')
			end++;
		arr[i] = fill_word(str, start, end);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
