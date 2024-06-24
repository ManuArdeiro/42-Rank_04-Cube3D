/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:20 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 20:37:51 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (!BONUS_FLAG)
	{
		if (x < 0.25 || x >= data->map_data.width - 1.25)
			return (false);
		if (y < 0.25 || y >= data->map_data.height -0.25)
			return (false);
		return (true);
	}
	if (BONUS_FLAG)
	{
		if (data->map[(int)y][(int)x] == '0')
			return (true);
	}
	return (false);
}

int	ft_move_validation(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = EXIT_FAILURE;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = EXIT_SUCCESS;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = EXIT_SUCCESS;
	}
	return (moved);
}
