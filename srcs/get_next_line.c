/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:22:59 by gasselin          #+#    #+#             */
/*   Updated: 2022/06/05 16:47:13 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	c;
	char	*tmp;
	char	*buf;

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
