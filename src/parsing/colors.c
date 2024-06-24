/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:03:45 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/24 23:02:04 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_read_rgb(t_data *data, const char *str, char *number, int *i)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		number = ft_read_number(str, i);
		if (ft_atoi(number) < 0 || ft_atoi(number) > 255)
		{
			free(number);
			ft_exit(data, "Error: Invalid RGB value!!\n");
		}
		data->floor[j] = ft_atoi(number);
		free(number);
		if (j < 2)
			ft_check_comma(data, str, i);
		else if (j == 2)
			ft_check_end(data, str, i);
		j++;
	}
	return ;
}

int	ft_floor_rgb(t_data *data, const char *str)
{
	int		i;
	char	*number;

	i = 0;
	data->floor = malloc(sizeof(int) * 3);
	if (!data->floor)
		return (EXIT_FAILURE);
	while (ft_is_space(str[i]))
		i++;
	if (!(str[i] == 'F' && ft_is_space(str[i + 1])))
		return (EXIT_FAILURE);
	i++;
	ft_read_rgb(data, str, number, &i);
	data->texture.hex_floor = ft_rgb_to_hex(data->floor);
	return (EXIT_SUCCESS);
}

int	ft_ceiling_rgb(t_data *data, const char *str)
{
	int		i;
	char	*number;

	data->ceiling = malloc(sizeof(int) * 3);
	if (!data->ceiling)
		return (EXIT_FAILURE);
	while (ft_is_space(str[i]))
		i++;
	if (!(str[i] == 'C' && ft_is_space(str[i + 1])))
		return (EXIT_FAILURE);
	i++;
	ft_read_rgb(data, str, number, &i);
	data->texture.hex_ceiling = ft_rgb_to_hex(data->ceiling);
	return (EXIT_SUCCESS);
}
