/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:35 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/26 14:07:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_player_rotate(t_data **data)
{
	double		rotspeed;
	double		temp;

	rotspeed = ROT_SPEED * (*data)->player.rotate;
	temp = (*data)->player.dir_x;
	(*data)->player.dir_x = (*data)->player.dir_x * cos(rotspeed)
		- (*data)->player.dir_y * sin(rotspeed);
	(*data)->player.dir_y = temp * sin(rotspeed)
		+ (*data)->player.dir_y * cos(rotspeed);
	temp = (*data)->player.plane_x;
	(*data)->player.plane_x = (*data)->player.plane_x * cos(rotspeed)
		- (*data)->player.plane_y * sin(rotspeed);
	(*data)->player.plane_y = temp * sin(rotspeed)
		+ (*data)->player.plane_y * cos(rotspeed);
	return (1);
}
