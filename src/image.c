/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:47:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/18 21:34:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	pixel_put(t_img *img, int x, int y, t_color color)
{
	char	*px;

	px = img->data + y * img->line_len + (x * (img->bpp / 8));
	*(unsigned int *)px = color;
}

t_color	pixel_get(t_img *img, int x, int y)
{
	char	*px;

	px = img->data + y * img->line_len + (x * (img->bpp / 8));
	return (*(unsigned int *)px);
}
