/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:35:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/20 22:41:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_init_data(t_data *data)
{
	int	i;

	i = 0;
	data->map_width = -1;
	data->map_height = -1;
	data->window_height = WINDOW_HEIGHT;
	data->window_width = WINDOW_WIDTH;
	data->floor = NULL;
	data->ceiling = NULL;
	data->north_path = NULL;
	data->south_path = NULL;
	data->east_path = NULL;
	data->west_path = NULL;
	data->map = ft_calloc(100, sizeof(char *));
	if (!data->map)
		ft_exit(data, "Error: Malloc failed!!\n");
	while (i < 100)
	{
		data->map[i] = ft_calloc(100, sizeof(char));
		if (!data->map[i])
			ft_exit(data, "Error: Malloc failed!!\n");
		i++;
	}
	data->mlx = NULL;
	data->window = NULL;
	return ;
}

void	ft_init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	ft_init_textures(t_data *data)
{
	t_texture texture;

	texture.textures = ft_calloc(5, sizeof(texture.textures)))
	if (!texture.textures)
		ft_exit(data, "Error: allocating memory for textures!!\n");
	texture.textures[NORTH] = xpm_to_img(data, data->north_path);
	texture.textures[SOUTH] = xpm_to_img(data, data->south_path);
	texture.textures[EAST] = xpm_to_img(data, data->east_path);
	texture.textures[WEST] = xpm_to_img(data, data->west_path);
	return ;
}
