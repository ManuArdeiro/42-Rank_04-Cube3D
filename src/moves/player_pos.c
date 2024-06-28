/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:20 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/27 17:48:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	ft_valid_pos(t_data *data, double x, double y)
{
	if (!BONUS_FLAG)
	{
		if (x < 0.50 || x >= data->map_width - 1.25)
			return (EXIT_FAILURE);
		if (y < 0.25 || y >= data->map_height -0.25)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (BONUS_FLAG)
	{
		if (data->map[(int)y][(int)x] != '1')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_move_validation(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = EXIT_FAILURE;
	if (ft_valid_pos(data, new_x, data->player.pos_y) == EXIT_SUCCESS)
	{
		data->player.pos_x = new_x;
		moved = EXIT_SUCCESS;
	}
	if (ft_valid_pos(data, data->player.pos_x, new_y) == EXIT_SUCCESS)
	{
		data->player.pos_y = new_y;
		moved = EXIT_SUCCESS;
	}
	return (moved);
}
