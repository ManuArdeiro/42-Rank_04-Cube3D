/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:58:25 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 21:46:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == XK_Left)
		data->player.rotate -= 1;
	else if (key == XK_Right)
		data->player.rotate += 1;
	else if (key == XK_w)
		data->player.move_y = 1;
	else if (key == XK_a)
		data->player.move_x = -1;
	else if (key == XK_s)
		data->player.move_y = -1;
	else if (key == XK_d)
		data->player.move_x = 1;
	return (EXIT_SUCCESS);
}

static int	ft_key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	else if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	else if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	else if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	else if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	else if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (EXIT_SUCCESS);
}

static int	ft_mouse_motion(int x, int y, t_data *data)
{
	static int	old_x;
	
	old_x = WINDOW_WIDTH / 2;
	if (x > data->window_width - MOUSE_STEP)
	{
		x = MOUSE_STEP;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	if (x < MOUSE_STEP)
	{
		x = data->window_width - MOUSE_STEP;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->player.has_moved = ft_player_rotate(&data);
	else if (x > old_x)
		data->player.has_moved += ft_player_rotate(&data);
	old_x = x;
	return (EXIT_SUCCESS);
}

void	ft_user_input(t_data *data)
{
	mlx_hook(data->window, X_EVENT_EXIT, 0, ft_close, data);
	mlx_hook(data->window, X_EVENT_KEY_RELEASE, 0, ft_key_press, data);
	mlx_hook(data->window, X_EVENT_KEY_RELEASE, 0, ft_key_release, data);
	if (BONUS_FLAG)
		mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_mouse_motion,
			data);
	return ;
}
