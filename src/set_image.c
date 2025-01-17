/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:13:36 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	argb_to_int(t_color color)
{
	int	rgb;

	rgb = 0;
	rgb += color.a << 24;
	rgb += color.r << 16;
	rgb += color.g << 8;
	rgb += color.b;
	return (rgb);
}

void	print_first_background(t_data *data)
{
	int			x;
	int			y;
	int			ceiling_color;
	int			floor_color;
	t_graphics	*g;

	g = &data->graphics;
	ceiling_color = argb_to_int(g->wall_sprite.ceiling_color);
	floor_color = argb_to_int(g->wall_sprite.floor_color);
	x = 0;
	while ((int)WIN_WIDTH > x)
	{
		y = 0;
		while ((int)WIN_HEIGHT > y)
		{
			if (y < (int)WIN_HEIGHT / 2)
				mlx_set_image_pixel \
				(g->mlx, g->game.img_background, x, y, ceiling_color);
			else
				mlx_set_image_pixel \
				(g->mlx, g->game.img_background, x, y, floor_color);
			y++;
		}
		x++;
	}
}
