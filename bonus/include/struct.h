/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:24:53 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 21:48:22 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MacroLibX/includes/mlx.h"
# include "SDL2/SDL_scancode.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define WIN_WIDTH 1920.0f
# define WIN_HEIGHT 1080.0f
# define M_PI_F 3.14159265358979323846f

# define BACKGROUND "textures/menu/menu_background.png"
# define BACKGROUND_SETTING "textures/menu/background_settings_menu.png"
# define GUI "textures/menu/GUI.png"
# define START "textures/menu/start.png"
# define START_HOVERED "textures/menu/start_hovered.png"
# define START_PRESSED "textures/menu/start_pressed.png"
# define EXIT_MENU "textures/menu/exit.png"
# define EXIT_HOVERED "textures/menu/exit_hovered.png"
# define EXIT_PRESSED "textures/menu/exit_pressed.png"
# define SETTINGS_MENU "textures/menu/settings.png"
# define SETTINGS_HOVERED "textures/menu/settings_hovered.png"
# define SETTINGS_PRESSED "textures/menu/settings_pressed.png"
# define BACK_BUTTON_PRESSED "textures/menu/back_button.png"
# define BACK_BUTTON_HOVERED "textures/menu/hovered_back_button.png"

typedef struct s_vec2f
{
	float			x;
	float			y;
}					t_vec2f;

typedef struct s_vec2i
{
	int				x;
	int				y;
}					t_vec2i;

typedef union u_color
{
	struct
	{
		uint8_t		a;
		uint8_t		r;
		uint8_t		g;
		uint8_t		b;
	};
	uint32_t		color;
}					t_color;

typedef enum e_status
{
	PARSING_ERROR,
	PRELOAD_ERROR,
	EXIT_GAME
}					t_status;

typedef enum e_screen_state
{
	MAIN_MENU,
	GAME,
	PAUSE,
	SETTINGS,
	EXIT
}					t_screen_state;

typedef struct s_image
{
	void			*img;
	int				width;
	int				height;
}					t_image;

typedef struct s_map
{
	char			**map;
	int				rows;
	int				cols;
}					t_map;

typedef struct s_player
{
	t_vec2f			pos;
	t_vec2f			dir;
	t_vec2f			plane;
	float			move_speed;
	float			rot_speed;
	float			pitch;
}					t_player;

typedef struct s_sprite
{
	char			*path_n;
	char			*path_s;
	char			*path_e;
	char			*path_w;
	char			*path_floor;
	char			*path_ceiling;
	t_image			wall_n;
	t_image			wall_s;
	t_image			wall_e;
	t_image			wall_w;
	t_image			floor;
	t_image			ceiling;
	int				*north_texture;
	int				*south_texture;
	int				*east_texture;
	int				*west_texture;
	int				*floor_texture;
	int				*ceiling_texture;
	t_color			floor_color;
	t_color			ceiling_color;
}					t_sprite;

typedef struct s_button
{
	t_image			img;
	t_image			img_pressed;
	t_image			img_hovered;
	bool			is_hovered;
	bool			is_pressed;
	t_vec2i			pos;
	t_vec2i			size;
}					t_button;

typedef struct s_menu
{
	t_image			img_background;
	t_image			img_background_button;
	t_button		play_button;
	t_button		exit_button;
	t_button		settings_button;
}					t_menu;

typedef struct s_game
{
	void			*img_background;
	bool			floor_and_ceiling;
}					t_game;

typedef enum e_button_state
{
	NOTHING,
	MOVE_FORWARD,
	MOVE_BACKWARD,
	MOVE_LEFT,
	MOVE_RIGHT,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	SPRINT,
	MAP_ZOOM,
	SHOW_FLOOR_AND_CEILING,
}				t_button_state;

typedef struct s_settings
{
	t_image			img_background;
	t_vec2i			pos_img_background;
	t_image			img_darken;
	t_button		back_button;
	t_button_state	button_state_hover;
	t_button_state	button_state_press;
	bool			waiting_for_key;
}					t_settings;

typedef struct s_graphics
{
	void			*mlx;
	void			*win;
	t_menu			menu;
	t_game			game;
	t_settings		settings;
	bool			is_first_frame;
	void			*img_mini_map;
	t_sprite		wall_sprite;
	int				key_states[256];
}					t_graphics;

typedef struct s_settings_player
{
	float			minimap_scale;
	float			fov;
	int				key_move_forward;
	int				key_move_backward;
	int				key_move_left;
	int				key_move_right;
	int				key_rotate_left;
	int				key_rotate_right;
	int				key_sprint;
	int				key_map_zoom;
	int				key_show_floor_and_ceiling;
	t_screen_state	screen_state;
}					t_settings_player;

typedef struct s_data
{
	t_graphics			graphics;
	t_map				map;
	t_player			player;
	t_settings_player	settings;
}					t_data;

#endif // STRUCT_H
