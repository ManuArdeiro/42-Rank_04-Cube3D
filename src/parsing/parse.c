/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:32:40 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/07 01:54:50 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int  ft_read_map(t_data *data, char *map_path)
{
    int     fd;
    char    *line;
    t_list   *new_line;

    fd = open(map_path, R_OK);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (read(fd, &line, 0) < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	data->map = ft_lstnew(line);
	line = get_next_line(fd);
	while (line)
    {
        new_line = ft_lstnew(line);
		ft_lstadd_back(&(data->map), new_line);
        line = get_next_line(fd);
    }
    //ft_print_map(data->map);
	close(fd);
    return (EXIT_SUCCESS);
}

static void *ft_search_textures(t_data *data, const char *line)
{
    char    *path;

    path = ft_north_texture(line);
    if (path)
        data->north_path = path;
    else
    {
        path = ft_south_texture(line);
        if (path)
            data->south_path = path;
        else
        {
            path = ft_east_texture(line);
            if (path)
                data->east_path = path;
            else
            {
                path = ft_west_texture(line);
                if (path)
                    data->west_path = path;
            }
        }
    }
    return ;
}

static void *ft_search_colors(t_data *data, const char *line)
{
    
}

int ft_parsing(t_data *data, char *map_path)
{
    t_list  *temp;

    if (ft_read_map(data, map_path))
        return (EXIT_FAILURE);
    temp = data->map;
    while (temp)
    {
        ft_search_textures(data, (char *)temp->content)
        
        temp = temp->next;
    }
    
}