/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:51:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/18 21:56:13 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

static char	*g_textures[W_COUNT] = {
	"assets/no.xpm",
	"assets/so.xpm",
	"assets/we.xpm",
	"assets/ea.xpm",
};

void	load_texture(t_screen *screen, int side)
{
	t_img	*wall;

	wall = &screen->walls[side];
	wall->ptr = mlx_xpm_file_to_image(
			screen->mlx,
			g_textures[side],
			&wall->width,
			&wall->height);
	wall->data = mlx_get_data_addr(
			wall->ptr,
			&wall->bpp,
			&wall->line_len,
			&wall->endianess);
}

t_screen	init_screen(void)
{
	t_screen	screen;

	memset(&screen, 0, sizeof(t_screen));
	screen.mlx = mlx_init();
	screen.window = mlx_new_window(
			screen.mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"Rcast");
	screen.buffer.ptr = mlx_new_image(screen.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	screen.buffer.data = mlx_get_data_addr(
			screen.buffer.ptr,
			&screen.buffer.bpp,
			&screen.buffer.line_len,
			&screen.buffer.endianess);
	load_texture(&screen, W_NO);
	load_texture(&screen, W_SO);
	load_texture(&screen, W_WE);
	load_texture(&screen, W_EA);
	return (screen);
}

static int	kill_screen(t_cub *rcast)
{
	t_screen	*screen;

	screen = &rcast->screen;
	mlx_destroy_image(screen->mlx, screen->buffer.ptr);
	mlx_destroy_image(screen->mlx, screen->walls[W_NO].ptr);
	mlx_destroy_image(screen->mlx, screen->walls[W_SO].ptr);
	mlx_destroy_image(screen->mlx, screen->walls[W_WE].ptr);
	mlx_destroy_image(screen->mlx, screen->walls[W_EA].ptr);
	mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	free(rcast->map.rows[0]);
	free(rcast->map.rows[1]);
	free(rcast->map.rows[3]);
	free(rcast->map.rows[4]);
	free(rcast->map.rows);
	exit(0);
}

void	load_hooks(t_cub *rcast)
{
	mlx_loop_hook(rcast->screen.mlx, &render, rcast);
	mlx_hook(rcast->screen.window, 17, 0, &kill_screen, rcast);
}
