/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _minimap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:38:13 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 05:50:13 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIMAP_H
# define _MINIMAP_H

# define MINIMAP_SCALE 30.0f
# define MINIMAP_RADIUS 100.0f

# include "include.h"

void	create_circular_mask(int *mask, int width, int height);
void	set_minimap_color(t_data *d, t_vec2f map, int *color);
void	set_minimap_pixel(t_data *d, int *mask, t_vec2i pos, t_vec2f p_map);
void	draw_player_marker(t_data *data);

#endif // _MINIMAP_H