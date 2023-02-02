#include "raycast.h"

void	load_hooks(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, &render, screen);
	mlx_hook(screen->window, 17, 0, &exit_raycast, screen);
}
