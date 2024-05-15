/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:03:45 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/15 18:09:44 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char *ft_read_number(const char *str, int *i)
{
    int     j;
    char    *number;

    j = 0;
    while (ft_is_space(str[*i]))
        (*i)++;
    while (j < 2)
    {
        number[j] = str[*i];
        j++;
        (*i)++;
    }
    number[j] = '\0';
    return (number);
}

static void ft_check_comma(t_data *data, const char *str, int *i)
{
    while (ft_is_space(str[*i]))
        (*i)++;
    if (str[*i] != ',')
    {
        ft_free_mem(&data);
        perror("Error: RGB format not valid!!\n");
        exit(EXIT_FAILURE);
    }
    (*i)++;
    return ;
}

static void ft_check_end(t_data *data, const char *str, int *i)
{
    while (ft_is_space(str[*i]))
        (*i)++;
    if (str[*i] != '\0')
    {
        ft_free_mem(&data);
        perror("Error: RGB format not valid!!\n");
        exit(EXIT_FAILURE);
    }
    return ;
}

void    *ft_floor_rgb(t_data *data, const char *str)
{
    int     i;
    int     j;
    char    *number;

    i = 0;
    j = 0;
    data->floor = malloc(sizeof(int) * 3);
    while (ft_is_space(str[i]))
        i++;
    if (!(str[i] == 'F' && ft_is_space(str[i + 1])))
        return (EXIT_FAILURE);
    i++;
    while (j < 3)
    {
        number = ft_read_number(str, &i);
        if (ft_atoi(number) < 0 || ft_atoi(number) > 255)
            return (EXIT_FAILURE);
        data->floor[j] = ft_atoi(number);
        if (j < 2)
            ft_check_comma(data, str, &i);
        else if (j == 2)
            ft_check_end(data, str, &i);
        j++;      
    }
    return (EXIT_SUCCESS);
}

void    *ft_ceiling_rgb(t_data *data, const char *str)
{
    int     i;
    int     j;
    char    *number;

    i = 0;
    j = 0;
    data->ceiling = malloc(sizeof(int) * 3);
    while (ft_is_space(str[i]))
        i++;
    if (!(str[i] == 'C' && ft_is_space(str[i + 1])))
        return (NULL);
    while (j < 3)
    {
        number = ft_read_number(str, &i);
        if (ft_atoi(number) < 0 || ft_atoi(number) > 255)
            return (EXIT_FAILURE);
        data->ceiling[j] = ft_atoi(number);
        if (j < 2)
            ft_check_comma(data, str, &i);
        else if (j == 2)
            ft_check_end(data, str, &i);
        j++;      
    }
    return (EXIT_SUCCESS);
}
