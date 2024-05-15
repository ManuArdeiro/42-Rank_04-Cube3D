/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:55:05 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/16 00:11:15 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int  ft_check_textures_dup(t_data *data, const char *line)
{
    int i;

    i = 0;
    while (line[i] && ft_is_space(line[i]))
        i++;
    if ((line[i] ==  'N' && data->north_path != NULL) ||
        (line[i] ==  'S' && data->south_path != NULL) ||
        (line[i] ==  'E' && data->east_path != NULL) ||
        (line[i] ==  'W' && data->west_path != NULL) ||
        (line[i] ==  'F' && data->floor != NULL) ||
        (line[i] ==  'C' && data->ceiling != NULL))
    {
        perror("Error: Some texture is defined more than once!!\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int ft_check_map_dup(t_data *data, const char *line)
{
    int i;

    i = 0;
    while (line[i] && ft_is_space(line[i]))
        i++;
    if (line[i] == '1' && data->map != NULL)
    {
        perror("Error: Map is defined more than once!!\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void ft_get_map_edges(t_data *data, t_list **temp, int *start, int *end)
{
    int     i;
    char    *line;
    t_list  *aux;

    i = 0;
    start = INT32_MAX;
    end = 0;
    aux = *temp;
    while (aux->next)
    {
        line = (char*)aux->content;
        while (ft_is_space(line[i]))
            i++;
        if (i < start)
            start = i;
        i = ft_strlen(line) - 1;
        while (ft_is_space(line[i]))
            i--;
        if (i > end)
            end = i;
    }
    data->map_width = end - start + 1;
    return ;
}
