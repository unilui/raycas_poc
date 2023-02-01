#include "raycast.h"

t_screen	load_mlx(int width, int height)
{
	t_screen	screen;

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
	return (screen);
}
