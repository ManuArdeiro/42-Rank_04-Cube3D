/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:04 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/26 14:36:46 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture.texture_pixels[y][x] > 0)
		ft_image_pixel(image, x, y, data->texture.texture_pixels[y][x]);
	else if (y < data->window_height / 2)
		ft_image_pixel(image, x, y, data->texture.hex_ceiling);
	else if (y < data->window_height -1)
		ft_image_pixel(image, x, y, data->texture.hex_floor);
}

static void	ft_render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	ft_mlx_img(data, &image, data->window_width, data->window_height);
	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			ft_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
	return ;
}

void	ft_render_img(t_data *data)
{
	ft_texture_pixels_init(data);
	ft_ray_init(&data->ray);
	ft_raycasting(&data->player, data);
	ft_render_frame(data);
	/*if (BONUS_FLAG)
		ft_render_minimap(data);*/
	return	;
}