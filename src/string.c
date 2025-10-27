/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:04:55 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/24 15:05:51 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *a, const char *b)
{
	size_t	i;

	if (!a || !b)
		return (a != b);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		++i;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}
