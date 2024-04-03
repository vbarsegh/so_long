/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:55 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 18:13:56 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1)
	{
		while (s1[s1_len])
			s1_len++;
	}
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	my_strncpy(str, s1, s1_len + 1);
	my_strncpy(&str[s1_len], s2, s1_len + s2_len + 1);
	return (str);
}

void	my_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (src)
	{
		while (i < n && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
}

int	check1(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

void	initiliaze_player_positions(t_map *map,
	int *count_start_p, int i, int j)
{
	*count_start_p += 1;
	map->player.pos_x = j;
	map->player.pos_y = i;
}
