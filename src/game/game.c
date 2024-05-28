/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 00:53:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/19 19:33:13 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_init_game(t_data *data)
{
	data->game->win_size_x = 0;
	data->game->win_size_y = 0;
	data->game = ft_calloc(sizeof(t_game), 1);
	if (!data->game)
		ft_exit(data, "error in memory");
}

void	ft_get_screen_size(t_data *data)
{
	Display	*display;
	Screen	*screen;

	display = XOpenDisplay(NULL);
	if (display == NULL)
	{
		perror("Can't open fullscreen: ");
		data->game->win_size_x = 800;
		data->game->win_size_y = 800;
		return ;
	}
	screen = DefaultScreenOfDisplay(display);
	data->game->win_size_x = screen->width;
	data->game->win_size_y = screen->height;
	XCloseDisplay(display);
}

void	ft_start_game(t_data *data)
{
	t_game	*aux;

	aux = data->game;
	aux->mlx = mlx_init();
	if (!aux->mlx)
		ft_exit(data, "Error in mlx_init");
	aux->mlx_window = mlx_new_window(aux->mlx, aux->win_size_x, \
		aux->win_size_y, "Cub3d");
	if (!aux->mlx_window)
		ft_exit(data, "Error in mlx_window");
	mlx_loop(aux->mlx);
}
