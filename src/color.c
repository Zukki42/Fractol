/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:57:53 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/24 15:05:29 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

/* interpolate between two colors */
static unsigned int	blend(unsigned int c1, unsigned int c2, double t)
{
	int	r;
	int	g;
	int	b;

	r = ((int)((1 - t) * ((c1 >> 16) & 255) + t * ((c2 >> 16) & 255))) & 255;
	g = ((int)((1 - t) * ((c1 >> 8) & 255) + t * ((c2 >> 8) & 255))) & 255;
	b = ((int)((1 - t) * (c1 & 255) + t * (c2 & 255))) & 255;
	return ((r << 16) | (g << 8) | b);
}

/* dark forest palette with smooth transition */
unsigned int	color_smooth(int iter, int max_iter, double x, double y)
{
	double			t;
	unsigned int	col1;
	unsigned int	col2;
	unsigned int	col3;

	(void)x;
	(void)y;
	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / (double)max_iter;
	col1 = 0x1A1F14;
	col2 = 0x4B5635;
	col3 = 0x7B6D54;
	if (t < 0.5)
		return (blend(col1, col2, t * 2));
	return (blend(col2, col3, (t - 0.5) * 2));
}
