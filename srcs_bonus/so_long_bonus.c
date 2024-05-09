/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:21:45 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/25 17:52:51 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	argv_is_valid(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv[i - 3] == '.')
		return (1);
	ft_printf("Error:\nInvalid map extension");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 && !argv_is_valid(argv[1]))
		return (0);
	game.map = map_reader(argv[1]);
	if (map_is_valid(&game))
	{
		if (game_init(&game))
			exit(EXIT_FAILURE);
		hook_handle(&game);
		mlx_loop(game.mlx);
		exit(EXIT_SUCCESS);
	}
	if (game.map)
	{
		free_map(game.map);
		exit(EXIT_FAILURE);
	}
	return (0);
}
