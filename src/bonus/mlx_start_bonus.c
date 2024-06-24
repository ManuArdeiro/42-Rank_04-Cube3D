/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:06:18 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/21 18:08:51 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mlx_mouse(t_data *data)
{
	mlx_mouse_move(data->mlx, data->window, data->window_width / 2, 
		data->window_height / 2);
	return ;
}
