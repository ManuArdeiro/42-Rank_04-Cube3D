/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:54:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/07 01:57:08 by Ardeiro          ###   ########.fr       */
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
    int     *floor;
    int     *ceiling;
    char    *north_path;
    char    *south_path;
    char    *east_path;
    char    *west_path;
    t_list  *map;
}               t_data;


//  File src/main.c
int	        main(int argc, char **argv);

//  File src/parsing/parse.c
int         ft_parsing(t_data *data, char *map_path);

//  File src/parsing/textures.c
char        *ft_north_texture(char *str);
char        *ft_south_texture(char *str);
char        *ft_east_texture(char *str);
char        *ft_west_texture(char *str);

//  File tests/print_map.c
void        ft_print_map(t_list *map);


#endif