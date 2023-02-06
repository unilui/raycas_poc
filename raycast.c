#include "raycast.h"

int	main(int argc, char **argv)
{
	t_screen screen;

	screen = load_mlx(SCREEN_WIDTH, SCREEN_HEIGHT);
	load_hooks(&screen);
	mlx_loop(screen.mlx);
	return (0);
}
