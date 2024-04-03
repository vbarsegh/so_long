/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:11 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 18:15:38 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiliaze_image_ptr(t_mlx *mlx)
{
	mlx->img_ptr_player = mlx_xpm_file_to_image(mlx->mlx,
			"textures/player.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_player_anim = mlx_xpm_file_to_image(mlx->mlx,
			"textures/player_anim.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_wall = mlx_xpm_file_to_image(mlx->mlx,
			"textures/wall(1).xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_exit = mlx_xpm_file_to_image(mlx->mlx,
			"textures/exit.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_coins = mlx_xpm_file_to_image(mlx->mlx,
			"textures/coin.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_0 = mlx_xpm_file_to_image(mlx->mlx,
			"textures/0.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_monster = mlx_xpm_file_to_image(mlx->mlx,
			"textures/monster.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img_ptr_monster_anim = mlx_xpm_file_to_image(mlx->mlx,
			"textures/monster2.xpm", &mlx->img_width, &mlx->img_height);
}

int	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->column)
		{
			mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
				map->mlx.img_ptr_0, j * SIZE, i * SIZE);
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
					map->mlx.img_ptr_wall, j * SIZE, i * SIZE);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
					animation_player(map), j * SIZE, i * SIZE);
			else
				draw_e_c_m(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	draw_e_c_m(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
			map->mlx.img_ptr_exit, j * SIZE, i * SIZE);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
			map->mlx.img_ptr_coins, j * SIZE, i * SIZE);
	else if (map->map[i][j] == 'M')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
			animation_monster(map), j * SIZE, i * SIZE);
}

int	draw_and_clear_map(t_map *map)
{
	char	*arr;

	mlx_clear_window(map->mlx.mlx, map->mlx.window);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.window,
		map->mlx.img_ptr_exit, map->pos_exit_x * SIZE, map->pos_exit_y * SIZE);
	draw_map(map);
	arr = ft_itoa(map->count_step);
	mlx_string_put(map->mlx.mlx, map->mlx.window, 100, 100, 0x00FF00, arr);
	free(arr);
	return (0);
}

//es funkciayov menq maqrum enq naxkinum nkarac map-@ u tazen nkarum: