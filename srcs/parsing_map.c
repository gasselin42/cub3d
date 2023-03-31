/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 06:43:34 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/09 12:35:39 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

int	validate_edges(t_kub *kub)
{
	int		i;
	char	**split;

	i = -1;
	kub->map_height = ft_strarr_size(kub->map);
	if (ft_count_char(kub->map[0], "1 ") != (int)ft_strlen(kub->map[0]))
		return (1);
	if (ft_count_char(kub->map[kub->map_height - 1], "1 ") != \
		(int)ft_strlen(kub->map[kub->map_height - 1]))
		return (1);
	while (++i < kub->map_height)
	{
		split = ft_split(kub->map[i], ' ');
		if (split[0] && (split[0][0] != '1' || split[ft_strarr_size(split) - 1] \
			[ft_strlen(split[ft_strarr_size(split) - 1]) - 1] != '1'))
		{
			ft_strarr_free(split);
			return (1);
		}
		ft_strarr_free(split);
	}
	return (0);
}

int	clear_lines(t_kub *kub)
{
	int		size;
	bool	end;

	end = false;
	size = ft_strarr_size(kub->map) - 1;
	while (size > 0)
	{
		if (kub->map[size][0] == '\0' ||
			ft_count_char(kub->map[size], " ") ==
				(int)ft_strlen(kub->map[size]))
		{
			if (end == false)
				kub->map = ft_strarr_popback(kub->map);
			if (end == true)
				return (1);
		}
		else
			end = true;
		size--;
	}
	return (0);
}

// This function validate the map
// First its validate the chars
int	valid_map(t_kub *kub)
{
	int	i;
	int	j;

	if (clear_lines(kub) || validate_edges(kub))
		return (1);
	fill_lines(kub);
	if (valid_chars(kub))
		return (1);
	else
	{
		i = -1;
		while (++i < ft_strarr_size(kub->map))
		{
			j = -1;
			while (++j < (int)ft_strlen(kub->map[0]))
			{
				if (kub->map[i][j] == ' ')
					if (check_surroundings(kub->map, i, j))
						return (1);
			}
		}
	}
	replace_spaces(kub);
	return (0);
}

int	set_initial_direction(t_kub *kub)
{
	char	c;

	if (kub->player_x == -1.0)
		return (1);
	c = kub->map[(int)kub->player_y][(int)kub->player_x];
	kub->dir_x = 0.0;
	kub->dir_y = 0.0;
	if (c == 'N')
		kub->dir_y = -1;
	if (c == 'S')
		kub->dir_y = 1;
	if (c == 'E')
		kub->dir_x = 1;
	if (c == 'W')
		kub->dir_x = -1;
	kub->map[(int)kub->player_y][(int)kub->player_x] = '0';
	kub->rot = player_rot(kub);
	return (0);
}

void	map_reach(t_kub *kub, char *line)
{
	kub->map = ft_calloc(1, sizeof(char *));
	kub->map = ft_strarr_addback(kub->map, line);
	free(line);
	while (get_next_line(kub->map_fd, &line))
	{
		kub->map = ft_strarr_addback(kub->map, line);
		free(line);
	}
	kub->map = ft_strarr_addback(kub->map, line);
	free(line);
	close(kub->map_fd);
	if (valid_map(kub) || set_initial_direction(kub))
	{
		printf("Error\n%s\n", INVALID_MAP);
		free_asset(kub);
		ft_strarr_free(kub->map);
		exit (0);
	}
}
