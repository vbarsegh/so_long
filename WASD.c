/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WASD.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:14:20 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 20:30:41 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_map *map)
{
	if (keycode == 53)
		free_mlx(map, 2);
	if (keycode == 13)
		if_possible_player_move_top(map);
	if (keycode == 0)
		if_possible_player_move_left(map);
	if (keycode == 1)
		if_possible_player_move_bottom(map);
	if (keycode == 2)
		if_possible_player_move_right(map);
	return (0);
}

void	if_possible_player_move_top(t_map *map)
{
	if (map->map[map->player.pos_y - 1][map->player.pos_x] == 'M')
		free_mlx(map, 1);
	if (map->map[map->player.pos_y - 1][map->player.pos_x] == '1')
		return ;
	if (map->map[map->player.pos_y - 1][map->player.pos_x] == 'C')
		map->count_coins--;
	else if (map->map[map->player.pos_y - 1][map->player.pos_x] == 'E')
	{
		if (map->count_coins == 0)
			free_mlx(map, 0);
	}
	map->map[map->player.pos_y - 1][map->player.pos_x] = 'P';
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	if (map->pos_exit_x == map->player.pos_x
		&& map->pos_exit_y == map->player.pos_y)
		map->map[map->pos_exit_y][map->pos_exit_x] = 'E';
	else
		map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_y -= 1;
	map->count_step++;
}

void	if_possible_player_move_left(t_map	*map)
{
	if (map->map[map->player.pos_y][map->player.pos_x - 1] == 'M')
		free_mlx(map, 1);
	if (map->map[map->player.pos_y][map->player.pos_x - 1] == '1')
		return ;
	if (map->map[map->player.pos_y][map->player.pos_x - 1] == 'C')
		map->count_coins--;
	else if (map->map[map->player.pos_y][map->player.pos_x - 1] == 'E')
	{
		if (map->count_coins == 0)
			free_mlx(map, 0);
	}
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->map[map->player.pos_y][map->player.pos_x - 1] = 'P';
	if (map->pos_exit_x == map->player.pos_x
		&& map->pos_exit_y == map->player.pos_y)
		map->map[map->pos_exit_y][map->pos_exit_x] = 'E';
	else
		map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_x -= 1;
	map->count_step++;
}

void	if_possible_player_move_bottom(t_map *map)
{
	if (map->map[map->player.pos_y + 1][map->player.pos_x] == 'M')
		free_mlx(map, 1);
	if (map->map[map->player.pos_y + 1][map->player.pos_x] == '1')
		return ;
	if (map->map[map->player.pos_y + 1][map->player.pos_x] == 'C')
		map->count_coins--;
	else if (map->map[map->player.pos_y + 1][map->player.pos_x] == 'E')
	{
		if (map->count_coins == 0)
			free_mlx(map, 0);
	}
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->map[map->player.pos_y + 1][map->player.pos_x] = 'P';
	if (map->pos_exit_x == map->player.pos_x
		&& map->pos_exit_y == map->player.pos_y)
		map->map[map->pos_exit_y][map->pos_exit_x] = 'E';
	else
		map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_y += 1;
	map->count_step++;
}

void	if_possible_player_move_right(t_map *map)
{
	if (map->map[map->player.pos_y][map->player.pos_x + 1] == 'M')
		free_mlx(map, 1);
	if (map->map[map->player.pos_y][map->player.pos_x + 1] == '1')
		return ;
	if (map->map[map->player.pos_y][map->player.pos_x + 1] == 'C')
		map->count_coins--;
	else if (map->map[map->player.pos_y][map->player.pos_x + 1] == 'E')
	{
		if (map->count_coins == 0)
			free_mlx(map, 0);
	}
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->map[map->player.pos_y][map->player.pos_x + 1] = 'P';
	if (map->pos_exit_x == map->player.pos_x
		&& map->pos_exit_y == map->player.pos_y)
		map->map[map->pos_exit_y][map->pos_exit_x] = 'E';
	else
		map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_x += 1;
	map->count_step++;
}
