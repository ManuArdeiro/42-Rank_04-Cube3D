/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:53:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/07 02:01:10 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void ft_init_data(t_data *data)
{
    data->floor = NULL;
    data->ceiling = NULL;
    data->north_path = NULL;
    data->south_path = NULL;
    data->east_path = NULL;
    data->west_path = NULL;
    return ;
}

static void ft_free_data(t_data *data)
{
    free(data->floor);
    free(data->ceiling);
    free(data->north_path);
    free(data->south_path);
    free(data->east_path);
    free(data->west_path);
}

static int  ft_check_args(const int argc, const char **argv)
{
    int     i;
    int     ext_len;
    char    *ext;

    ext = ".cub";
    if (argc != 2)
    {
        perror("Invalid number of arguments!!\n");
        return (EXIT_FAILURE);
    }
    else
    {
        ext_len = ft_strlen(argv[1]);
        i = ext_len - 4;
        while (i < ext_len)
        {
            if (argv[1][i] != ext[i - ext_len + 4])
            {
                perror("Wrong map extension!!\n");
                return (EXIT_FAILURE);
            }
            i++;
        }
    }
    return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
    t_data  data;

    (void)data;
    ft_init(&data);
    if (ft_check_args(argc, (const char **)argv))
        return (EXIT_FAILURE);
    if (ft_parsing(&data, argv[1]))
        return (EXIT_FAILURE);
    ft_free_data(&data);
    return (EXIT_SUCCESS);
}