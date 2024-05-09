/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:53:39 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/24 15:05:37 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **original)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	while (original[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!(copy))
		return (NULL);
	i = -1;
	j = -1;
	while (original[++i])
	{
		copy[i] = ft_strdup(original[i]);
		if (!(copy[i]))
		{
			while (++j < i)
				free(copy[j]);
			free(copy);
			return (NULL);
		}
	}
	copy[i] = NULL;
	return (copy);
}

void	error_message(t_game *game)
{
	if (!map_arg_present(game))
	{
		ft_printf("error:\ninvalid number of arguments on the map:\n", 2);
		if (game->nbr_player != 1)
			ft_printf("invalid player number\n");
		if (game->nbr_exit != 1)
			ft_printf("invalid exit number\n");
		if (game->nbr_collec <= 0)
			ft_printf("invalid collectible number\n");
	}
	if (!map_is_rec(game->map))
		ft_printf("error:\nmap is not rectangular\n");
	if (!map_no_invalid_arg(game->map))
		ft_printf("error:\ninvalid arguments on the map\n");
	if (!map_is_wall(game->map))
		ft_printf("error:\ninvalid wall on the map\n");
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}

t_game	*copy_struct(t_game *original)
{
	t_game	*copy;

	copy = malloc(sizeof(t_game));
	if (!copy)
		return (NULL);
	copy->nbr_collec = original->nbr_collec;
	copy->nbr_exit = original->nbr_exit;
	copy->y_player = original->y_player;
	copy->x_player = original->x_player;
	copy->map = copy_map(original->map);
	if (!(copy->map))
	{
		free(copy);
		return (NULL);
	}
	return (copy);
}
