/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:01:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 13:00:49 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_set_pixels(t_minimap *minimap, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			ft_image_pixel(minimap->img, x + j, i + y, color);
			j++;
		}
		i++;
	}
}

static void	ft_minimap_tile(t_minimap *minimap, int x, int y)
{
	if (minimap->map[y][x] == 'P')
		ft_set_pixels(minimap, x * minimap->tile_size,
			y * minimap->tile_size, MINIMAP_PLAYER_COLOR);
	else if (minimap->map[y][x] == '1')
		ft_set_pixels(minimap, x * minimap->tile_size,
			y * minimap->tile_size, MINIMAP_WALL_COLOR);
	else if (minimap->map[y][x] == '0')
		ft_set_pixels(minimap, x * minimap->tile_size,
			y * minimap->tile_size, MINIMAP_FLOOR_COLOR);
	else if (minimap->map[y][x] == ' ')
		ft_set_pixels(minimap, x * minimap->tile_size,
			y * minimap->tile_size, MINIMAP_SPACE_COLOR);
}

static void	ft_minimap_border(t_minimap *minimap, int color)
{
	int	size;
	int	x;
	int	y;

	size = MINIMAP_PXL_SIZE + minimap->tile_size;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x <= size)
		{
			if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
				ft_image_pixel(minimap->img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	ft_draw_minimap(t_minimap *minimap)
{
	int	x;
	int	y;

	y = 0;
	while (y < minimap->size)
	{
		x = 0;
		while (x < minimap->size)
		{
			if (!minimap->map[y] || !minimap->map[y][x]
				|| minimap->map[y][x] == '\0')
				break ;
			ft_minimap_tile(minimap, x, y);
			x++;
		}
		y++;
	}
	ft_minimap_border(minimap, MINIMAP_SPACE_COLOR);
}

void	ft_render_minimap_img(t_data *data, t_minimap *minimap)
{
	int	img_size;

	img_size = MINIMAP_PXL_SIZE + minimap->tile_size;
	ft_mlx_img(data, &data->minimap_img, img_size, img_size);
	ft_draw_minimap(minimap);
	mlx_put_image_to_window(data->mlx, data->window,
		data->minimap_img.img, minimap->tile_size,
		data->window_height - (MINIMAP_PXL_SIZE + (minimap->tile_size * 2)));
	mlx_destroy_image(data->mlx, data->minimap_img.img);
}
