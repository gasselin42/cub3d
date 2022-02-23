/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:28:44 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 14:53:03 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

void	init_tmp_map(t_cub *cub)
{
	int	i;
	int	j;
	
	i = 0;
	while (i++ < 1024)
	{
		j = 0;
		while (j++ < 1024)
			cub->tmp_map[i][j] = '\0';
	}
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
	init_tmp_map(cub);
	ft_memcpy(cub->tmp_map[0], line, ft_strlen(line));
	while (true)
	{
		ret = get_next_line(cub->fd, &str);
		split = ft_split(str, ' ');
		if (!str[0] || !split[0])
			break;
		ft_memcpy(cub->tmp_map[i++], str, ft_strlen(str));
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