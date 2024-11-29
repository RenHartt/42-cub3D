/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:10:51 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

static int	print_error(const char *error)
{
	printf("\033[1;31mError\n%s\033[0m", error);
	return (-1);
}

static int	check_argv(int ac, char **av, int *fd)
{
	if (ac != 2)
		return (print_error("Wrong number of arguments\n"));
	if (check_extension_file(av[1], ".cub") == -1)
		return (print_error("Wrong file extension\n"));
	*fd = open(av[1], O_RDONLY);
	if (*fd < 0)
		return (print_error("Can't open file\n"));
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	int		fd;
	char	**file;

	file = NULL;
	if (check_argv(ac, av, &fd) == -1)
		return (-1);
	file_to_char(fd, &file);
	if (!file)
		return (print_error("Empty file"));
	if (parse_texture(file, data) == -1)
		return (print_error("Can't parse texture\n"));
	if (parse_map(file, data) == -1)
		return (print_error("Can't parse map\n"));
	if (check_player(data->map.map, &data->player) == -1)
		return (print_error("Wrong player\n"));
	if (check_map_character(data->map.map) == -1)
		return (print_error("Wrong character in map\n"));
	if (check_unclosed_map(data->map.map) == -1)
		return (print_error("Unclosed map\n"));
	if (check_unclosed_map(data->map.map) == -2)
		return (print_error("Wrong door position\n"));
	if (WIN_WIDTH < 100 || WIN_HEIGHT < 100)
		return (print_error("Resolution too low\n"));
	return (0);
}
