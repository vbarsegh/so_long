/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:38 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/04/11 22:49:52 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validation(t_map *map)
{
	int		count_exit;
	int		count_start_p;
	char	**copy_map;

	map->count_coins = 0;
	count_exit = 0;
	count_start_p = 0;
	map->column = check_if_all_line_len_is_equal(map);//nayum enq vor sax toxery nuyn erkarutyunn(simvolneri qanakay =linen) unenan
	border_check(map);//stugum enq ardyoq qartezi verev,nerqev,aj u dzax koxmery sax 1 erov pakvac linen,ete che errora
	if_how_simvols_have_map(map, count_exit, count_start_p);//parzvum enq te yuraqanchyur simvolic(P,E,C) qani hat ka
	copy_map = get_copy_map(map);//copy_map enq stexcum,vor iranov fllod_fill-@ irakanacnenq,vor kparzi ardyoq player-@ karoxa vercnel bolor coin-nery ev hasni exit-in
	if (!copy_map)
		free_and_exit_func(map->map);
	flood_fill(copy_map, map);
	check_map_is_valid(copy_map, map);//ete copy_map-oii mej mnacel en P kam E kam C uremn player-@ chi kara xaxa xaxy ev avartin hascni=>ERROR 
	free_split_line(copy_map);
}

int	check_if_all_line_len_is_equal(t_map *map)
{
	int	i;

	i = 0;
	map->column = ft_strlen(map->map[i]);
	i++;
	while (map->map[i])
	{
		if (map->column != ft_strlen(map->map[i]))
			error(map);
		i++;
	}
	return (map->column);
}

void	border_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
		i++;
	j = 0;
	while (map->map[0][j] && map->map[i - 1][j])
	{
		if (map->map[0][j] != '1' || map->map[i - 1][j] != '1')
			error(map);
		j++;
	}
	i = 0;
	while (map->map[i] && map->map[i][0] && map->map[i][map->column - 1])
	{
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			error(map);
		i++;
	}
}

void	if_how_simvols_have_map(t_map *map, int count_exit, int count_start_p)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				initiliaze_player_positions(map, &count_start_p, i, j);
			else if (map->map[i][j] == 'E')
			{
				map->pos_exit_x = j;//fiqsum en nayev exit-i koordinatnery
				map->pos_exit_y = i;
				count_exit++;
			}
			else if (map->map[i][j] == 'C')
				map->count_coins++;
			j++;
		}
		i++;
	}
	if (count_start_p != 1 || count_exit != 1 || map->count_coins < 1)
		error(map);
}

void	check_map_is_valid(char **copy_map, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->column)
		{
			if (copy_map[i][j] == 'E' || copy_map[i][j] == 'C'
			|| copy_map[i][j] == 'P')
			{
				free_split_line(map->map);
				free_split_line(copy_map);
				write(1, "INVALID MAP\n", 12);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
