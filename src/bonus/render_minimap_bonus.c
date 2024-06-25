/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:01:40 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/25 22:35:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_minimap_offset(t_minimap *minimap, int mapsize, int pos)
{
	if (pos > minimap->distance && mapsize - pos > minimap->distance + 1)
		return (pos - minimap->distance);
	if (pos > minimap->distance && mapsize - pos <= minimap->distance + 1)
		return (mapsize - minimap->size);
	return (0);
}

static bool	ft_valid_coordinate(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}

static char	*ft_add_line(t_data *data, t_minimap *mm, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(mm->size + 1, sizeof(line));
	if (!line)
		return (NULL);
	x = 0;
	while (x < mm->size && x < data->map_width)
	{
		if (!ft_valid_coordinate(y + mm->offset_y, data->map_height)
			|| !ft_valid_coordinate(x + mm->offset_x, data->map_width))
			line[x] = '\0';
		else if ((int)data->player.pos_x == (x + mm->offset_x)
			&& (int)data->player.pos_y == (y + mm->offset_y))
			line[x] = 'P';
		else if (data->map[y + mm->offset_y][x + mm->offset_x] == '1')
			line[x] = '1';
		else if (data->map[y + mm->offset_y][x + mm->offset_x] == '0')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	return (line);
}

static char	**ft_create_minimap(t_data *data, t_minimap *minimap)
{
	char	**mini_map;
	int		y;

	mini_map = ft_calloc(minimap->size + 1, sizeof(mini_map));
	if (!mini_map)
		return (NULL);
	y = 0;
	while (y < minimap->size && y < data->map_height)
	{
		mini_map[y] = ft_add_line(data, minimap, y);
		if (!mini_map[y])
		{
			ft_free_matrix((void **)mini_map);
			return (NULL);
		}
		y++;
	}
	return (mini_map);
}

void	ft_render_minimap(t_data *data)
{
	t_minimap	minimap;

	minimap.map = NULL;
	minimap.img = &data->minimap_img;
	minimap.distance = MINIMAP_DISTANCE;
	minimap.size = (2 * minimap.distance) + 1;
	minimap.tile_size = MINIMAP_PXL_SIZE / (2 * minimap.distance);
	minimap.offset_x = ft_minimap_offset(&minimap,
			data->map_width, (int)data->player.pos_x);
	minimap.offset_y = ft_minimap_offset(&minimap,
			data->map_height, (int)data->player.pos_y);
	minimap.map = ft_create_minimap(data, &minimap);
	if (!minimap.map)
		ft_exit(data, "Error: Malloc failed!!\n");
	ft_render_minimap_img(data, &minimap);
	ft_free_matrix((void **)minimap.map);
}
