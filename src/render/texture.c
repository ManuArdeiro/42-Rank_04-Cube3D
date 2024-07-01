/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:15 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 19:37:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Determines the texture index based on the ray's side and direction.
	 -> If the ray hits a vertical wall (side 0), checks the x-direction of the
   		ray.
	 -> If the ray hits a horizontal wall (side 1), checks the y-direction of
	 	the ray. */
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

/*	Updates the texture pixels for the screen column based on the ray
	properties.
   -> Determines the texture index using ft_texture_index().
   -> Calculates the texture's x-coordinate based on the wall hit position.
      -> Adjusts the x-coordinate for texture mirroring if needed.
   -> Calculates the texture step for vertical scaling.
   -> Initializes the texture position for the current column.
   -> Loops through each pixel in the column within the draw range.
      -> Calculates the texture's y-coordinate and updates the texture position.
      -> Retrieves the color from the texture at the calculated coordinates.
      -> Darkens the color if the texture index is NORTH or EAST.
      -> Updates the pixel in the texture_pixels array if the color is valid. */
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
