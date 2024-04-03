/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:59 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 18:14:00 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_copy_map(t_map *map)
{
	char	**copy_map;
	int		i;
	int		j;

	i = 0;
	copy_map = malloc(sizeof(char *) * (map->row + 1));
	if (!copy_map)
		return (NULL);
	while (map->map[i])
	{
		copy_map[i] = malloc(sizeof(char) * (map->column + 1));
		if (!copy_map[i])
			free_and_exit_func(copy_map);
		j = 0;
		while (map->map[i][j])
		{
			copy_map[i][j] = map->map[i][j];
			j++;
		}
		copy_map[i][j] = '\0';
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	fill(char **copy_map, t_map *map, t_player player, char to_fill)
{
	if (player.pos_x < 0 || player.pos_x > map->column
		|| player.pos_y < 0 || player.pos_y > map->row)
		return ;
	if (ft_strchr("PCE", copy_map[player.pos_y][player.pos_x]) != 0)
		copy_map[player.pos_y][player.pos_x] = '0';
	if (copy_map[player.pos_y][player.pos_x] != to_fill)
		return ;
	copy_map[player.pos_y][player.pos_x] = 'F';
	fill(copy_map, map, (t_player){player.pos_x - 1, player.pos_y}, to_fill);
	fill(copy_map, map, (t_player){player.pos_x + 1, player.pos_y}, to_fill);
	fill(copy_map, map, (t_player){player.pos_x, player.pos_y - 1}, to_fill);
	fill(copy_map, map, (t_player){player.pos_x, player.pos_y + 1}, to_fill);
}

void	flood_fill(char **copy_map, t_map *map)
{
	fill(copy_map, map, map->player, '0');
}
