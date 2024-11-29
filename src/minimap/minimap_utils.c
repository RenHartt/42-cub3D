/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:17:11 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:17:15 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_minimap.h"

void	create_circular_mask(int *mask, int width, int height)
{
	int		radius;
	t_vec2i	center;
	t_vec2i	p;
	t_vec2i	d;

	radius = width / 2;
	center.x = width / 2;
	center.y = height / 2;
	p.y = 0;
	while (p.y < height)
	{
		p.x = 0;
		while (p.x < width)
		{
			d.x = center.x - p.x;
			d.y = center.y - p.y;
			if (d.x * d.x + d.y * d.y <= radius * radius)
				mask[p.y * width + p.x] = 1;
			else
				mask[p.y * width + p.x] = 0;
			p.x++;
		}
		p.y++;
	}
}

void	set_minimap_color(t_data *d, t_vec2f map, int *color)
{
	if (map.x >= 0.f && map.x < (float)d->map.cols && map.y >= 0.f && map.y < (float)d->map.rows)
	{
		if (d->map.map[(int)map.y][(int)map.x] == '1')
			*color = (int)(uintptr_t)0xFFFF0000;
		if (d->map.map[(int)map.y][(int)map.x] == 'D')
			*color = (int)(uintptr_t)0xFF0000FF;
	}
}

void	set_minimap_pixel(t_data *d, int *mask, t_vec2i pos, t_vec2f p_map)
{
	t_vec2f	map;
	t_vec2f	cos_sin;
	float	ratio;
	int		color;
	int		size;

	size = (int)((WIN_HEIGHT * 0.56f / 3.0f) * d->settings.minimap_scale);
	cos_sin.x = cosf(atan2f(d->player.dir.y, d->player.dir.x));
	cos_sin.y = sinf(atan2f(d->player.dir.y, d->player.dir.x));
	ratio = (WIN_HEIGHT * 0.28f / 3.0f) * d->settings.minimap_scale;
	if (mask[pos.y * size + pos.x])
	{
		map.x = p_map.x + (cos_sin.x * (-((float)pos.y - ratio)) - cos_sin.y \
		* ((float)pos.x - ratio)) / MINIMAP_SCALE * d->settings.minimap_scale;
		map.y = p_map.y + (cos_sin.y * (-((float)pos.y - ratio)) + cos_sin.x \
		* ((float)pos.x - ratio)) / MINIMAP_SCALE * d->settings.minimap_scale;
		color = (int)(uintptr_t)0xFF808080;
		set_minimap_color(d, map, &color);
		mlx_set_image_pixel(d->graphics.mlx, \
		d->graphics.img_mini_map, pos.x, pos.y, color);
	}
}
