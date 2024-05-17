/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:55:05 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/17 14:01:42 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    ft_get_map_edges(t_data *data, t_list **temp, int *start, int *end)
{
    int     i;
    char    *line;
    t_list  *aux;

    i = 0;
    *start = INT32_MAX;
    *end = 0;
    aux = *temp;
    while (aux->next)
    {
        line = (char*)aux->content;
        while (ft_is_space(line[i]))
            i++;
        if (i < *start)
            *start = i;
        i = ft_strlen(line) - 1;
        while (ft_is_space(line[i]))
            i--;
        if (i > *end)
            *end = i;
    }
    data->map_width = *end - *start + 1;
    return ;
}

int ft_vertical_last(t_data *data, int i)
{
    int j;

    j = data->map_height - 1;
    while (ft_is_space(data->map[j][i]))
        j--;
    if (data->map[j + 1][i] == '1')
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}
