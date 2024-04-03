/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:25 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 20:32:49 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_matrix_simvols_is_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C' || map->map[i][j] == 'P'
				|| map->map[i][j] == 'E' || map->map[i][j] == '1'
				|| map->map[i][j] == '0' || map->map[i][j] == 'M')
				j++;
			else
				error(map);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc > 2 || argc < 2)
	{
		write(1, "Invalid argc argument\n", 22);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Can not open file\n", 18);
		return (1);
	}
	if_map_was_ended_tochka_ber(argv[1]);
	map.map = parsing(fd, &map);
	if (!(map.map[0]))
		return (1);
	validation(&map);
	if_matrix_simvols_is_valid(&map);
	mlx_part(&map);
	return (0);
}

void	if_map_was_ended_tochka_ber(char *argvi)
{
	int	i;

	i = ft_strlen(argvi) - 1;
	if (argvi[i--] != 'r')
		exit(write(1, "ERROR\n", 6));
	if (argvi[i--] != 'e')
		exit(write(1, "ERROR\n", 6));
	if (argvi[i--] != 'b')
		exit(write(1, "ERROR\n", 6));
	if (argvi[i--] != '.')
		exit(write(1, "ERROR\n", 6));
}
