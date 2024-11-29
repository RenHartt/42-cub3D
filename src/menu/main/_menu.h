/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _menu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:10:38 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 02:50:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MENU_H
# define _MENU_H

# include "include.h"

void	set_menu_image(t_data *data, t_menu *m, t_vec2f scale_factor);
void	resize_image(t_data *data, t_image *src, t_vec2i new_size);
int		is_mouse_over_button(t_button *button, int mouse_x,
			int mouse_y) __attribute__((pure));

#endif // _MENU_H