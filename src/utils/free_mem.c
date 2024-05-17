/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:39:40 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/17 14:02:20 by Ardeiro          ###   ########.fr       */
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
