#include "raycast.h"

int	exit_raycast(t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img.mlx_img);
	mlx_destroy_image(screen->mlx, screen->walls[S_NO].mlx_img);
	mlx_destroy_image(screen->mlx, screen->walls[S_SO].mlx_img);
	mlx_destroy_image(screen->mlx, screen->walls[S_WE].mlx_img);
	mlx_destroy_image(screen->mlx, screen->walls[S_EA].mlx_img);
	mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	exit(0);
}
