#include "raycast.h"
#include <string.h>

static char *walls_xpm_files[W_COUNT] = {
	"assets/no.xpm",
	"assets/so.xpm",
	"assets/we.xpm",
	"assets/ea.xpm"
};

static void	load_wall_sprite(t_screen *screen, int wall)
{
	char	*xpm_file;

	xpm_file = walls_xpm_files[wall];
	screen->walls[wall].mlx_img = mlx_xpm_file_to_image(
			screen->mlx,
			xpm_file,
			&screen->walls[W_NORTH].width,
			&screen->walls[W_NORTH].height);
	screen->walls[wall].addr = mlx_get_data_addr(
			screen->walls[wall].mlx_img,
			&screen->walls[wall].bpp,
			&screen->walls[wall].line_len,
			&screen->walls[wall].endian);
}

t_screen	load_mlx(int width, int height)
{
	t_screen	screen;

	memset(&screen, 0, sizeof(t_screen));
	screen.mlx = mlx_init();
	screen.window = mlx_new_window(
			screen.mlx,
			width,
			height,
			"Proof of concept");
	screen.img.mlx_img = mlx_new_image(
			screen.mlx,
			width,
			height);
	screen.img.addr = mlx_get_data_addr(
			screen.img.mlx_img,
			&screen.img.bpp,
			&screen.img.line_len,
			&screen.img.endian);
	load_wall_sprite(&screen, W_NORTH);
	load_wall_sprite(&screen, W_SOUTH);
	load_wall_sprite(&screen, W_WEST);
	load_wall_sprite(&screen, W_EAST);
	return (screen);
}
