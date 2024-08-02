/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:42:33 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 20:06:49 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	load_texture_data(void *mlx, t_image wall_img, int *texture)
{
	int	x;
	int	y;

	y = 0;
	while (y < wall_img.height)
	{
		x = 0;
		while (x < wall_img.width)
		{
			texture[y * wall_img.width + x] = mlx_get_image_pixel(mlx,
					wall_img.img, x, y);
			x++;
		}
		y++;
	}
}

int	preload_texture(t_data *data, t_image wall_img, int **texture)
{
	*texture = malloc(wall_img.width * wall_img.height * sizeof(int));
	if (!(*texture))
		return (-1);
	load_texture_data(data->mlx.mlx, wall_img, *texture);
	return (0);
}

int	preload_textures(t_data *data)
{
	int	alloc_error;

	alloc_error = 0;
	alloc_error += preload_texture(data, data->mlx.wall_sprite.wall_n, \
		&data->mlx.wall_sprite.north_texture);
	alloc_error += preload_texture(data, data->mlx.wall_sprite.wall_s, \
		&data->mlx.wall_sprite.south_texture);
	alloc_error += preload_texture(data, data->mlx.wall_sprite.wall_e, \
		&data->mlx.wall_sprite.east_texture);
	alloc_error += preload_texture(data, data->mlx.wall_sprite.wall_w, \
		&data->mlx.wall_sprite.west_texture);
	if (alloc_error < 0)
		return (-1);
	return (0);
}
