/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:38:52 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/28 20:25:30 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define SIZE 60
# define W 13
# define A 0
# define S 2
# define D 1

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img_ptr_player;
	void	*img_ptr_player_anim;
	void	*img_ptr_wall;
	void	*img_ptr_exit;
	void	*img_ptr_coins;
	void	*img_ptr_0;
	void	*img_ptr_monster;
	void	*img_ptr_monster_anim;
	int		img_width;
	int		img_height;
}	t_mlx;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			row;
	int			column;
	int			count_coins;
	int			pos_exit_x;
	int			pos_exit_y;
	int			count_step;
	t_player	player;
	t_mlx		mlx;
}		t_map;

void	if_matrix_simvols_is_valid(t_map *map);
char	**parsing(int fd, t_map *map);
char	**parsing_part_two(t_map *map, char *join_arr);
void	if_have_slesh_n_next_two(char *trim_arr);
char	**get_end_trimmed_matrix(char **split_matrix, t_map *map);
void	validation(t_map *map);
int		check_if_all_line_len_is_equal(t_map *map);
void	border_check(t_map *map);
void	if_how_simvols_have_map(t_map *map, int count_exit, int count_start_p);
void	check_map_is_valid(char **copy_map, t_map *map);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strtrim_verjic(char *str);
char	*strjoin(const char *s1, const char *s2);
void	my_strncpy(char *dest, const char *src, unsigned int n);
int		check1(char c, char const *set);
void	initiliaze_player_positions(t_map *map,
			int *count_start_p, int i, int j);
char	**get_copy_map(t_map *map);
void	fill(char **copy_map, t_map *map, t_player player, char to_fill);
void	flood_fill(char **copy_map, t_map *map);
void	free_split_line(char **matrix);
void	error(t_map *map);
void	free_and_exit_func(char **matrix);
void	check_malloc_is_allocated(char *buffer);
void	*animation_monster(t_map *map);
void	*animation_player(t_map *map);
void	free_mlx(t_map *map, int i);
int		finish_with_esc(t_map *map);
void	mlx_part(t_map *map);
void	initiliaze_image_ptr(t_mlx *mlx);
int		draw_map(t_map *map);
int		draw_and_clear_map(t_map *map);
char	*ft_itoa(int n);
int		key_press(int keycode, t_map *map);
void	if_possible_player_move_top(t_map *map);
void	if_possible_player_move_left(t_map	*map);
void	if_possible_player_move_bottom(t_map *map);
void	if_possible_player_move_right(t_map *map);
char	*get_next_line(int fd);
char	**split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
void	draw_e_c_m(t_map *map, int i, int j);
void	if_map_was_ended_tochka_ber(char *argvi);

#endif