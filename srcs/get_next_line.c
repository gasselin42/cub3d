/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:22:59 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 11:06:14 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

int	get_next_line(int fd, char **line)
{
	char*	buf;
	char	c;
	int		ret;
	char*	tmp;

	buf = malloc(1 * sizeof(char));
	buf[0] = '\0';
	while (true)
	{
		ret = read(fd, &c, 1);
		if (ret == 0 || c == '\n')
			break ;
		tmp = ft_calloc((ft_strlen(buf) + 2), sizeof(char));
		ft_memcpy(tmp, buf, ft_strlen(buf));
		tmp[ft_strlen(buf)] = c;
		free (buf);
		buf = ft_strdup(tmp);
		free (tmp);
	}
	*line = ft_strdup(buf);
	free (buf);
	return (ret);
}
