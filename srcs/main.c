/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:41:16 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 11:09:22 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	char *line;
	int ret;
	if (argc >= 2)
		return (printf("Error : too many arguments!\n"));
	int fd = open("./map.cub", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		printf("%s\n", line);
		if (ret == 0)
			break;
	}
	return (0);
}
