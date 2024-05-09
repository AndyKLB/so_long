/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:16:28 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/25 17:47:25 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_is_rec(char **map)
{
	int	y;

	if (!map || !map[0])
		return (0);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[y]))
			return ((0));
		y++;
	}
	return (1);
}

int	map_no_invalid_arg(char **map)
{
	int	x;
	int	y;

	if (!map)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P'
				&& map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != 'N')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	map_is_wall(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
		y++;
	while (map[0][x] && map[y - 1][x])
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	x = ft_strlen(map[0]);
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	map_arg_present(t_game *game)
{
	if (game->nbr_collec <= 0 || game->nbr_player != 1 || game->nbr_exit != 1
		|| game->nbr_enemy <= 0)
		return (0);
	return (1);
}

int	map_is_valid(t_game *game)
{
	if (!game->map || !game->map[0])
	{
		ft_printf("error:\nno arguments on the map\n");
		return (0);
	}
	var_struct_init(game);
	if (map_arg_present(game) && map_is_rec(game->map)
		&& map_no_invalid_arg(game->map) && map_is_wall(game->map)
		&& is_valid_path(game))
		return (1);
	error_message(game);
	return (0);
}
