/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:01:49 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/25 20:04:58 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*
We initialize the set up for the rays
- camera_x -> Where is the camera (-1 = left, 0 = center, 1 = right)
- dir_x/y = direction of the ray
- map_x/y = current square of the ray
- deltadist_x/y = distance to go to the next x or y.
*/

static void	ft_raycasting_info(int x, t_ray *ray, t_player *player)
{
	ft_ray_init(ray);
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

/*
- We are doing the initial set up for the dda
- dda algorithm will jump one square in each loop eiter in a x or y direction
- ray->sidedist_x or y = distance from the ray start position to the
	next x or y position
- if x or y < 0 go the next x or y to the left
- if x or y > 0 go the next x or y to the right
*/

static void	ft_set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
		printf("\tray->sidedist_x: %f \tray->map_x: %d \tplayer->pos_x: %f \tray->deltadist_x: %f\n", ray->sidedist_x, ray->map_x, player->pos_x, ray->deltadist_x);
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
		printf("\tray->sidedist_x: %f \tray->map_x: %d \tplayer->pos_x: %f \tray->deltadist_x: %f\n", ray->sidedist_x, ray->map_x, player->pos_x, ray->deltadist_x);
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square 
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/

static void	ft_run_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x = ray->sidedist_x + ray->deltadist_x;
			ray->map_x = ray->map_x + ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y = ray->sidedist_y + ray->deltadist_y;
			ray->map_y = ray->map_y + ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->map_data.height - 0.25
			|| ray->map_x > data->map_data.width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

static void	ft_line_length(t_ray *ray, t_data *data, t_player *player)
{
	printf("data->map_width: %d\n", data->map_width);
	printf("data->map_heigh: %d\n", data->map_height);
	printf("data->window_height: %d\n", data->window_height);
	printf("data->window_width: %d\n", data->window_width);
	printf("ray->camera_x: %f\n", ray->camera_x);
	printf("ray->step_x: %d\n", ray->step_x);
	printf("ray->step_y: %d\n", ray->step_y);
	printf("ray->map_x: %d\n", ray->map_x);
	printf("ray->map_y: %d\n", ray->map_y);
	printf("ray->side: %d\n", ray->side);
	printf("ray->dir_x: %f\n", ray->dir_x);
	printf("ray->dir_y: %f\n", ray->dir_y);
	printf("player->pos_x: %f\n", player->pos_x);
	printf("player->pos_y: %f\n", player->pos_y);
	printf("ray->deltadist_x: %f\n", ray->deltadist_x);
	printf("ray->deltadist_y: %f\n", ray->deltadist_y);
	printf("ray->sidedist_x: %f\n", ray->sidedist_x);
	printf("ray->sidedist_y: %f\n", ray->sidedist_y);
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	printf("ray->wall_dist: %f\n", ray->wall_dist);
	ray->line_height = (int)(data->window_height / ray->wall_dist);
	printf("ray->line_height: %d\n", ray->line_height);
	ray->draw_start = -(ray->line_height) / 2 + data->window_height / 2;
	printf("ray->draw_start: %d\n", ray->draw_start);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->window_height / 2;
	if (ray->draw_end >= data->window_height)
		ray->draw_end = data->window_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	printf("ray->wall_x: %f\n", ray->wall_x);
}

int	ft_raycasting(t_player *player, t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = data->ray;
	while (x < data->window_width)
	{
		ft_raycasting_info(x, &ray, player);
		ft_set_dda(&ray, player);
		ft_run_dda(data, &ray);
		ft_line_length(&ray, data, player);
		ft_texture_pixels_update(data, &data->texture, &ray, x);
		x++;
	}
	return (EXIT_SUCCESS);
}
