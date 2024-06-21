/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:39 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/20 21:46:41 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	*ft_xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
		sizeof(buffer * data->texture.size * data->texture.size));
	if (!buffer)
		ft_exit(data, "Error: Malloc failed!!\n");
	y = 0;
	while (y < data->texture.size)
	{
		x = 0;
		while (x < data->texture.size)
		{
			buffer[y * data->texture.size + x]
				= tmp.addr[y * data->texture.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}
