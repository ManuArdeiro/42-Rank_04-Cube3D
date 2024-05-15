/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:31:48 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/16 00:32:23 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void ft_check_upper_map_line(t_data *data, const char *line,
            const int start, const int end)
{
    int i;
    int j;

    i = start;
    while (line [i] && i < end)
    {
        if (line[i] != '1' && line[i] != ' ')
        {
            perror("Error: Invalid line in map!!\n");
            ft_free_mem(&data);
            exit(EXIT_FAILURE);
        }
        else
            data->map[0][i] = line[i];
        i++;
    }
    return ;
}

static void ft_check_map_lines(t_data *data, t_list **temp)
{
    
    return ;
}

static void ft_read_map(t_data *data, t_list **temp, const int start,
            const int end)
{
    char    *line;
    char    **next_line;

    line = (char)(*temp)->content;
    ft_check_upper_map_line(data, line, start, end);
    while ((*temp)->next)
    {
        (*temp) = (*temp)->next;
        line = (char*)(*temp)->content;
        if ((*temp)->next)
            next_line = (char*)(*temp)->next->content;
        else
            ft_check_border_map_line(data, line);
    }
    



    line = (char)(*temp)->content;
    if ((*temp)->next->content)
        next_line = (char*)(*temp)->next->content;
    else
    {
        perror("Error: Insuficient lines of map!!\n");
        ft_free_mem(&data);
        exit(EXIT_FAILURE);
    }
    while ((*temp)->next)
    {
    }
    ft_check_map_lines(data, temp);
    return ;
}

int  ft_check_if_map(t_data *data, t_list **temp)
{
    int     i;
    int     start;
    int     end;
    char    *line;

    i = 0;
    line = (char)(*temp)->content;
    while (ft_is_space(line[i]))
        i++;
    if (line[i] == '1')
    {
        ft_get_map_edges(data, temp, &start, &end);
        ft_read_map(data, temp, start, end);
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}
