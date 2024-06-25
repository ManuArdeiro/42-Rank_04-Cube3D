/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:06:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/25 12:18:01 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_exit(t_data *data, char *error)
{
	perror(error);
	if (data->minimap_img.img && data->mlx)
		mlx_destroy_image(data->mlx, data->minimap_img.img);
	if (data->window && data->mlx)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_mem(data);
	free(data);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *data)
{
	printf(WHITE "\nGame closed!! Come to play again soon :)\n");
	if (data->minimap_img.img && data->mlx)
		mlx_destroy_image(data->mlx, data->minimap_img.img);
	if (data->window && data->mlx)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_mem(data);
	free(data);
	exit(EXIT_SUCCESS);
}
