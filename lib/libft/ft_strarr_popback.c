/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_popback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:11:16 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/03 13:25:24 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_popback(char **arr)
{
	int		size;
	int		i;
	char	**dup;

	i = -1;
	if (arr == NULL || arr[0] == NULL)
		return (arr);
	size = ft_strarr_size(arr);
	dup = ft_calloc(size, sizeof(char *));
	while (++i < size - 1)
		dup[i] = ft_strdup(arr[i]);
	ft_strarr_free(arr);
	return (dup);
}
