/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:42 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 17:52:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_free_var(void *var)
{
	if (var)
		free(var);
	return ;
}

void	ft_free_matrix(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
	return ;
}

void	ft_free_mem(t_data *data)
{
	int	i;

	i = 0;
	ft_free_var(data->floor);
	ft_free_var(data->ceiling);
	ft_free_var(data->north_path);
	ft_free_var(data->south_path);
	ft_free_var(data->east_path);
	ft_free_var(data->west_path);
	while (i < 100)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->texture.texture[NORTH]);
	free(data->texture.texture[EAST]);
	free(data->texture.texture[SOUTH]);
	free(data->texture.texture[WEST]);
	free(data->texture.texture);
	ft_lstclear(&(data->file), &free);
	return ;
}

void	ft_exit(t_data *data, char *error)
{
	perror(error);
	if (data->window && data->mlx)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_mem(data);
	free(data);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *data)
{
	printf(WHITE "\nGame closed!! Come to play again soon :)\n");
	if (data->window && data->mlx)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_mem(data);
	free(data);
	exit(EXIT_SUCCESS);
}
