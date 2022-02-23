/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:28:44 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 16:43:21 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

int	find_longest_line(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) > (size_t)len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

void	fill_lines(t_cub *cub, int len)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = ft_strlen(cub->map[i]);
		while (j < len)
		{
			cub->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	transfer_map(t_cub *cub)
{
	int len;
	int	i;
	int	j;

	i = 0;
	len = find_longest_line(cub->tmp_map);
	cub->map = ft_calloc(ft_strarr_size(cub->tmp_map) + 1, sizeof(char*));
	while (i < ft_strarr_size(cub->tmp_map))
	{
		j = 0;
		cub->map[i] = ft_calloc(len + 1, sizeof(char));
		while (cub->tmp_map[i][j])
		{
			cub->map[i][j] = cub->tmp_map[i][j];
			j++;
		}
		i++;
	}
	fill_lines(cub, len);
}

int	check_remaining_lines(t_cub *cub)
{
	int		ret;
	char	**split;
	char	*str;

	while (true)
	{
		ret = get_next_line(cub->fd, &str);
		split = ft_split(str, ' ');
		free (str);
		if (split[0])
		{
			ft_strarr_free(split);
			return (printf("Error : Map must be last in file\n"));
		}
		ft_strarr_free(split);
		if (ret == 0)
			break;
	}
	return (0);
}

int	fill_map(t_cub *cub, char *line)
{
	int		ret;
	char	*str;
	int		i;
	char	**split;

	i = 1;
	cub->tmp_map = ft_strarr_addback(cub->tmp_map, ft_strdup(line));
	while (true)
	{
		ret = get_next_line(cub->fd, &str);
		split = ft_split(str, ' ');
		if (!str[0] || !split[0])
			break;
		cub->tmp_map = ft_strarr_addback(cub->tmp_map, ft_strdup(str));
		if (ret == 0)
			break;
		ft_strarr_free(split);
		free (str);
	}
	ft_strarr_free(split);
	free (str);
	if (ret != 0)
		return (check_remaining_lines(cub));
	return (0);
}
