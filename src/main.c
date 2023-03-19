/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:28:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/18 21:52:06 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

static void	init_simulation(t_cub *rcast)
{
	memset(rcast, 0, sizeof(t_cub));
	rcast->map.rows = calloc(10, sizeof(char *));
	rcast->map.rows[0] = strdup("1111111111");
	rcast->map.rows[1] = strdup("1000000011");
	rcast->map.rows[2] = strdup("1000011001");
	rcast->map.rows[3] = strdup("1000000001");
	rcast->map.rows[4] = strdup("1000001011");
	rcast->map.rows[5] = strdup("1000011001");
	rcast->map.rows[6] = strdup("1010000001");
	rcast->map.rows[7] = strdup("1000011001");
	rcast->map.rows[8] = strdup("1010100001");
	rcast->map.rows[9] = strdup("1111111111");
	rcast->player.fov = 60;
	rcast->player.fov = rcast->player.fov / 2;
	rcast->player.angle = 90;
	rcast->player.x = 4;
	rcast->player.y = 3;
	rcast->screen = init_screen();
	load_hooks(rcast);
}

int	main(void)
{
	t_cub	rcast;

	init_simulation(&rcast);
	mlx_loop(rcast.screen.mlx);
	return (0);
}
