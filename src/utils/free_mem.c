/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:39:40 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/15 13:26:39 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void ft_free_var(void *var)
{
    if (var)
        free(var);
    return ;
}

void    ft_free_mem(t_data *data)
{
    ft_free_var(data->floor);
    ft_free_var(data->ceiling);
    ft_free_var(data->north_path);
    ft_free_var(data->south_path);
    ft_free_var(data->east_path);
    ft_free_var(data->west_path);
    ft_lstclear(&(data->file), &free);
    return ;
}

void    ft_print_info(t_data *data)
{
    printf("Floor: %d, %d, %d\n", data->floor[0], data->floor[1], data->floor[2]);
    printf("Ceiling: %d, %d, %d\n", data->ceiling[0], data->ceiling[1], data->ceiling[2]);
    printf("North path: %s\n", data->north_path);
    printf("South path: %s\n", data->south_path);
    printf("East path: %s\n", data->east_path);
    printf("West path: %s\n", data->west_path);
    ft_print_file(data->file);
    return ;
}