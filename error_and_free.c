/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:32 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 20:33:44 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split_line(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	error(t_map *map)
{
	free_split_line(map->map);
	write(1, "Invalid map\n", 12);
	exit(1);
}

void	free_and_exit_func(char **matrix)
{
	free_split_line(matrix);
	exit(1);
}

void	check_malloc_is_allocated(char *buffer)
{
	if (!buffer)
		exit(1);
	else
		return ;
}
