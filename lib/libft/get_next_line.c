/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:25 by usoontra          #+#    #+#             */
/*   Updated: 2024/11/05 17:29:00 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_next(char *buffer, int *bytes)
{
	int	len;

	len = 0;
	while (buffer[len] != '\0' && len < *bytes)
	{
		if (buffer[len] == '\n')
			return (len + 1);
		len++;
	}
	if (buffer[len] == '\n')
		len++;
	return (len);
}

static void	shift_buffer(char *buffer, size_t len)
{
	size_t	i;

	i = 0;
	while (len + i < ft_strlen(buffer))
	{
		*(buffer + i) = *(buffer + len + i);
		i++;
	}
	*(buffer + i) = '\0';
}

static char	*fill_line(char *line, char *buffer, int len)
{
	char	*temp;
	char	*res;
	int		i;

	if (len == 0)
		return (NULL);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = *buffer++;
	res[i] = '\0';
	if (!line)
		line = res;
	else
	{
		temp = line;
		line = ft_strjoin(line, res);
		free(res);
		free(temp);
	}
	return (line);
}

static char	*ft_reader(int fd, char *buffer, char *line)
{
	static int	bytes;
	int			len;

	while (1)
	{
		if (bytes > 0)
		{
			len = find_next(buffer, &bytes);
			line = fill_line(line, buffer, len);
			if (buffer[len - 1] == '\n')
			{
				shift_buffer(buffer, len);
				return (line);
			}
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(line), NULL);
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_reader(fd, buffer, line);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	fd = open("get_next_line.c", O_RDONLY);
// 	char	*line;
// 	int	i;

// 	i = 1;
// 	while (i <= 27)
// 	{
// 		line = get_next_line(fd);
// 		printf("%2d | %s", i, line);
// 		if (!line)
// 			printf("\n");
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
