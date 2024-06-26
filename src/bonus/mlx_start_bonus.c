/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:06:18 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/26 14:30:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
int	ft_mouse_motion(int x, int y, t_data *data)
{
	/*static int	old_x;
	
	old_x = WINDOW_WIDTH / 2;*/
	if (x > data->window_width - MOUSE_WINDOW_LIMIT)
	{
		x = MOUSE_WINDOW_LIMIT;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	if (x < MOUSE_WINDOW_LIMIT)
	{
		x = data->window_width - MOUSE_WINDOW_LIMIT;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	else if (x < data->window_width / 2)
		data->player.has_moved = ft_player_rotate(&data);
	else if (x > data->window_width / 2)
		data->player.has_moved += ft_player_rotate(&data);
	//old_x = x;
	return (EXIT_SUCCESS);
}

void	ft_mlx_mouse(t_data *data)
{
	mlx_mouse_move(data->mlx, data->window, data->window_width / 2, 
		data->window_height / 2);
	return ;
}
