/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:53:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/06/20 22:49:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_start_game(t_data *data)
{
	ft_mlx_start(data);



	
	game->mlx = mlx_init();
	if (!aux->mlx)
		ft_exit(data, "Error in mlx_init");
	if (mlx_get_screen_size(aux->mlx, &aux->win_size_x, &aux->win_size_y))
		ft_exit(data, "Error in mlx_get_screen_size");
	aux->mlx_window = mlx_new_window(aux->mlx, aux->win_size_x, \
			aux->win_size_y, "Cub3d");
	if (!aux->mlx_window)
		ft_exit(data, "Error in mlx_window");
	mlx_hook(aux->mlx_window, 17, 1L << 17, closewin, data);
	mlx_key_hook(aux->mlx_window, key_select, data);
	mlx_loop(aux->mlx);
}

void	ft_init(t_data *data)
{
	ft_init_data(data);
	
}

static int	ft_check_args(const int argc, const char **argv)
{
	int		i;
	int		ext_len;
	char	*ext;

	ext = ".cub";
	if (argc != 2)
	{
		perror("Error: Invalid number of arguments!!\n");
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
				perror("Error: Wrong file extension!!\n");
				return (EXIT_FAILURE);
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
	{
		perror("Error: error allocating memory!!\n");
		return ( free(data), EXIT_FAILURE);
	}
	ft_init(data);
	if (ft_check_args(argc, (const char **)argv))
		return (ft_free_mem(data), free(data), EXIT_FAILURE);
	if (ft_parsing(data, argv[1]))
		return (ft_free_mem(data), free(data), EXIT_FAILURE);
	ft_print_menu();
	ft_start_game(data);
	return (ft_free_mem(data), free(data), EXIT_SUCCESS);
}
