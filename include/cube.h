/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:54:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/06/20 22:49:10 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUBE_H
# define  CUBE_H

# ifndef BONUS
#  define BONUS 1
# endif

//	INCLUDES:
////////////////////////////////////////////////////////////////////////////////

# include "../mlx_linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <X11/Xlib.h>

//	CONSTANTS:
/////////////////////////////////////////////////////////////////////////////////

# define PI 3.14159265359
# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 720
# define MOVE_SPEED 0.025
# define ROT_SPEED 0.025
//	Minimap:
# define MINIMAP_PXL_SIZE 128
# define MINIMAP_DISTANCE 5
# define MINIMAP_PLAYER_COLOR 0x0000FF
# define MINIMAP_WALL_COLOR 0x990000
# define MINIMAP_FLOOR_COLOR 0xdddddd
# define MINIMAP_SPACE_COLOR 0x000000

//	ENUMS:
/////////////////////////////////////////////////////////////////////////////////

enum e_texture_index
{
	NORTH = 0,
	EAST = 90,
	SOUTH = 180,
	WEST = 270
};

//	STRUCTS:
/////////////////////////////////////////////////////////////////////////////////

typedef struct	s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

typedef struct	s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_texture
{
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				**texture_pixels;
	int				**textures;
}				t_texture;

typedef struct	s_minimap
{
	int		size;
	int		tile_size;
	int		offset_x;
	int		offset_y;
	char	**map;
	t_img	*img;
}				t_minimap;

typedef struct	s_map
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}				t_map;

typedef struct s_data
{
	int			map_width;
	int			map_height;
	int			window_height;
	int			window_width;
	int			*floor;
	int			*ceiling;
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	char		**map;
	void		*mlx;
	void		*window;
	t_list		*file;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	t_img		minimap;
	t_map		map;
}				t_data;

//  File src/main.c
int			main(int argc, char **argv);

//	File src/bonus/render_bonus.c
void		ft_render_minimap(t_data *data);

//  File src/parsing/checks.c
int			ft_check_textures_dup(t_data *data, const char *line);
int			ft_check_map_dup(t_data *data, const char *line);
void		ft_check_invalid_chars(t_data *data, t_list **temp);

//  File src/parsing/colors.c
int			ft_floor_rgb(t_data *data, const char *str);
int			ft_ceiling_rgb(t_data *data, const char *str);

//  File src/parsing/map.c
int			ft_check_if_map(t_data *data, t_list **temp);

//  File src/parsing/parse.c
int			ft_empty_line(const char *line);
int			ft_parsing(t_data *data, char *map_path);

//  File src/parsing/textures.c
int			ft_check_texture(t_data *data, const char *line, char *cardinal);
int			ft_check_floor(t_data *data, const char *line);
int			ft_check_ceiling(t_data *data, const char *line);

//  File src/parsing/utils.c
void		ft_get_map_edges(t_data *data, t_list **temp, int *start, int *end);
void		ft_save_path(t_data *data, char *path, char *cardinal);
int			ft_vertical_last(t_data *data, int i);
int			ft_horizontal_left_last(const char *line, int i);
int			ft_horizontal_right_last(const char *line, int i);

//  File tests/print_file.c
void		ft_print_file(t_list *file);
void		ft_print_info(t_data *data);

//  File src/utils/free_mem.c
void		ft_free_mem(t_data *data);
void		ft_exit(t_data *data, char *error);

//  File src/utils/inits.c
void		ft_init_data(t_data *data);
void		ft_init_img(t_img *img);

//  File src/utils/mlx.c
void		ft_img(t_data *data, t_img *image, int width, int height);
void		ft_texture(t_data *data, t_img *image, char *path);
void		ft_mlx_start(t_data *data);

//  File src/utils/print.c
void		ft_print_menu(void);

//	COLORS:
////////////////////////////////////////////////////////////////////////////////

# define RESET	"\e[0m"

# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define ITAL	"\e[3m"
# define ULINE	"\e[4m"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

# define BRIGHT_BLACK	"\e[90m"
# define BRIGHT_RED		"\e[91m"
# define BRIGHT_GREEN	"\e[92m"
# define BRIGHT_YELLOW	"\e[93m"
# define BRIGHT_BLUE	"\e[94m"
# define BRIGHT_PURPLE	"\e[95m"
# define BRIGHT_CYAN	"\e[96m"
# define BRIGHT_WHITE	"\e[97m"

# define BG_BLACK	"\e[40m"
# define BG_RED		"\e[41m"
# define BG_GREEN	"\e[42m"
# define BG_YELLOW	"\e[43m"
# define BG_BLUE	"\e[44m"
# define BG_PURPLE	"\e[45m"
# define BG_CYAN	"\e[46m"
# define BG_WHITE	"\e[47m"

# define BG_BRIGHT_BLACK	"\e[100m"
# define BG_BRIGHT_RED		"\e[101m"
# define BG_BRIGHT_GREEN	"\e[102m"
# define BG_BRIGHT_YELLOW	"\e[103m"
# define BG_BRIGHT_BLUE		"\e[104m"
# define BG_BRIGHT_PURPLE	"\e[105m"
# define BG_BRIGHT_CYAN		"\e[106m"
# define BG_BRIGHT_WHITE	"\e[107m"

#endif