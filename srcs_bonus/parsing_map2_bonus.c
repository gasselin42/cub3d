/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:33:27 by gasselin          #+#    #+#             */
/*   Updated: 2022/06/06 14:23:47 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

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

// Remplir avec les espaces
void	fill_lines(t_kub *kub)
{
	size_t	length;
	char	*str;
	int		i;

	length = get_longest_line(kub->map, ft_strarr_size(kub->map));
	kub->map_width = (int)length;
	i = -1;
	while (++i < ft_strarr_size(kub->map))
	{
		if (ft_strlen(kub->map[i]) < length)
		{
			str = ft_calloc(length + 1, sizeof(char));
			ft_memset(str, ' ', length);
			ft_memcpy(str, kub->map[i], ft_strlen(kub->map[i]));
			free (kub->map[i]);
			kub->map[i] = ft_strdup(str);
			free (str);
		}	
	}
}
