/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:14:10 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/04/11 23:06:45 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*animation_monster(t_map *map)
{
	static int	i;

	if (i < 10)
	{
		i++;
		return (map->mlx.img_ptr_monster);
	}
	if (i < 40)
	{
		i++;
		return (map->mlx.img_ptr_monster_anim);
	}
	i = 0;
	return (map->mlx.img_ptr_monster_anim);
}

void	*animation_player(t_map *map)
{
	static int	i;

	if (i < 20)
	{
		i++;
		return (map->mlx.img_ptr_player);
	}
	if (i < 50)
	{
		i++;
		return (map->mlx.img_ptr_player_anim);
	}
	i = 0;
	return (map->mlx.img_ptr_player_anim);
}

void	free_mlx(t_map *map, int i)
{
	int	j;

	j = 0;
	mlx_destroy_window(map->mlx.mlx, map->mlx.window);//verjnakan avarteluc,ogtvum enq mlx-i es funkciayic
	while (j < map->row)
		free(map->map[j++]);
	free(map->map);
	if (i == 0)
	{
		write(1, "You Win!!\n", 10);
		exit(i);
	}
	else if (i == 1)
	{
		write (1, "You Lose\n", 9);
		exit(i);
	}
	exit(0);
}

int	finish_with_esc(t_map *map)
{
	free_mlx(map, 2);
	return (0);
}

void	mlx_part(t_map *map)
{
	t_mlx	mlx;

	map->count_step = 0;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window
		(mlx.mlx, map->column * SIZE, map->row * SIZE, "MY");
	initiliaze_image_ptr(&mlx);
	map->mlx = mlx;
	draw_map(map);
	mlx_hook(mlx.window, 2, 0, key_press, map);//2-y key_press-na ,aysinqn henc sexmenq mer kargavorac hatuk stexnery,inqy ardzaganqelua
	//(yani,ashxatec orinak W-n,voncor terminalum gri,du kpar W tarin,de yst mer grac funckiayi  henc sexmenq W-n kani en inch es greleem funkciayi mej)
	mlx_hook(mlx.window, 17, 0, finish_with_esc, map);//es funkcian hnaravorutyuna talis vor ESC-ov prcnenq xaxy(kisat toxac)
	mlx_loop_hook(mlx.mlx, draw_and_clear_map, map);//loop_hook-mijocovel mer draw_and_clear_map funkcian ha kanchvelua,(for eli)
	mlx_loop(mlx.mlx);//cikli meja qcum ,ete chlni apa patuhany enqan arag kbacvi u kpakvi vor chenqe hascni nkatel,isk loop funkciayi mijocov voncor cikli mej enq gorcyntacy qcum
}
