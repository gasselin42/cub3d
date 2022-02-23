/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:42:01 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 11:54:03 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../mlx_mac/mlx.h"
# include "../libft/libft.h"

# define WINH 1000
# define WINW 1000

# define North 0
# define South 1
# define East 2
# define West 3

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_text {
	void	*img;
	int		height;
	int		width;
}	t_text;

typedef struct s_cub {
	void	*mlx;
	void	*win;

	char	*textN;
	char	*textS;
	char	*textE;
	char	*textW;

	int		floor;
	int		ceiling;

	t_text	text[4];
	t_img	*img[2];

	char	**map;
}	t_cub;

void	start_parsing(t_cub *cub, char *path);

int		get_next_line(int fd, char **line);

#endif