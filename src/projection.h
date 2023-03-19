/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/18 21:56:30 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCAST_H
# define RCAST_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SCREEN_HALF_WIDTH 640
# define SCREEN_HALF_HEIGHT 360

# define RAY_PRECISION 1024
# include <stdlib.h>

enum e_wall_direction
{
	W_NO,
	W_SO,
	W_WE,
	W_EA,
	W_COUNT,
};

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endianess;
	int		width;
	int		height;
}	t_img;

typedef struct s_screen
{
	void	*mlx;
	void	*window;
	t_img	buffer;
	t_img	walls[W_COUNT];
}	t_screen;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_map
{
	char	**rows;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_player
{
	int			x;
	int			y;
	double		angle;
	int			fov;
}	t_player;

typedef struct s_cub
{
	t_map		map;
	t_screen	screen;
	t_player	player;
}	t_cub;

typedef struct s_ray
{
	double	x;
	double	y;
}	t_ray;

typedef struct s_hit
{
	double	x;
	double	y;
	int		side;
	double	distance;
}	t_hit;

typedef int				t_color;

t_screen	init_screen(void);

void		load_hooks(t_cub *rcast);

void		pixel_put(t_img *img, int x, int y, t_color color);

t_color		pixel_get(t_img *img, int x, int y);

int			rgb(int r, int g, int b);

void		fill(t_img *img, t_color color);

void		raycasting(t_cub *rcast);

int			render(t_cub *rcast);

#endif // !RCAST_H
