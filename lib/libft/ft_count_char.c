/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:25:07 by olabrecq          #+#    #+#             */
/*   Updated: 2022/05/16 10:26:27 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Gasselin
// count nb of caractere in set inside str
int	ft_count_char(const char *s, const char *set)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	if (!s || !set)
		return (0);
	while (s[i])
	{
		j = 0;
		while (set[j])
			if (s[i] == set[j++])
				count++;
		i++;
	}
	return (count);
}
