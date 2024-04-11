/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:45 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/04/11 22:43:12 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parsing(int fd, t_map *map)
{
	char	*buffer;
	char	*arr;
	char	*join_arr;

	join_arr = NULL;
	buffer = get_next_line(fd);
	check_malloc_is_allocated(buffer);
	if (!buffer)
		return (NULL);
	while (buffer)
	{
		arr = strjoin(join_arr, buffer);
		free(join_arr);
		join_arr = arr;
		free(buffer);
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
	}//   .ber faylic amboxjy lcnum enq buffer-i mej
	return (parsing_part_two(map, join_arr));
}

char	**parsing_part_two(t_map *map, char *join_arr)
{
	char	*trim_arr;
	char	**split_matrix;

	trim_arr = ft_strtrim(join_arr, " \n\v\f\r\t");//array-i vra trim enq anum
	if (!trim_arr)
	{
		free(join_arr);
		exit(1);
	}
	free(join_arr);
	if_have_slesh_n_next_two(trim_arr);//ete irar hetevic /n-ner exav apa error enq tpum
	split_matrix = split(trim_arr, '\n');//split enq anum trim arac array-@ @st /n-i
	if (!split_matrix)
	{
		free(trim_arr);
		exit(1);
	}
	free(trim_arr);
	return (get_end_trimmed_matrix(split_matrix, map));//spliti exac erkchap zangvaci yuraqanchyur toxi verjic trim enq anum
}

void	if_have_slesh_n_next_two(char *trim_arr)
{
	int	i;

	i = 0;
	while (trim_arr[i])
	{
		if (trim_arr[i] == '\n' && trim_arr[i + 1] == '\n')
		{
			free(trim_arr);
			write(1, "Invalid Map\n", 12);
			exit(1);
		}
		i++;
	}
}

char	**get_end_trimmed_matrix(char **split_matrix, t_map *map)
{
	int		j;
	char	**res_matrix;

	j = 0;
	map->row = 0;
	while (split_matrix[map->row])
		map->row++;
	res_matrix = malloc(sizeof(char *) * (map->row + 1));
	if (!res_matrix)
		free_and_exit_func(split_matrix);
	while (j < map->row)
	{
		res_matrix[j] = ft_strtrim_verjic(split_matrix[j]);
		if (res_matrix[j] == NULL)
		{
			free_split_line(res_matrix);
			free_split_line(split_matrix);
			exit(1);
		}
		j++;
	}
	res_matrix[j] = NULL;
	free_split_line(split_matrix);
	return (res_matrix);
}
