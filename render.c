#include "raycast.h"

int	rgb_encode(short int red, short int green, short int blue)
{
	t_rgb	color;

	if (red < 0 || red > 255)
		red = 255;
	if (green < 0 || green > 255)
		green = 255;
	if (blue < 0 || blue > 255)
		blue = 255;
	color.rgb[3] = 0;
	color.rgb[2] = red;
	color.rgb[1] = green;
	color.rgb[0] = blue;
	return (color.color);
}

int	render(t_screen *screen)
{
	background(&screen->img, rgb_encode(0, 0, 150));
	// Draw here
	mlx_put_image_to_window(
		screen->mlx,
		screen->window,
		screen->img.mlx_img, 0, 0);
	return (0);
}
