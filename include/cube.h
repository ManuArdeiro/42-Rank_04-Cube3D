/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:54:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/17 14:05:06 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUBE_H
# define  CUBE_H

# include "stdio.h"
# include "stdlib.h"
# include "math.h"
# include "stdbool.h"
# include "../mlx/mlx.h"
# include "libft/libft.h"

# define PI 3.14159265359

typedef struct  s_data
{
    int     map_width;
    int     map_height;
    int     *floor;
    int     *ceiling;
    char    *north_path;
    char    *south_path;
    char    *east_path;
    char    *west_path;
    char    **map;
    t_list  *file;
}               t_data;

//  File src/main.c
int	    main(int argc, char **argv);

//  File src/parsing/checks.c
int     ft_check_textures_dup(t_data *data, const char *line);
int     ft_check_map_dup(t_data *data, const char *line);
void    ft_check_invalid_chars(t_data *data, t_list **temp);

//  File src/parsing/colors.c
int     ft_floor_rgb(t_data *data, const char *str);
int     ft_ceiling_rgb(t_data *data, const char *str);

//  File src/parsing/map.c
int     ft_check_if_map(t_data *data, t_list **temp);

//  File src/parsing/parse.c
int     ft_empty_line(const char *line);
int     ft_parsing(t_data *data, char *map_path);

//  File src/parsing/textures.c
int     ft_check_texture(t_data *data, const char *line, char *cardinal);
int     ft_check_floor(t_data *data, const char *line);
int     ft_check_ceiling(t_data *data, const char *line);

//  File src/parsing/utils.c
void    ft_get_map_edges(t_data *data, t_list **temp, int *start, int *end);
int     ft_vertical_last(t_data *data, int i);

//  File tests/print_file.c
void    ft_print_file(t_list *file);
void    ft_print_info(t_data *data);

//  File src/utils/free_mem.c
void    ft_free_mem(t_data *data);


#endif