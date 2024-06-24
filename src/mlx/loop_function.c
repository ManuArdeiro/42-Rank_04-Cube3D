/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:09:37 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 18:30:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_render_loop(t_data *data)
{
	int moved;
	
	moved = ft_player_move(data);
	data->player.has_moved = data->player.has_moved + moved;
	if (data->player.has_moved == 0)
		return (EXIT_SUCCESS);
	ft_render_img(data);
	return (EXIT_SUCCESS);
}
