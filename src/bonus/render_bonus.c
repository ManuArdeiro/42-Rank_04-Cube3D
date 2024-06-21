/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:27:55 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/20 22:50:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
				ft_set_pixel_addr(minimap->img, x, y, color);
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
			draw_minimap_tile(minimap, x, y);
			x++;
		}
		y++;
	}
	ft_minimap_border(minimap, MINIMAP_SPACE_COLOR);
	return ;
}

void	ft_render_minimap_image(t_data *data, t_minimap *minimap)
{
	int	img_size;

	img_size = MINIMAP_PXL_SIZE + minimap->tile_size;
	ft_img(data, &data->minimap, img_size, img_size);
	ft_draw_minimap(minimap);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img,
		minimap->tile_size, data->win_height
		- (MMAP_PIXEL_SIZE + (minimap->tile_size * 2)));
	mlx_destroy_image(data->mlx, data->minimap.img);
	return ;
}

void	ft_render_minimap(t_data *data)
{
	t_minimap	minimap;

	minimap.map = NULL;
	minimap.img = &data->minimap;
	minimap.size = (2 * MINIMAP_DISTANCE) + 1;
	minimap.tile_size = MINIMAP_PXL_SIZE / (2 * MINIMAP_DISTANCE);
	minimap.offset_x = get_mmap_offset(&minimap,
			data->map.width, (int)data->player.pos_x);
	minimap.offset_y = get_mmap_offset(&minimap,
			data->map.height, (int)data->player.pos_y);
	minimap.map = generate_minimap(data, &minimap);
	if (!minimap.map)
		ft_exit(data, "Error: Malloc failed!!\n");
	ft_render_minimap_image(data, &minimap);
	free_tab((void **)minimap.map);
	return ;
}
