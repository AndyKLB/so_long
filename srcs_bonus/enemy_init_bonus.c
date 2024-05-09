/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:09:24 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/29 12:09:48 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin_count(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

int	xpm_enemy_to_img(t_game *game)
{
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/N.xpm", &game->img_h, &game->img_w);
	if (!game->img_enemy)
		return (free(game->img_backg), free(game->img_exit),
			free(game->img_wall), free(game->img_collec),
			free(game->img_player), 1);
	game->img_happy = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/PH.xpm", &game->img_h, &game->img_w);
	if (!game->img_happy)
		return (free(game->img_backg), free(game->img_exit),
			free(game->img_wall), free(game->img_collec),
			free(game->img_player), free(game->img_enemy), 1);
	game->img_count = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/BCK.xpm", &game->img_h, &game->img_w);
	if (!game->img_count)
		return (free(game->img_backg), free(game->img_exit),
			free(game->img_wall), free(game->img_collec),
			free(game->img_player), free(game->img_enemy),
			free(game->img_happy), 1);
	return (0);
}

void	enemy_init_bonus(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'N')
				game->nbr_enemy++;
		}
	}
}
