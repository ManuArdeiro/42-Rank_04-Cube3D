/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:03:07 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/25 12:32:17 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mlx_img(t_data *data, t_img *image, int width, int height)
{
	ft_img_init(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		ft_exit(data, "Error: not possible to create mlx image!!\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_texture_img(t_data *data, t_img *image, char *path)
{
	ft_img_init(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texture.size,
			&data->texture.size);
	if (image->img == NULL)
		ft_exit(data, "Error: not possible to create mlx texture!!\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_mlx_start(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data, "Error: mlx_init failed!!\n");
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube");
	if (!data->window)
		ft_exit(data, "Error: mlx_new_window failed!!\n");
	if (BONUS_FLAG)
		ft_mlx_mouse(data);
	return ;
}
