/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:43:34 by usoontra          #+#    #+#             */
/*   Updated: 2025/05/04 19:02:42 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	hook(mlx_key_data_t key, void *param)
{
	t_data	*id;

	id = (t_data *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		ft_putstr_fd("ESC end miniRT\n", 2);
		mlx_terminate(id->mlx);
		free(id->camera);
		free(id->ambient);
		exit(0);
	}
}
