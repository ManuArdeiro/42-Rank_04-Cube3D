/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:15 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/23 02:03:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texture.index = WEST;
		else
			data->texture.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texture.index = SOUTH;
		else
			data->texture.index = NORTH;
	}
}

void	ft_texture_pixels_update(t_data *data, t_texture *texture,
			t_ray *ray, int x)
{
	int			y;
	int			color;

	ft_texture_index(data, ray);
	texture->x = (int)(ray->wall_x * texture->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		texture->x = texture->size - texture->x - 1;
	texture->step = 1.0 * texture->size / ray->line_height;
	texture->pos = (ray->draw_start - data->window_height / 2
			+ ray->line_height / 2) * texture->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texture->y = (int)texture->pos & (texture->size - 1);
		texture->pos += texture->step;
		color = data->texture.texture[texture->index]
			[texture->size * texture->y + texture->x];
		if (texture->index == NORTH || texture->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture.texture_pixels[y][x] = color;
		y++;
	}
}
