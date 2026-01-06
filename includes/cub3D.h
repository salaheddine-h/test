/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:59:59 by salhali           #+#    #+#             */
/*   Updated: 2025/12/08 12:25:26 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_WIDTH 1470
# define SCREEN_HEIGHT 890
# define ESC_KEY 53
# define MOVE_SPEED 5
# define ROT_SPEED 0.03
# define FOV_ANGLE 60.0
# define NUM_RAYS SCREEN_WIDTH
# define TILE_SIZE 45
# define EXIT_FAILURE 1

typedef struct s_alloc
{
	void			*ptr;
	struct s_alloc	*next;
}					t_alloc;

typedef struct s_ray
{
	double			angle;
	double			distance;
	double			hit_x;
	double			hit_y;
	int				side;
	double			raydirx;
	double			raydiry;
}					t_ray;

typedef struct s_ray_coords
{
	double			player_x;
	double			player_y;
	double			hit_x;
	double			hit_y;
}					t_ray_coords;

typedef struct s_raycast
{
	double			ray_angle;
	double			raydirx;
	double			raydiry;
	int				map_x;
	int				map_y;
	double			delta_x;
	double			delta_y;
	double			side_distx;
	double			side_disty;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_raycast;

typedef struct s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

typedef struct s_wall_params
{
	double			perp_dist;
	double			proj_plane_dist;
	int				wall_height;
	int				draw_start;
	int				draw_end;
	int				x;
	int				tex_x;
}					t_wall_params;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_player
{
	double			x;
	double			y;
	char			dir;
	double			angle;
}					t_player;

typedef struct s_map
{
	char			**map;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*floor_color;
	char			*ceiling_color;
	t_rgb			floor_rgb;
	t_rgb			ceiling_rgb;
	t_player		player;
	int				map_height;
}					t_map;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_keys			keys;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	t_ray			*rays;
	t_texture		wall_texture[4];
	t_texture		floor;
	t_texture		ceiling;
}					t_game;

t_alloc				**g_allocs(void);
void				printf_all_struct(t_map *map);
void				free_split(char **arr);
void				error_print(char *str);
int					ft_strcmp(const char *dest, const char *src);
void				start_parsing(int ac, char *av, t_map *map);
void				map_init(t_map *map);
void				save_player(t_map *map);
void				map_parser(int fd, t_map *map);
void				parse_colors(t_map *map);
char				*ft_substr_plus(char *string);
void				parse_textures(t_map *map);
void				save_colors(char *line, t_map *map);
void				save_texture_helper(char *line, t_map *map);
void				save_textures(char *line, t_map *map);
void				file_parser(int fd, t_map *map);
int					ft_atoi_helper(char *str, int *i, long *res);
long				ft_atomic_atoi(char *str);
void				parse_rgb(t_map *map);
void				parser_colors(t_map *map);
bool				check_path(char *path);
bool				check_rgb(t_rgb rgb);
bool				check_valid_map_help(char **map2d, int i, int j);
bool				check_comma(char *str);
bool				check_file_extension(char *av);
bool				check_valid_map(char *map);
bool				check_map(char *map);
bool				check_valid_chars(char *map);
bool				check_newline(char *map);
bool				is_all_whitespace(char *str);
void				init_player_position(t_map *map, int i, int j);
void				set_player_angle(t_map *map);
bool				is_player_char(char c);
int					close_window(t_game *game);
int					key_press(int keycode, t_game *game);
void				start_game(t_map *map);
int					is_wall(t_map *map, double x, double y);
void				update_game(t_game *game);
t_game				*g_game(void);
int					key_release(int keycode, t_game *g);
int					update_player(t_game *game);
void				put_pixel(t_game *game, int x, int y, int color);
int					moves(void);
void				cast_ray_2d(t_game *game, double ray_angle);
void				init_keys(t_keys *keys);
void				init_ray_2d(t_raycast *r, t_ray_coords *c,
						double ray_angle);
double				safe_inverse(double value);
void				calculate_hit_point(t_raycast *r, t_ray_coords *c);
int					raycast_loop(t_game *game, t_raycast *r);
void				cast_all_rays(t_game *game);
void				render_3d_walls(t_game *game);
void				ft_up(void);
void				ft_down(void);
void				ft_right(void);
void				ft_left(void);
void				init_mlx(t_game *game);
void				init_game_resources(t_game *game);
int					calculate_texture_x(t_texture *tex, t_ray *ray);
unsigned int		get_pixel_from_texture(t_texture *tex, int tex_x,
						int tex_y);
t_texture			*select_wall_texture(t_game *game, int side, t_ray *ray);
double				calculate_wall_x(t_ray *ray, int side);
void				draw_wall_strip(t_game *game, int x,
						double player_angle_rad);
void				draw_floor_and_ceiling(t_game *game, int x);
void				cast_single_ray(t_game *game, int i, double ray_angle);
void				draw_wall_column(t_game *game, t_wall_params *params,
						t_texture *tex);
void				*ft_malloc(size_t size);
void				ft_free_all(void);
void				cleanup_game(t_game *game);
void				free_map(t_map *map);
void				load_textures(t_game *game);
void				load_textures_helper(t_game *game, t_texture *texture,
						char *path);
void				free_map_colors(t_map *map);
void				free_map_textures(t_map *map);
void				free_map_array(t_map *map);
void				destroy_textures(t_game *game);
void				destroy_mlx_resources(t_game *game);
void				add_allocation(void *ptr);
void				free_all_allocations(void);
char	*ft_strdup2(const char *s);
#endif