/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:33:27 by gasselin          #+#    #+#             */
/*   Updated: 2022/06/11 13:31:43 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

int	check_surroundings(char **map, int i, int j)
{
	int	height;
	int	width;

	height = ft_strarr_size(map) - 1;
	width = (int)ft_strlen(map[0]) - 1;
	if (i > 0)
	{
		if ((j > 0 && map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != ' ') ||
			(map[i - 1][j] != '1' && map[i - 1][j] != ' ') ||
			(j < width && map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != ' '))
			return (1);
	}
	if (i < height)
	{
		if ((j > 0 && map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != ' ') ||
			(map[i + 1][j] != '1' && map[i + 1][j] != ' ') ||
			(j < width && map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != ' '))
			return (1);
	}
	if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != ' ')
		return (1);
	if (j < width && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
		return (1);
	return (0);
}

// This function validate that the char are only 0,1 and space
// It also validate the player position (N, S, W, E)
int	valid_chars(t_kub *kub)
{
	int	i;
	int	j;

	i = -1;
	while (kub->map[++i])
	{
		j = -1;
		while (kub->map[i][++j])
		{
			if (kub->map[i][j] == ' ' || kub->map[i][j] == '1' ||
				kub->map[i][j] == '0')
				continue ;
			else if (kub->map[i][j] == 'N' || kub->map[i][j] == 'S' ||
				kub->map[i][j] == 'E' || kub->map[i][j] == 'W')
			{
				if (kub->player_x != -1.0)
					return (1);
				kub->player_x = j + 0.5;
				kub->player_y = i + 0.5;
			}
			else
				return (1);
		}
	}
	return (0);
}

void	replace_spaces(t_kub *kub)
{
	int	i;

	i = -1;
	while (++i < kub->map_width)
	{
		if (kub->map[0][i] == ' ')
			kub->map[0][i] = '1';
		if (kub->map[kub->map_height - 1][i] == ' ')
			kub->map[kub->map_height - 1][i] = '1';
	}
	i = -1;
	while (kub->map[++i])
	{
		if (kub->map[i][0] == ' ')
			kub->map[i][0] = '1';
		if (kub->map[i][kub->map_width - 1] == ' ')
			kub->map[i][kub->map_width - 1] = '1';
	}
}

// Remplir avec les espaces
void	fill_lines(t_kub *kub)
{
	char	*str;
	int		i;

	kub->map_width = (int)get_longest_line(kub->map, ft_strarr_size(kub->map));
	i = -1;
	while (++i < ft_strarr_size(kub->map))
	{
		if ((int)ft_strlen(kub->map[i]) < kub->map_width || \
			ft_count_char(kub->map[i], " "))
		{
			str = ft_calloc(kub->map_width + 1, sizeof(char));
			ft_memset(str, ' ', kub->map_width);
			ft_memcpy(str, kub->map[i], ft_strlen(kub->map[i]));
			free (kub->map[i]);
			kub->map[i] = ft_strdup(str);
			free (str);
		}	
	}
}
