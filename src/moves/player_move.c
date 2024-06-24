/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:01 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 21:46:49 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_move_player_front(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

static int	ft_move_player_back(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

static int	ft_move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

static int	ft_move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

int	ft_player_move(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved = moved + ft_move_player_front(data);
	if (data->player.move_y == -1)
		moved = moved + ft_move_player_back(data);
	if (data->player.move_x == -1)
		moved = moved + ft_move_player_left(data);
	if (data->player.move_x == 1)
		moved = moved + ft_move_player_right(data);
	if (data->player.rotate != 0)
		moved = moved + ft_player_rotate(&data);
	return (moved);
}
