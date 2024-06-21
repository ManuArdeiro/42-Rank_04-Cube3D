/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:56:49 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/20 22:50:30 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_set_pixel_addr(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	ft_img(t_data *data, t_img *image, int width, int height)
{
	ft_init_img(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		ft_exit(data, "Error: not possible to create image!!\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_texture(t_data *data, t_img *image, char *path)
{
	ft_init_img(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size,
			&data->texinfo.size);
	if (image->img == NULL)
		ft_exit(data, "Error: not possible to create image!!\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_mlx_start(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data, "Error: not possible to start mlx!!\n");
	data->window = mlx_new_window(data->mlx,
		WINDOW_WIDTH, WINDOW_HEIGHT, "Cube");
	if (!data->window)
		ft_exit(data, "Error: not possible to create  mlx window!!\n");
	if (BONUS)
		mlx_mouse_move(data->mlx, data->window,
			data->window_height / 2, data->window_height / 2);
	return ;
}