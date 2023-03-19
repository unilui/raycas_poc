/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:45:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/18 21:34:32 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int	render(t_cub *rcast)
{
	raycasting(rcast);
	mlx_put_image_to_window(
		rcast->screen.mlx,
		rcast->screen.window,
		rcast->screen.buffer.ptr, 0, 0);
	usleep(20000);
	rcast->player.angle += 0.2;
	if (rcast->player.angle > 360)
		rcast->player.angle -= 360;
	return (0);
}
